#include <iostream>
using namespace std;

// Struktur untuk node dalam linked list
struct Node {
    string nama;
    string nim;
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
    void tambahDepan(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
        cout << "Data telah ditambahkan" << endl;
    }

    // Fungsi untuk menambahkan data ke belakang linked list
    void tambahBelakang(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
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
        cout << "Data telah ditambahkan" << endl;
    }

    // Fungsi untuk menambahkan data di tengah linked list
    void tambahTengah(string nama, string nim, int posisi) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;

        if (posisi == 1) {
            tambahDepan(nama, nim);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < posisi - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Posisi diluar jangkauan" << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Data telah ditambahkan" << endl;
    }

    // Fungsi untuk mengubah data di depan linked list
    void ubahDepan(string namaBaru, string nimBaru) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        head->nama = namaBaru;
        head->nim = nimBaru;
        cout << "Data telah diubah" << endl;
    }

    // Fungsi untuk mengubah data di belakang linked list
    void ubahBelakang(string namaBaru, string nimBaru) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data telah diubah" << endl;
    }

    // Fungsi untuk mengubah data di tengah linked list berdasarkan posisi
    void ubahTengah(string namaBaru, string nimBaru, int posisi) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* temp = head;
        int counter = 1;
        while (temp != nullptr && counter != posisi) {
            temp = temp->next;
            counter++;
        }

        if (temp == nullptr) {
            cout << "Posisi diluar jangkauan" << endl;
            return;
        }

        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data telah diubah" << endl;
    }

    // Fungsi untuk menghapus data dari depan linked list
    void hapusDepan() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus" << endl;
    }

    // Fungsi untuk menghapus data dari belakang linked list
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Data berhasil dihapus" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Data berhasil dihapus" << endl;
    }

    // Fungsi untuk menghapus data di tengah linked list berdasarkan posisi
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        if (posisi == 1) {
            hapusDepan();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        int counter = 1;
        while (temp != nullptr && counter != posisi) {
            prev = temp;
            temp = temp->next;
            counter++;
        }

        if (temp == nullptr) {
            cout << "Posisi diluar jangkauan" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Data berhasil dihapus" << endl;
    }

    // Fungsi untuk menampilkan seluruh data dalam linked list
    void tampilkanData() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus seluruh data dalam linked list
    void hapusList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Seluruh data telah dihapus" << endl;
    }
};

int main() {
    LinkedList linkedList;
    int choice;
    string nama, nim;
    int posisi;

    do {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "- Tambah Depan" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                linkedList.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "- Tambah Belakang" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                linkedList.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "- Tambah Tengah" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.tambahTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "- Ubah Depan" << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                linkedList.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "- Ubah Belakang" << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                linkedList.ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "- Ubah Tengah" << endl;
                cout << "Masukkan Nama Baru : ";
                cin >> nama;
                cout << "Masukkan NIM Baru : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                cout << "- Hapus Depan" << endl;
                linkedList.hapusDepan();
                break;
            case 8:
                cout << "- Hapus Belakang" << endl;
                linkedList.hapusBelakang();
                break;
            case 9:
                cout << "- Hapus Tengah" << endl;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                linkedList.hapusTengah(posisi);
                break;
            case 10:
                cout << "- Hapus List" << endl;
                linkedList.hapusList();
                break;
            case 11:
                cout << "- TAMPILKAN" << endl;
                linkedList.tampilkanData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 0);

    return 0;
}
