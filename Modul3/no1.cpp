#include <iostream>
#include <string>

using namespace std;

struct Data {
  string nama;
  string nim;
};

struct Node {
  Data data;
  Node* next;
};

Node* head;
Node* tail;

void inisialisasi() {
  head = NULL;
  tail = NULL;
}

void input(Data new_data) {
  Node* entry = new Node();
  entry->data = new_data;
  entry->next = NULL;
  if (head == NULL) {
    head = entry;
    tail = head;
  } else {
    entry->next = head;
    head = entry;
  }
}

void hapus() {
  Data data;
  Node* del;
  if (head == NULL) {
    cout << "\nlinked list kosong, penghapusan tidak bisa dilakukan" << endl;
  } else {
    data = head->data;
    cout << "\nData yang dihapus adalah ";
    cout << data.nama << "/" << data.nim << endl;

    del = head;
    head = head->next;
    delete del;
  }
}

void cetak() {
  Node* curr;
  curr = head;
  if (head == NULL)
    cout << "\ntidak ada data dalam linked list" << endl;
  else {
    cout << "\nData yang ada dalam linked list : \n" << endl;
    cout << "\t";
    while (curr != NULL) {
      cout << curr->data.nama << "/" << curr->data.nim;
      cout << " -> ";
      curr = curr->next;
    }
    cout << "NULL";
    cout << endl;
  }
}

void menu() {
  char pilih, ulang;
  Data data;

  do {
    system("cls");
    cout << "\n \n";
    cout << "SINGLE LINKED LIST NON CIRCULAR" << endl;
    cout << "-------------------------------" << endl;
    cout << "Menu : " << endl;
    cout << "1. Input data " << endl;
    cout << "2. Hapus data " << endl;
    cout << "3. Cetak Data" << endl;
    cout << "4. Exit" << endl;
    cout << "Masukkan pilihan Anda : ";
    cin >> pilih;
    cin.ignore();
    switch (pilih) {
      case '1':
        cout << "\nMasukkan nama  : ";
        getline(cin, data.nama);
        cout << "Masukkan NIM   : ";
        getline(cin, data.nim);
        input(data);
        break;
      case '2':
        hapus();
        break;
      case '3':
        cetak();
        break;
      case '4':
        exit(0);
        break;
      default:
        cout << "\nPilih ulang" << endl;
    }
    cout << "\nKembali ke menu?(y/n)";
    cin >> ulang;
  } while (ulang == 'y' || ulang == 'Y');
}

int main() {
  inisialisasi();
  menu();

  return EXIT_SUCCESS;
}
