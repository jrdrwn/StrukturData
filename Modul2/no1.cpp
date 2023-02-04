#include <iostream>
#include <string>

using namespace std;

#define MAX 10

struct Music {
    string title, artist;
} music;

struct Stack {
    Music musics[MAX];
    int top, bottom;
} stack;

struct Queue {
    Music musics[MAX];
    int front, rear, count;
} queue;


void readable(Music *m) {
  cout << "Judul Lagu: " << m->title << endl;
  cout << "Nama Penyanyi: " << m->artist << endl;
}

void enqueue(Queue *q, Music m) {
  q->musics[q->rear] = m;
  q->rear++;
  q->count++;
}

void push(Stack *s, Music m) {
  s->musics[s->top] = m;
  s->top++;
}

void dequeue(Queue *q, Music *m) {
  m = &q->musics[q->front];
  for (int i = q->front; i < q->rear; ++i) {
    q->musics[i] = q->musics[i + 1];
  }
  q->rear--;
  q->count--;
}

void pop(Stack *s, Music *m) {
  m = &s->musics[s->top - 1];
  s->top--;
}

void input(Queue *q, Stack *s, Music *m) {
  cout << "Data lagu ke-" << q->count + 1 << " dari " << MAX << " lagu." << endl;
  cout << "Judul Lagu: ";
  getline(cin, m->title);
  cout << "Nama Penyanyi: ";
  getline(cin, m->artist);
  enqueue(q, *m);
  push(s, *m);
}

void clear(Queue *q, Stack *s, Music *m) {
  while (s->top) { pop(s, m); }
  while (q->count) { dequeue(q, m); }
  cout << "Data musik berhasil dihapus\n";
}

void print(Queue *q, Stack *s, Music *m) {
  cout << "Data di dalam Queue: " << endl;
  for (int i = 0; i < q->count; ++i) {
    m = &q->musics[i];
    readable(m);
  }
  cout << "===================" << endl;
  cout << "Data di dalam Stack: " << endl;
  for (int i = 0; i < s->top; ++i) {
    m = &s->musics[i];
    readable(m);
  }
}

int main() {
  int n;
  do {
    system("cls");
    cout << "Menu:" << endl;
    cout << "1. Input data musik" << endl;
    cout << "2. Ambil data musik (FIFO)" << endl;
    cout << "3. Ambil data musik (LIFO)" << endl;
    cout << "4. Hapus data musik" << endl;
    cout << "5. Tampilkan data musik" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> n;
    system("cls");

    cin.ignore();
    switch (n) {
      case 1:
        input(&queue, &stack, &music);
        break;
      case 2:
        cout << "Mengambil Lagu Secara FIFO." << endl;
        dequeue(&queue, &music);
        readable(&music);
        break;
      case 3:
        cout << "Mengambil Lagu Secara LIFO." << endl;
        pop(&stack, &music);
        readable(&music);
        break;
      case 4:
        clear(&queue, &stack, &music);
        break;
      case 5:
        print(&queue, &stack, &music);
        break;
      case 6:
        cout << "Terima kasih!" << endl;
        break;
      default:
        cout << "Input tidak valid!" << endl;
    }
    cout << endl << "Tekan ENTER untuk lanjut!" << endl;
    cin.get();

  } while (n != 6);
}