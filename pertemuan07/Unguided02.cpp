#include <iostream>
using namespace std;

// Struktur Node untuk menyimpan data Mahasiswa dan pointer ke node selanjutnya
struct MahasiswaNode {
    string nama_136;
    string nim_136;
    MahasiswaNode* next;
};

// Kelas Queue menggunakan linked list untuk Mahasiswa
class MahasiswaQueue {
private:
    MahasiswaNode* front; // Node pertama dalam queue
    MahasiswaNode* back;  // Node terakhir dalam queue
public:
    MahasiswaQueue() {
        front = nullptr;
        back = nullptr;
    }

    // Fungsi untuk mengecek apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Fungsi untuk menambahkan data Mahasiswa ke dalam queue
    void enqueue(string nama_136, string nim_136) {
        MahasiswaNode* newNode = new MahasiswaNode(); // Membuat node baru
        newNode->nama_136 = nama_136;
        newNode->nim_136 = nim_136;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    // Fungsi untuk menghapus data Mahasiswa dari queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        MahasiswaNode* temp = front;
        front = front->next;
        delete temp;
    }

    // Fungsi untuk melihat data Mahasiswa yang ada di queue
    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "Data antrian mahasiswa:" << endl;
        MahasiswaNode* current = front;
        int position = 1;
        while (current != nullptr) {
            cout << position << ". Nama: " << current->nama_136 << ", NIM: " << current->nim_136 << endl;
            current = current->next;
            position++;
        }
    }

    // Fungsi untuk menghitung jumlah data Mahasiswa di queue
    int countQueue() {
        int count = 0;
        MahasiswaNode* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk membersihkan queue
    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    MahasiswaQueue queue; // Membuat objek queue

    char tambahLagi;
    do {
        string nama, nim;
        cout << "Masukkan nama mahasiswa: ";
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa: ";
        getline(cin, nim);
        queue.enqueue(nama, nim);

        cout << "Apakah ingin menambahkan mahasiswa lagi? (y/n): ";
        cin >> tambahLagi;
        cin.ignore(); // Untuk membersihkan newline di buffer stdin
    } while (tambahLagi == 'y' || tambahLagi == 'Y');

    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
