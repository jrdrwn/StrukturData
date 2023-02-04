#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string email;
};

// Fungsi untuk membersihkan output sebelumnya
void clrscr() { system("cls"); }

// Fungsi untuk memasukkan data mahasiswa
void masukkanData(Mahasiswa mhs[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Masukkan data mahasiswa ke-" << i + 1 << ":" << endl;
    cout << "NIM: ";
    getline(cin, mhs[i].nim);
    cout << "Nama: ";
    getline(cin, mhs[i].nama);
    cout << "Email: ";
    getline(cin, mhs[i].email);
  }
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(Mahasiswa mhs[], int n) {
  cout << endl << "Data mahasiswa:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Mahasiswa ke-" << i + 1 << ":" << endl;
    cout << "NIM: " << mhs[i].nim << endl;
    cout << "Nama: " << mhs[i].nama << endl;
    cout << "Email: " << mhs[i].email << endl;
  }
}


int main() {
  clrscr();

  int n, pilihan;
  cout << "Masukkan jumlah mahasiswa: ";
  cin >> n;

  Mahasiswa mhs[n]; // Array Of Struct dengan jumlah elemen sebanyak n

  // Menu
  do {
    clrscr();
    cout << "Menu:" << endl;
    cout << "1. Masukkan data mahasiswa" << endl;
    cout << "2. Tampilkan data mahasiswa" << endl;
    cout << "3. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        // menghapus input sebelumnya agar tidak terjadi bug
        cin.ignore();
        masukkanData(mhs, n);
        // agar tidak langsung keluar sampai ada ENTER di tekan
        cin.get();
        break;
      case 2:
        cin.ignore();
        tampilkanData(mhs, n);
        cin.get();
        break;
      case 3:
        cin.ignore();
        cout << "Terima kasih!" << endl;
        cin.get();
        break;
      default:
        cin.ignore();
        cout << "Pilihan tidak valid!" << endl;
        cin.get();
    }
  } while (pilihan != 3);

  return 0;
}