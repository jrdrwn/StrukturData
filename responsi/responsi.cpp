#include <algorithm>
#include <iostream>
#include <random>
#include <string>

using namespace std;

struct Perpustakaan {
  string id, judul, pengarang, tahun, jumlah;
};

struct Node {
  Perpustakaan data;
  Node *next, *prev;
};

Node *head = NULL, *tail = NULL;

void tambahData(Node **head, Node **tail, Perpustakaan data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = newNode->prev = NULL;

  if (*head == NULL) {
    *head = *tail = newNode;
  } else {
    Node *curr = *head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    *tail = newNode;
  }
}

void tampilData(Node *head) {
  Node *curr = head;
  while (curr != NULL) {
    cout << "ID Buku: " << curr->data.id << endl;
    cout << "Judul Buku: " << curr->data.judul << endl;
    cout << "Pengarang: " << curr->data.pengarang << endl;
    cout << "Tahun Terbit: " << curr->data.tahun << endl;
    cout << "Jumlah Buku: " << curr->data.jumlah << endl;
    cout << endl;
    curr = curr->next;
  }
}

void hapusData(Node **head, string input) {
  Node *curr = *head;
  while (curr != NULL) {
    if (curr->data.judul == input || curr->data.pengarang == input ||
        curr->data.tahun == input || curr->data.jumlah == input ||
        curr->data.id == input) {
      if (curr->prev == NULL) {
        *head = curr->next;
        if (curr->next != NULL) {
          curr->next->prev = NULL;
        }
      } else if (curr->next == NULL) {
        curr->prev->next = NULL;
      } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
      }
      delete curr;
      break;
    }
    curr = curr->next;
  }
}

void updateData(Node *head, string id, Perpustakaan data) {
  Node *curr = head;
  while (curr != NULL) {
    if (curr->data.id == id) {
      curr->data = data;
      break;
    }
    curr = curr->next;
  }
}

void cariData(Node *head, string pola) {
  Node *curr = head;
  while (curr != NULL) {
    if (curr->data.judul.find(pola) != string::npos ||
        curr->data.pengarang.find(pola) != string::npos ||
        curr->data.tahun.find(pola) != string::npos ||
        curr->data.jumlah.find(pola) != string::npos ||
        curr->data.id.find(pola) != string::npos) {
      tampilData(curr);
    }
    curr = curr->next;
  }
}

Node *clone(Node *head) {
  Node *curr = head;
  Node *newHead = NULL, *newTail = NULL;
  while (curr != NULL) {
    tambahData(&newHead, &newTail, curr->data);
    curr = curr->next;
  }
  return newHead;
}

void urutData(Node *head) {
  if (head == NULL) return;
  int jarak = 1;
  bool sudah = true;
  while (jarak <= head->data.id.length() / 3) {
    jarak = jarak * 3 + 1;
  }
  while (jarak > 0) {
    sudah = true;
    Node *curr = head;
    while (curr->next != NULL) {
      if (curr->data.id.compare(curr->next->data.id) > 0) {
        Perpustakaan temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;
        sudah = false;
      }
      curr = curr->next;
    }
    if (sudah) {
      jarak = jarak / 3;
    }
  }
}

string random_string() {
  string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

  random_device rd;
  mt19937 generator(rd());
  shuffle(str.begin(), str.end(), generator);

  return str.substr(0, 5);
}

void isiData(Perpustakaan &data) {
  cout << "Masukkan Judul Buku : ";
  getline(cin, data.judul);
  cout << "Masukkan Pengarang Buku : ";
  getline(cin, data.pengarang);
  cout << "Masukkan Tahun Terbit Buku : ";
  getline(cin, data.tahun);
  cout << "Masukkan Jumlah Buku : ";
  getline(cin, data.jumlah);
}

int main() {
  do {
    cout << "=====================================" << endl;
    cout << "| 1. Tambah Data Buku               |" << endl;
    cout << "| 2. Tampilkan Data Buku            |" << endl;
    cout << "| 3. Hapus Data Buku                |" << endl;
    cout << "| 4. Update Data Buku               |" << endl;
    cout << "| 5. Cari Data Buku                 |" << endl;
    cout << "| 6. Urutkan Data Buku              |" << endl;
    cout << "| 7. Keluar                         |" << endl;
    cout << "=====================================" << endl;
    cout << "Masukkan Pilihan Anda : ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();
    switch (pilihan) {
      case 1: {
        Perpustakaan data;
        isiData(data);
        data.id = random_string();
        tambahData(&head, &tail, data);
        break;
      }
      case 2:
        tampilData(head);
        break;
      case 3: {
        string input;
        cout << "Masukkan ID Buku : ";
        getline(cin, input);
        hapusData(&head, input);
        break;
      }
      case 4: {
        string id;
        Perpustakaan data;
        cout << "Masukkan ID Buku : ";
        getline(cin, id);
        isiData(data);
        updateData(head, id, data);
        break;
      }
      case 5: {
        string input;
        cout << "Masukkan Pencarian : ";
        getline(cin, input);
        cariData(head, input);
        break;
      }
      case 6: {
        Node *newHead = clone(head);
        cout << "Data Setelah Diurutkan" << endl;
        urutData(newHead);
        tampilData(newHead);
        break;
      }
      case 7:
        cout << "Terima Kasih" << endl;
        exit(0);
        break;
      default:
        cout << "Pilihan tidak ada" << endl;
    }
  } while (true);
}
