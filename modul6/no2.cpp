#include <iostream>
#include <string>

using namespace std;

string padLeft(string str, int len) {
  string result = str;
  while (result.length() - str.length() < len) {
    result = " " + result;
  }
  return result;
}

void computeLPSArray(string pat, int M, int* lps);

void KMPSearch(string pat, string txt) {
  int M = pat.length();
  int N = txt.length();

  int lps[M];
  computeLPSArray(pat, M, lps);

  int i = 0, j = 0;
  while (i < N) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == M) {
      cout << padLeft(pat, (i - j)) << endl;
      //   cout << "Kata ditemukan pada indeks " << i - j << endl;
      j = lps[j - 1];
    } else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}

void computeLPSArray(string pat, int M, int* lps) {
  int len = 0;
  lps[0] = 0;
  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

int main() {
  string txt =
      "mimpimu memiliki akhir yang tidak terbatas, tarik napas yang dalam dan "
      "coba lagi";
  string pat1 = "mimpimu";
  string pat2 = "coba";

  cout << "Mencari kata 'mimpimu' dan 'coba' pada kalimat:\n" << txt << endl;
  KMPSearch(pat1, txt);
  KMPSearch(pat2, txt);

  return 0;
}
