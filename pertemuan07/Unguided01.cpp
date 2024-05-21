#include <iostream>
using namespace std;

// Mendefinisikan node untuk linked list
struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front; // Pointer ke depan antrian
    Node* rear;  // Pointer ke belakang antrian
    int size;    // Ukuran antrian

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Fungsi untuk menambahkan elemen ke belakang antrian
    void enqueueAntrian(string data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        
        // Jika antrian kosong
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Fungsi untuk menghapus elemen dari depan antrian
    void dequeueAntrian() {
        // Jika antrian kosong
        if (front == nullptr) {
            cout << "Antrian kosong" << endl;
            return;
        }
        
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    // Fungsi untuk menampilkan seluruh elemen antrian
    void viewQueue() {
        if (front == nullptr) {
            cout << "Antrian kosong" << endl;
            return;
        }
        
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Fungsi untuk menghitung jumlah elemen dalam antrian
    int countQueue() {
        return size;
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clearQueue() {
        while (front != nullptr) {
            dequeueAntrian();
        }
    }

    // Destruktor untuk menghapus seluruh elemen pada akhir program
    ~Queue() {
        clearQueue();
    }
};

int main() {
    Queue antrian;
    antrian.enqueueAntrian("Andi");
    antrian.enqueueAntrian("Maya");
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.dequeueAntrian();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.clearQueue();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    return 0;
}
