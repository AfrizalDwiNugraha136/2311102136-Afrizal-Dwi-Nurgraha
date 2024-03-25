#include <iostream>
using namespace std;

// Struktur untuk node dalam linked list
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Class untuk mengelola linked list
class LinkedList {
private:
    Node* head; // Pointer ke head dari linked list

public:
    // Constructor untuk menginisialisasi linked list
    LinkedList() : head(nullptr) {}

    // Fungsi untuk menambahkan data ke depan linked list
    void insertFront(string nama, int usia) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan data ke belakang linked list
    void insertBack(string nama, int usia) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menambahkan data di antara dua node
    void insertBetween(string nama, int usia, string prevNama, string nextNama) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;

        Node* temp = head;
        while (temp != nullptr && temp->nama != prevNama) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << prevNama << " tidak ditemukan." << endl;
            return;
        }

        Node* nextNode = temp->next;
        temp->next = newNode;
        newNode->next = nextNode;
    }

    // Fungsi untuk menghapus node dengan nama tertentu
    void remove(string nama) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        if (head->nama == nama) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr && current->nama != nama) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node " << nama << " tidak ditemukan." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    // Fungsi untuk mengubah data node dengan nama tertentu
    void edit(string nama, string newNama, int newUsia) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << nama << " tidak ditemukan." << endl;
            return;
        }

        temp->nama = newNama;
        temp->usia = newUsia;
    }

    // Fungsi untuk menampilkan seluruh data dalam linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", Usia: " << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    // a. Memasukkan data sesuai urutan yang diminta
    linkedList.insertFront("Hoshino", 18);
    linkedList.insertFront("Akechi", 20);
    linkedList.insertFront("Yusuke", 19);
    linkedList.insertFront("Michael", 18);
    linkedList.insertFront("Jane", 20);
    linkedList.insertFront("John", 19);

    // b. Menghapus data Akechi
    linkedList.remove("Akechi");

    // c. Menambahkan data Futaba di antara John dan Jane
    linkedList.insertBetween("Futaba", 18, "John", "Jane");

    // d. Menambahkan data Igor di awal
    linkedList.insertFront("Igor", 20);

    // e. Mengubah data Michael menjadi Reyn
    linkedList.edit("Michael", "Reyn", 18);

    // f. Menampilkan seluruh data
    cout << "Seluruh Data:\n";
    linkedList.display();

    return 0;
}
