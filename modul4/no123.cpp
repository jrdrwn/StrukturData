#include <conio.h>

#include <iostream>
using namespace std;
struct node {
  char data;
  node *kiri;
  node *kanan;
};
node *akar = NULL;

void addNode(node **akar, char isi) {
  if (*akar == NULL) {
    node *baru;
    baru = new node;
    baru->data = isi;
    baru->kiri = NULL;
    baru->kanan = NULL;
    *akar = baru;
  }
}
void preOrder(node *akar) {
  if (akar != NULL) {
    cout << " " << akar->data;
    preOrder(akar->kiri);
    preOrder(akar->kanan);
  }
}
void inOrder(node *akar) {
  if (akar != NULL) {
    inOrder(akar->kiri);
    cout << " " << akar->data;
    inOrder(akar->kanan);
  }
}
void postOrder(node *akar) {
  if (akar != NULL) {
    postOrder(akar->kiri);
    postOrder(akar->kanan);
    cout << " " << akar->data;
  }
}

int hitungNode(node *akar, int i = 0) {
  return (akar == NULL) ? 0
                        : 1 + hitungNode(akar->kiri) + hitungNode(akar->kanan);
}

void nilaiNodeMinimum(node *akar, char &minValue) {
  if (akar == NULL) {
    return;
  }
  if (akar->data < minValue) {
    minValue = akar->data;
  }
  nilaiNodeMinimum(akar->kiri, minValue);
  nilaiNodeMinimum(akar->kanan, minValue);
}

int main() {
  char abjad;
  cout << "\n\n\t Posisi Awal Tree : \n\n";
  cout << "\t A\n\t /\\\n\t B C\n\t /\n\t D\n\t /\\\n\t E F\n\n";

  addNode(&akar, abjad = 'A');
  addNode(&akar->kiri, abjad = 'B');
  addNode(&akar->kanan, abjad = 'C');
  addNode(&akar->kiri->kiri, abjad = 'D');
  addNode(&akar->kiri->kiri->kiri, abjad = 'E');
  addNode(&akar->kiri->kiri->kanan, abjad = 'F');
  cout << "Tampilan PreOrder :";
  preOrder(akar);
  cout << "\nTampilan InOrder :";
  inOrder(akar);
  cout << "\nTampilan PostOrder :";
  postOrder(akar);
  cout << "\nJumlah Node : " << hitungNode(akar);
  char nilaiMinimum = akar->data;
  nilaiNodeMinimum(akar, nilaiMinimum);
  cout << "\nNilai Node Minimum : " << nilaiMinimum;
}