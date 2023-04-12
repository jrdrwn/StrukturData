#include <iostream>
#include <string>

using namespace std;

struct Data {
  string nim, nama;
};

struct Node {
  Data data;
  Node* next;
};

Node *head, *curr;

void input(Data new_data) {
  Node* entry = new Node();
  entry->data = new_data;
  entry->next = NULL;
  if (head == NULL) {
    head = entry;
  } else {
    entry->next = head;
    head = entry;
  }
}

void cetak(Node* head) {
  curr = head;
  if (head == NULL)
    cout << "\nTidak ada data dalam linked list" << endl;
  else {
    cout << "\nData yang ada dalam linked list : \n" << endl;
    int i = 1;
    while (curr != NULL) {
      cout << "Data ke-" << i++ << endl;
      cout << "NIM : " << curr->data.nim << endl;
      cout << "Nama : " << curr->data.nama << endl;
      curr = curr->next;
    }
  }
}

void swap(Node* a, Node* b) {
  Data temp = a->data;
  a->data = b->data;
  b->data = temp;
}

Node* linkedlist_clone() {
  curr = head;
  Node* new_head = NULL;
  while (curr != NULL) {
    Node* new_node = new Node();
    new_node->data = curr->data;
    new_node->next = new_head;
    new_head = new_node;
    curr = curr->next;
  }
  return new_head;
}

void sort() {
  Node *i, *j, *head = linkedlist_clone();
  Data temp;

  for (i = head; i != NULL; i = i->next) {
    for (j = i->next; j != NULL; j = j->next) {
      if (i->data.nim > j->data.nim) {
        temp = i->data;
        i->data = j->data;
        j->data = temp;
      }
    }
  }
  cout << "\nData telah diurutkan (Ascending)" << endl;
  cetak(head);

  for (i = head; i != NULL; i = i->next) {
    for (j = i->next; j != NULL; j = j->next) {
      if (i->data.nim < j->data.nim) {
        temp = i->data;
        i->data = j->data;
        j->data = temp;
      }
    }
  }
  cout << "\nData telah diurutkan (Descending)" << endl;
  cetak(head);
}

void search(string pola) {
  curr = head;
  int i = 1;
  while (curr != NULL) {
    if (curr->data.nim.find(pola) != string::npos ||
        curr->data.nama.find(pola) != string::npos) {
      cout << "Data ke-" << i++ << endl;
      cout << "NIM : " << curr->data.nim << endl;
      cout << "Nama : " << curr->data.nama << endl;
    }
    curr = curr->next;
  }
}

int main() {
  char pilih, ulang;
  string pola;
  Data data;

  do {
    system("cls");
    cout << "Menu : " << endl;
    cout << "1. Input Data " << endl;
    cout << "2. Cetak Data" << endl;
    cout << "3. Sort Data" << endl;
    cout << "4. Search Data" << endl;
    cout << "5. Exit" << endl;
    cout << "Masukkan pilihan Anda : ";
    cin >> pilih;
    cin.ignore();
    switch (pilih) {
      case '1':
        cout << "Masukkan NIM   : ";
        getline(cin, data.nim);
        cout << "Masukkan nama  : ";
        getline(cin, data.nama);
        input(data);
        break;
      case '2':
        cetak(head);
        break;
      case '3':
        sort();
        break;
      case '4':
        cout << "Masukkan pola yang dicari : ";
        getline(cin, pola);
        search(pola);
        break;
      case '5':
        exit(0);
      default:
        cout << "\nPilih ulang" << endl;
    }
    cout << "\nKembali ke menu?(y/n) ";
    cin >> ulang;
  } while (ulang == 'y' || ulang == 'Y');
}
