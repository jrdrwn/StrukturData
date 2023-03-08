#include <conio.h>

#include <iostream>
#include <string>

using namespace std;
struct Node {
  string data;
  Node *next;
  Node *prev;
};

Node *head = NULL;
Node *tail = NULL;
int option = 0;

void tambah_awal_list() {
  Node *baru;
  baru = new Node();
  cout << "Masukkan Data  : ";
  cin >> baru->data;
  baru->next = NULL;
  baru->prev = NULL;
  if (head == NULL) {
    head = baru;
    tail = baru;
  } else {
    baru->next = head;
    head->prev = baru;
    head = baru;
  }
}

void menambah_node_di_akhir() {
  Node *baru;  // Temporary pointers
  // menciptakan node baru
  baru = new Node();
  cout << "Masukkan Data     : ";
  cin >> baru->data;
  baru->next = NULL;

  // Set up link pada node
  if (head == NULL) {
    head = baru;
    tail = head;
  } else {
    tail->next = baru;
    baru->prev = tail;
    tail = baru;
  }
}

void Hapus_tengah_list() {
  int banyakdata, posisi_hapus, poshapus;
  Node *hapus, *bantu, *bantu2;
  if (head != NULL) {
    cout << " Dihapus pada data ke : ";
    cin >> posisi_hapus;
    banyakdata = 1;
    bantu = head;
    while (bantu->next != NULL) {
      bantu = bantu->next;
      banyakdata++;
    }
    if ((posisi_hapus < 1) || (posisi_hapus > banyakdata)) {
      cout << "Belum ada data !!\n";
    } else {
      bantu = head;
      poshapus = 1;
      while (poshapus < (posisi_hapus - 1)) {
        bantu = bantu->next;
        poshapus++;
      }
      hapus = bantu->next;
      bantu2 = hapus->next;
      bantu->next = hapus->next;
      bantu2->prev = bantu;
      delete hapus;
    }
  } else {
    cout << "Data Masih kosong, tidak bisa hapus data dari tengah! ";
  }

  getch();
}

void display_list() {
  Node *temp;
  temp = head;
  cout << endl;
  cout << " Data yang dimasukan = ";
  if (temp == NULL)
    cout << "List kosong!" << endl;
  else {
    while (temp != NULL) {  // Menampilkan detail data

      cout << "" << temp->data << ",";

      if (temp == tail) cout << " ";
      temp = temp->next;
    }
  }
  getch();
}

main() {
  int option;
  do {
    system("cls");
    cout << "      MENU UTAMA  :    " << endl;
    cout << "_______________________" << endl;
    cout << " 1. Tambah awal list   " << endl;
    cout << " 2. Tambah akhir list  " << endl;
    cout << " 3. Hapus tengah list  " << endl;
    cout << " 4. Cetak Data         " << endl;
    cout << " 5. Keluar             " << endl;
    cout << endl << " Pilihan : ";
    cin >> option;

    switch (option) {
      case 1:
        system("cls");
        tambah_awal_list();
        break;
      case 2:
        system("cls");
        menambah_node_di_akhir();
        break;
      case 3:
        system("cls");
        Hapus_tengah_list();
        break;
      case 4:
        display_list();
        getch();
        break;
    }
  } while (option != 5);
  return 5;
}
