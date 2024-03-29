# <h1 align="center">Laporan Praktikum Modul SINGLE AND DOUBLE LINKED LIST</h1>
# <p align="center">Afrizal Dwi Nugraha-2311102136 </p>

## Dasar Teori
Linked List dan Double Linked List adalah dua jenis struktur data yang digunakan untuk menyimpan dan mengelola elemen data dalam suatu program.

1. Linked List  : Linked List adalah  struktur data linier yang terbentuk secara dinamis.Elemen Linked List disimpan sebagai node, yang terdiri dari dua elemen anak: bagian data  menyimpan elemen, dan bagian berikutnya menyimpan link ke node berikutnya. Linked List terbentuk ketika  banyak node dihubungkan bersama dan membentuk sebuah rantai. Setiap node menunjuk ke node berikutnya secara berurutan. Node pertama  selalu digunakan sebagai referensi ketika melintasi daftar yang disebut HEAD, sedangkan node terakhir akan menunjuk ke NULL.

2. Double Linked List : Double Linked List adalah varian dari Linked List, menggunakan pointer berikutnya dan sebelumnya yang masing- masing menunjuk ke node berikutnya dan sebelumnya. Double Linked List dapat digunakan untuk berpindah dari node pertama ke node terakhir atau sebaliknya, yang lebih efisien daripada Linked List hanya dengan penunjuk berikutnya.

Double Linked List dapat digunakan untuk mengurutkan data, seperti yang telah dilakukan pada artikel “Menerapkan dan Menganalisis Penyortiran DDouble Linked List. Double Linked List juga dapat digunakan dalam sistem komunikasi, seperti halnya dalam artikel "Design of buffered double linked list for LEO satelit beam-hopping forwarding", yang menggunakan dDouble Linked List. kebijakan Double Linked List untuk transmisi data antara satelit dan pengguna dalam sistem beam-hopping LEO 

## Guided 

### 1.  Latihan Single Linked List

```C++

#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node {
    int data;
    Node* next;
};

Node* head;
Node* tail;

//Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}

//Tambah Depan
void insertDepan(int nilai) {
    //Buat Node baru
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
    }
}

//Tambah Belakang
void insertBelakang(int nilai) {
    //Buat Node baru
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        tail->next = baru;
        tail = baru;
    }
}

//Hitung Jumlah List
int hitungList() {
    Node* hitung;
    hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

//Tambah Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        Node* baru, * bantu;
        baru = new Node();
        baru->data = data;

        // tranversing
        bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan() {
    Node* hapus;

    if (isEmpty() == false) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang() {
    Node* hapus;
    Node* bantu;

    if (isEmpty() == false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi) {
    Node* hapus, * bantu, * bantu2;

    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }

            if (nomor == posisi) {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data) {
    if (isEmpty() == false) {
        head->data = data;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi) {
    Node* bantu;

    if (isEmpty() == false) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else {
            bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->data = data;
        }
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int data) {
    if (isEmpty() == false) {
        tail->data = data;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList() {
    Node* bantu, * hapus;
    bantu = head;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil() {
    Node* bantu;
    bantu = head;

    if (isEmpty() == false) {
        while (bantu != NULL) {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }

        cout << endl;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    return 0;
}
```
Program di atas adalah implementasi dari daftar non-lingkaran tertaut tunggal di C++.
Berikut  penjelasan singkat masing-masing fungsi dan cara kerja program: Struktur Node: Mendefinisikan struktur node yang memiliki dua properti, yaitu data sebagai nilai yang disimpan dan kemudian penunjuk ke node berikutnya.
 - init(): Inisialisasi head dan tail ke NULL.</br>
 - isEmpty(): Memeriksa apakah daftar tertaut kosong.</br>
 - isEmpty(): Memeriksa apakah daftar tertaut kosong.</br>
 - InsertFront(int value): Menambahkan node baru ke awal daftar tertaut.</br>
 - InsertBack(int value): Tambahkan node baru ke akhir daftar tertaut.</br>
 - HitungList(): Menghitung jumlah node dalam daftar tertaut.</br>
 - InsertMiddle(int data, int location): Menambahkan node baru ke tengah daftar tertaut pada posisi yang ditentukan.</br>
 - RemoveFront(): Menghapus node pertama dari daftar tertaut.</br>
 - deleteBack(): Menghapus node terakhir dari daftar tertaut.</br>
 - deleteMiddle(int location): Hapus node di tengah daftar link pada lokasi yang ditentukan.</br>
 - ChangeFront(int data): Mengubah nilai data pada node pertama dari daftar tertaut.</br>
 - ChangeMiddle(int data, int location): Mengubah nilai data pada node di tengah daftar tertaut di lokasi yang ditentukan.</br>
 - ChangeBack(int data): Mengubah nilai data pada node terakhir dari daftar tertaut.</br>
 - clearList(): Menghapus semua isi daftar tertaut.</br>
 - show(): Menampilkan konten daftar tertaut.</br>
<p> Program kemudian menguji fungsi-fungsi ini menggunakan berbagai operasi, seperti menambah, menghapus, dan mengubah data dalam daftar tertaut.<p>



### 2.Latihan Double Linked List

```C++

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }

        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void deleteAll() {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;

                bool updated = list.update(oldData, newData);

                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}
```
Kelas node: Mendefinisikan struktur node dengan tiga properti yaitu data sebagai nilai yang disimpan, yang pertama adalah penunjuk ke node sebelumnya,dan yang berikutnya adalah penunjuk ke node berikutnya.
- Kelas DoublyLinkedList: Mendefinisikan daftar tertaut ganda dengan dua penunjuk, yaitu kepala ke simpul pertama dan ekor ke simpul terakhir.</br>
- Kelas ini memiliki fungsi berikut: push(int data): Menambahkan data baru ke awal daftar tertaut.</br>
- pop(): Menghapus data dari awal daftar tertaut.</br>
- Pembaruan (int oldData, int newData): Mengganti nilai data yang  ada dengan nilai baru.</br>
- deleteAll(): Menghapus semua data dari daftar tertaut.</br>
- display(): Menampilkan konten daftar tertaut.</br>
- Fungsi utama: Dalam fungsi main(), program membuat objek dari kelas DoublyLinkedList dan kemudian menampilkan menu operasi yang dapat dilakukan pada daftar tertaut.</br>
<p> Pengguna diminta untuk memilih operasi yang diinginkan dan program akan melakukan operasi  sesuai dengan pilihan pengguna.<p>

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan Usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:</br> ㅤa. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.</br> ㅤb. Hapus data Akechi</br> ㅤc. Tambahkan data berikut diantara John dan Jane: "Futaba 18"</br> ㅤd. Tambahkan data berikut di awal: "Igor 20"</br> ㅤe. Ubah data Michael menjadi: "Reyn 18"</br> ㅤf. Tampilkan seluruh data

```C++

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
```

#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan03/Unguided%201%20Link.PNG?raw=true)

Program di atas merupakan implementasi dari daftar tertaut non-lingkaran di C++.
 Berikut  penjelasan singkat programnya:
1. Struktur Node: Mendefinisikan struktur node yang mempunyai dua properti yaitu name sebagai string untuk menyimpan nama dan age sebagai bilangan bulat untuk menyimpan umur. Selain itu, ada pointer berikutnya yang menunjuk ke node berikutnya dalam Linked List.
   
2. Class LinkedList: Mendefinisikan kelas untuk menangani daftar tertaut.
 - class ini mempunyai fungsi sebagai berikut: InsertFront(nama string, usia int): Menambahkan data ke awal Linked List.</br>
 - InsertBack(nama string, usia int): Tambahkan data ke akhir Linked List.</br>
 - InsertBetween(string name, int age, string prevName, string nextName): Menggabungkan data  antara dua node yang ditentukan dalam Linked List.</br>
 - Hapus (nama string): Menghapus node dengan nama tertentu dari Linked List.</br>
 - edit(string nama, string newName, int newAge): Edit data node dengan nama yang ditentukan.</br>
 - display(): Menampilkan semua data dalam Linked List.</br>

3. Fungsi utama: Dalam fungsi main(), program membuat objek  kelas LinkedList  kemudian melakukan operasi yang diperlukan dalam studi kasus.Setelah menyelesaikan operasi, semua data dalam daftar tertaut akan ditampilkan.
 Program ini memungkinkan pengguna untuk menyisipkan, menghapus, mengubah dan menampilkan data dalam daftar tertaut sesuai  kebutuhan. Implementasi ini menggunakan struktur data linked list untuk pengelolaan data yang sangat fleksibel dan efisien.



### 2. odifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama Produk dan Harga. </br>Case:</br> ㅤ1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific</br> ㅤ2. Hapus produk Wardah</br> ㅤ3. Update produk Hanasui menjadi Cleora dengan harga 55000</br> ㅤ4. Tampilkan menu, di mana tampilan akhirnya akan menjadi seperti dibawah ini: Toko Skincare Purwokerto 1. Tambah Data 2. Hapus Data 3. Update Data 3. Update Data 4. Tambah Data Urutan Tertentu 5. Hapus Data Urutan Tertentu 6. Hapus Seluruh Data 7. Tampilkan Data 8. Exit Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini : Nama Produk Harga Somethinc 150.000 Originote 60.000 Skintific 100.000 Cleora 55.000

```C++

#include <iostream>
using namespace std;

struct Node {
    string namaProduk;
    double harga;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Menambah data di awal
    void tambahData(string nama, double harga) {
        Node* newNode = new Node();
        newNode->namaProduk = nama;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;
        
        head = newNode;

        if (tail == NULL)
            tail = newNode;
    }

    // Menghapus data dengan nama tertentu
    void hapusData(string nama) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                if (current->prev != NULL)
                    current->prev->next = current->next;
                else
                    head = current->next;

                if (current->next != NULL)
                    current->next->prev = current->prev;
                else
                    tail = current->prev;

                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan" << endl;
    }

    // Update data dengan nama tertentu
    void updateData(string nama, string newNama, double newHarga) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                current->namaProduk = newNama;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan" << endl;
    }

    // Menambah data di urutan tertentu
    void tambahDataUrutanTertentu(string nama, double harga, string namaSetelah) {
        Node* newNode = new Node();
        newNode->namaProduk = nama;
        newNode->harga = harga;

        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaSetelah) {
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != NULL)
                    current->next->prev = newNode;
                else
                    tail = newNode;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk setelahnya tidak ditemukan" << endl;
    }

    // Menampilkan semua data
    void tampilkanData() {
        Node* current = head;
        cout << "Nama Produk\tHarga" << endl;
        while (current != NULL) {
            cout << current->namaProduk << "\t\t" << current->harga << endl;
            current = current->next;
        }
    }

    // Hapus semua data
    void hapusSeluruhData() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;
    }
};

int main() {
    DoubleLinkedList list;
    list.tambahData("Originote", 60000);
    list.tambahData("Somethinc", 150000);
    list.tambahData("Skintific", 100000);
    list.tambahData("Wardah", 50000);
    list.tambahData("Hanasui", 30000);

    int choice;
    string nama, newNama, namaSetelah;
    double harga, newHarga;

    do {
        cout << "\nToko Skincare Purwokerto\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Update Data\n";
        cout << "4. Tambah Data Urutan Tertentu\n";
        cout << "5. Hapus Seluruh Data\n";
        cout << "6. Tampilkan Data\n";
        cout << "7. Exit\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin >> nama;
                cout << "Masukkan harga produk: ";
                cin >> harga;
                list.tambahData(nama, harga);
                break;
            case 2:
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> nama;
                list.hapusData(nama);
                break;
            case 3:
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> nama;
                cout << "Masukkan nama baru: ";
                cin >> newNama;
                cout << "Masukkan harga baru: ";
                cin >> newHarga;
                list.updateData(nama, newNama, newHarga);
                break;
            case 4:
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> nama;
                cout << "Masukkan harga produk: ";
                cin >> harga;
                cout << "Masukkan nama produk setelahnya: ";
                cin >> namaSetelah;
                list.tambahDataUrutanTertentu(nama, harga, namaSetelah);
                break;
            case 5:
                list.hapusSeluruhData();
                cout << "Semua data telah dihapus." << endl;
                break;
            case 6:
                list.tampilkanData();
                break;
            case 7:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 7);

    return 0;
}

```
 #### Output:
 ![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan03/Unguided%202%20Link.PNG?raw=true)
 ![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan03/Unguided%202(1)%20Link.PNG?raw=true)
 
Program di atas adalah implementasi daftar tertaut ganda yang dimodifikasi untuk menambahkan operasi penambahan data dalam urutan tertentu, menghapus data, memperbarui data, menambahkan data  antara dua node tertentu, menghapus semua kedua data dan menampilkan semua data di toko  toko skincare.

Berikut  penjelasan singkat programnya: 
1. Struktur node: Mendefinisikan struktur node dengan dua properti, yaitu nama produk sebagai string untuk menyimpan nama produk dan harga sebagai ganda untuk Menyimpan harga produk.vSelain itu, ada dua pointer: prev  menunjuk ke node sebelumnya dan next  menunjuk ke node berikutnya dalam daftar tertaut.
   
2. Class DoubleLinkedList: Mendefinisikan kelas untuk menangani daftar LinkedList.
-Class ini mempunyai fungsi sebagai berikut: addData(nama string, harga ganda): Menambahkan data ke awal LinkedList.</br>
- deleteData(string nama): Menghapus node dengan nama produk tertentu dari LinkedList.</br>
-updateData(string name, string newName, double newPrice): Memperbarui node data  dengan nama produk yang ditentukan.</br>
- addDataCertainSequence(stringname, doubleprice, stringnameAfter): Menambahkan data dalam urutan yang ditentukan setelah node dengan nama produk yang ditentukan.</br>
- showData(): Menampilkan semua data dalam LinkedList.</br>
- deleteAllData(): Menghapus semua data dari LinkedList.</br>

 3. Fungsi utama: Dalam fungsi main(), program membuat objek class DoubleLinkedList dan kemudian melakukan operasi yang diperlukan dalam studi kasus. Pengguna dapat memilih berbagai operasi yang tersedia melalui menu yang ditampilkan di layar seperti menambah data, menghapus data, memperbarui data, menambah data dalam urutan tertentu, menghapus semua data dan Menampilkan semua data. Program ini memberi pengguna kemampuan untuk mengelola data produk perawatan kulit di dalam  toko secara fleksibel dan efisien menggunakan struktur data daftar tertaut ganda.



## Kesimpulan
1. Daftar tertaut tunggal (SLL) dan daftar tertaut ganda (DLL) adalah dua jenis daftar tertaut yang berbeda dalam cara mereka menggunakan pointer. SLL hanya memiliki penunjuk berikutnya, sedangkan DLL memiliki penunjuk berikutnya dan penunjuk sebelumnya.

2. SLL lebih hemat memori dibandingkan DLL karena setiap node hanya memerlukan satu pointer. SLL juga lebih efisien dalam menambah dan menghapus node di awal atau akhir daftar.
   
3.DLL memungkinkan operasi penghapusan dan penambahan node pada node mana pun, sehingga sangat berguna untuk mengimplementasikan algoritma yang memerlukan operasi tersebut. DLL juga memudahkan navigasi daftar dari depan (head) dan belakang (tail).

4.SLL dan DLL dapat digunakan untuk menyimpan data seperti nama dan umur siswa, serta data tentang produk dan harga di toko toko skincare.


## Referensi
[1] https://www.semanticscholar.org/paper/Artikel-Double-Linked-List-Circulate-Nugraha/db3440ea805484595b638fa29423795f4f903178

[2] https://www.semanticscholar.org/paper/List-linier(linked-list)-dan-variasinya_struktur-Putra/b242a169720943bde95311642bc51f3f1ee75eec
