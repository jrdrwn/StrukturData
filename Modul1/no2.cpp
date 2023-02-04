#include <iostream>

#define max 50

using namespace std;

int *fibo(int n, int arr[]) {
  arr[0] = 1;
  arr[1] = 1;
  for (int i = 2; i < n; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  // ada warning disini karena fungsi mengembalikan memory
  // sedangkan yg ini mengembalikan array
  // solusinya, letakkan variabel ini ke global
  // atau jadikan parameter
  return arr;
}

int main() {
  int num, *ptr, arr[max];;
  cout << "jumlah bilangan fibonacci : ";
  cin >> num;
  ptr = fibo(num, arr);
  for (int i = 0; i < num; i++) {
    // letakkan asterik untuk mendapankan nilai
    cout << *(ptr + i) << " ";
  }
}