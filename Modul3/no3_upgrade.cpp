#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *prev;
  Node *next;
};

Node *head, *tail, *new_node, *curr;

void insert(int data) {
  new_node = new Node({data, NULL, NULL});
  if (head == NULL) {
    head = tail = new_node;
  } else {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
}

void insert_back(int data) {
  new_node = new Node({data, NULL, NULL});
  if (head == NULL) {
    head = tail = new_node;
  } else {
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
  }
}

void del() {
  if (head == NULL) {
    cout << "Double Linked List Masih Kosong!" << endl;
  } else {
    curr = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    cout << "Data \"" << curr->data << "\" Dihapus Dari Depan." << endl;
  }
}

void del_back() {
  if (head == NULL) {
    cout << "Double Linked List Masih Kosong!" << endl;
  } else {
    curr = tail;
    tail = tail->prev;
    if (tail != NULL) tail->next = NULL;
    cout << "Data \"" << curr->data << "\" Dihapus Dari Belakang." << endl;
  }
}

int count() {
  int i = 0;
  curr = head;
  while (curr != NULL) {
    i++;
    curr = curr->next;
  }
  return i;
}

void del_mid(int n) {
  if (head == NULL) {
    cout << "Double Linked List Masih Kosong!" << endl;
  } else {
    if (n == 0 || n >= count() - 1) {
      cout << "Posisi Tidak Di Tengah!" << endl;
    } else {
      curr = head;
      for (int i = 0; i < n && curr != NULL; i++) {
        curr = curr->next;
      }

      if (curr == NULL) {
        cout << "Posisi Salah!" << endl;
        return;
      }

      curr->prev->next = curr->next;
      if (curr->next != NULL) curr->next->prev = curr->prev;
      delete curr;

      cout << "Data \"" << curr->data << "\" Dihapus Dari Tengah Di Posisi "
           << n << endl;
    }
  }
}

void print() {
  cout << "Data Double Linked List: ";
  if (count() == 0) cout << "Belum Ada!";

  curr = head;
  while (curr != NULL) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  int n;
  do {
    cout << "1. Tambah Data dari depan" << endl;
    cout << "2. Tambah Data dari Belakang" << endl;
    cout << "3. Hapus Data terdepan" << endl;
    cout << "4. Hapus Data terbelakang" << endl;
    cout << "5. Hapus Data tengah" << endl;
    cout << "6. Cetak" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> n;
    switch (n) {
      case 1:
        cout << "Masukkan Data Angka : ";
        cin >> n;
        insert(n);
        break;
      case 2:
        cout << "Masukkan Data Angka : ";
        cin >> n;
        insert_back(n);
        break;
      case 3:
        del();
        break;
      case 4:
        del_back();
        break;
      case 5:
        cout << "Masukkan Posisi : ";
        cin >> n;
        del_mid(n);
        break;
      case 6:
        print();
        break;
      case 7:
        cout << "Terima Kasih!" << endl;
        exit(0);
        break;
      default:
        break;
    }
  } while (true);
}