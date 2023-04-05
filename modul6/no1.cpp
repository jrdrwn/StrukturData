#include <algorithm>
#include <iostream>

using namespace std;

int sequential_search(int data[], int n, int target) {
  for (int i = 0; i < n; i++) {
    if (data[i] == target) {
      return i;
    }
  }
  return -1;
}

int binary_search(int data[], int n, int target) {
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (data[mid] == target) {
      return mid;
    } else if (data[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cout << "Masukkan Jumlah Data: ";
  cin >> n;
  int data[n];
  for (int i = 0; i < n; i++) {
    cout << "Masukkan Data ke-" << i + 1 << ": ";
    cin >> data[i];
  }

  sort(data, data + n);

  int target, choice;

  do {
    cout << "Data: ";
    for (int i = 0; i < n; i++) {
      cout << data[i] << " ";
    }
    cout << "\nPilih Metode Pencarian:" << endl;
    cout << "1. Sequential Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Pilihan: ";
    cin >> choice;
    cout << "Masukkan ID Pelanggan: ";
    cin >> target;
    switch (choice) {
      case 1: {
        int result_sequential = sequential_search(data, n, target);
        if (result_sequential == -1) {
          cout << "Metode Sequential Search: Data Tidak Ditemukan!" << endl;
        } else {
          cout << "Metode Sequential Search: Data Ditemukan pada indeks ke-"
               << result_sequential << endl;
        }
        break;
      }
      case 2: {
        int result_binary = binary_search(data, n, target);
        if (result_binary == -1) {
          cout << "Metode Binary Search: Data Tidak Ditemukan!" << endl;
        } else {
          cout << "Metode Binary Search: Data Ditemukan pada indeks ke-"
               << result_binary << endl;
        }
        break;
      }
      default:
        cout << "Pilihan Salah!" << endl;
    }
  } while (true);

  return 0;
}
