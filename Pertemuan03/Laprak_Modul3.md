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

    return 0;M
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
 Pengguna diminta untuk memilih operasi yang diinginkan dan program akan melakukan operasi  sesuai dengan pilihan pengguna.


## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

#include <iostream>

using namespace std;

// Fungsi untuk menghitung rata-rata dari sejumlah nilai
float hitungRataRata(int jumlahNilai) {
    int total = 0;
    int nilai;

    for (int i = 0; i < jumlahNilai; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> nilai;
        total += nilai;
    }

    return static_cast<float>(total) / jumlahNilai;
}

// Fungsi utama
int main() {
    int jumlahNilai;

    cout << "Program Menghitung Rata-Rata Nilai\n";
    cout << "---------------------------------\n";

    // Input jumlah nilai dari pengguna
    cout << "Masukkan jumlah nilai: ";
    cin >> jumlahNilai;

    // Memanggil fungsi hitungRataRata dan menampilkan hasil
    float rataRata = hitungRataRata(jumlahNilai);
    cout << "Rata-rata nilai adalah: " << rataRata;

    return 0;
}

#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan01/Unguided%201%20tipe%20data.PNG?raw=true)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

#include <iostream>
#include <string>

using namespace std;

// Struct untuk merepresentasikan informasi penulis buku
struct Author {
    string name;
    int birthYear;
};

// Class untuk merepresentasikan informasi buku
class Book {
public:
    // Constructor untuk inisialisasi informasi buku
    Book(string title, Author author, int yearPublished)
        : title(title), bookAuthor(author), yearPublished(yearPublished) {}

    // Fungsi untuk menampilkan informasi buku
    void displayInfo() {
        cout << "Buku: " << title << std::endl;
        cout << "Penulis: " << bookAuthor.name << std::endl;
        cout << "Tahun Terbit: " << yearPublished << std::endl;
    }

private:
    // Informasi buku
    string title;
    Author bookAuthor;
    int yearPublished;
};

int main() {
    // Membuat objek Author
    Author author{"John Doe", 1980};

    // Membuat objek Book menggunakan struct Author sebagai bagian dari class
    Book book1("Pemrograman C++", author, 2022);

    // Menampilkan informasi buku
    book1.displayInfo();

    return 0;
}

 #### Output:
 
   

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] https://www.semanticscholar.org/paper/Artikel-Double-Linked-List-Circulate-Nugraha/db3440ea805484595b638fa29423795f4f903178

[2] https://www.semanticscholar.org/paper/List-linier(linked-list)-dan-variasinya_struktur-Putra/b242a169720943bde95311642bc51f3f1ee75eec
