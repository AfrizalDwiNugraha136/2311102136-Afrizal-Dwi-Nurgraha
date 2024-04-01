# <h1 align="center">Laporan Praktikum Modul LINKED LIST CIRCULAR DAN NON CIRCULAR</h1>
# <p align="center">Afrizal Dwi Nugraha-2311102136 </p>

## Dasar Teori

Linked list adalah struktur data dinamis yang terdiri dari sekelompok node yang dihubungkan oleh pointer.Mereka dapat diklasifikasikan menjadi dua jenis: Linked list tunggal dan Linked list ganda.Linked list tunggal  menggunakan satu penunjuk untuk menghubungkan simpul-simpulnya, sedangkan Linked list ganda menggunakan dua penunjuk, satu ke simpul berikutnya dan satu lagi ke simpul sebelumnya.
 
Dalam konteks Linked list, istilah "melingkar" dan "tidak melingkar" mengacu pada struktur daftar.Linked list melingkar adalah jenis dLinked list di mana simpul terakhir dalam Linked list  kembali ke simpul pertama, sehingga menciptakan lingkaran tertutup.Sebaliknya, Linked list  non-lingkaran tidak memiliki karakteristik berikut; Node terakhir tidak mengacu pada node pertama.
  
Misalnya, dalam Linked list, ada dua varian:  melingkar dan non-lingkaran. Daftar melingkar tertaut tunggal adalah Linked list di mana simpul terakhir menunjuk  ke simpul pertama, membentuk lingkaran tertutup. Sebaliknya, daftar NON CIRCULAR yang tertaut tunggal tidak memiliki fitur ini; Node terakhir tidak mengacu pada node pertama.
 
Dalam daftar tertaut ganda, variasi melingkar juga dimungkinkan. Perulangan Linked list ganda adalah Linked list di mana simpul terakhir menunjuk  ke simpul pertama menggunakan penunjuk berikutnya dan sebelumnya, sehingga menciptakan perulangan tertutup.Ini berbeda dengan Linked list ganda non-lingkaran, yang mana simpul terakhir tidak terhubung kembali ke simpul pertama.
 
Singkatnya, istilah "CIRCULAR" dan "NON CIRCULAR" dalam konteks Linked list mengacu pada struktur daftar.Linked list melingkar adalah Linked list yang simpul terakhirnya menunjuk  ke simpul pertama, sehingga menciptakan perulangan tertutup, sedangkan daftar tertaut non-lingkaran tidak memiliki fitur ini.

## Guided 

### 1.  Linked List Non Circular

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
Kode C++ yang disediakan mengimplementasikan Linked list tunggal dengan berbagai fungsi seperti menyisipkan di awal, akhir dan tengah, menghapus di awal dan tengah, memodifikasi elemen di awal, akhir dan tengah, menghapus daftar dan menampilkan daftar. Berikut rincian fungsinya: 
 -init(): Menginisialisasi daftar tertaut dengan menyetel penunjuk kepala dan ekor ke NULL.</br>
 -isEmpty(): Memeriksa apakah daftar kosong.</br>
 -InsertFront(nilai int): Menyisipkan tombol di awal daftar.</br>
 -InsertBack(int value): Menyisipkan tombol di akhir daftar.</br>
 -countList(): Menghitung jumlah node dalam daftar.</br>
 -InsertMiddle(int data, int location): Menyisipkan node pada posisi yang ditentukan dalam daftar.</br>
 -RemoveFront(): Menghapus node pertama dari daftar.</br>
 -deleteCenter(int location): Menghapus sebuah node di lokasi yang ditentukan dalam daftar.</br>
 -ModifyFront(int data): Memodifikasi data node pertama.</br>
 -ModifyCenter(int data, int location): Memodifikasi data  node pada lokasi tertentu.</br>
 -ModifyBack(int data): Memodifikasi data terakhir dari node.</br>
 -clearList(): Hapus semua node dari daftar.</br>
 -display(): Menampilkan item daftar.</br>
 
Fungsi main() ini mendemonstrasikan cara menggunakan fungsi-fungsi ini dengan menyisipkan, menghapus, dan memodifikasi node, lalu menampilkan daftarnya pada waktu yang berbeda.

### 2. Tipe Data Abstrak

```C++

#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Kode C++ ini mengimplementasikan Linked list melingkar dengan berbagai operasi seperti menyisipkan di awal, menyisipkan di akhir, menyisipkan di posisi tertentu, menghapus dari awal, menghapus dari akhir, menghapus dari posisi tertentu, menghapus daftar, dan menampilkan daftar. Berikut gambaran singkat fungsi utamanya: 
 -init(): Menginisialisasi penunjuk kepala dan ekor.</br>
 -isEmpty(): Memeriksa apakah daftar kosong.</br>
 -createNode(string data): Membuat node baru dengan data yang diberikan.</br>
 -InsertFront(string data): Menyisipkan tombol di awal daftar.</br>
 -InsertBack(string data): Menyisipkan tombol di akhir daftar.</br>
 -InsertMiddle(data string, lokasi int): Menyisipkan node pada posisi yang ditentukan dalam daftar.</br>
 -RemoveFront(): Menghapus node dari daftar teratas.</br>
 -RemoveBack(): Menghapus node dari bagian bawah daftar.</br>
 -RemoveCenter(int location): Menghapus sebuah node dari lokasi yang ditentukan dalam daftar.</br>
 -clearList(): Menghapus seluruh daftar.</br>
 -display(): Menampilkan item daftar.</br>
 
Fungsi main() ini mendemonstrasikan penggunaan fungsi-fungsi ini dengan menyisipkan, menghapus, dan menampilkan elemen dalam berbagai situasi.



## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan04/Soal%201.PNG?raw=true)

![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan04/Soal%201(1).PNG?raw=true)

![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan04/Soal%201(2).PNG?raw=true)

```C++
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
```
#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan04/Unguided%201%20Non.PNG?raw=true)

![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan04/Unguided%201(1)%20Non.PNG?raw=true)

![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan04/Unguided%201(2)%20Non.PNG?raw=true)

Kode yang Anda berikan adalah program C++ yang mengimplementasikan daftar tertaut tunggal.Hal ini memungkinkan pengguna untuk melakukan berbagai operasi pada daftar tertaut seperti menambahkan node di awal, menambahkan node di akhir, menambahkan node pada posisi tertentu, memodifikasi node di awal, memodifikasi node di akhir, memodifikasi tombol di lokasi tertentu.lokasi, menghapus node di  depan, menghapus node di akhir, menghapus node di lokasi tertentu, melihat data yang disimpan dalam Linked List, dan menghapus seluruh daftar tertaut. Di bawah ini adalah ringkasan fungsi utama yang disediakan oleh program ini: 

 -Tambahkan bagian depan: Tambahkan node baru ke awal daftar tertaut.</br>
 -Tambah Kembali: Menambahkan simpul baru ke akhir daftar tertaut.</br>
 -Tambah Tengah: Menambahkan simpul baru pada posisi yang ditentukan dalam daftar tautan.</br>
 -Pengeditan Sebelumnya:  Edit simpul data di bagian atas daftar tertaut.</br>
 -Edit lagi:  Ubah data node di bagian bawah daftar tertaut.</br>
 -Memodifikasi antara: Memodifikasi data simpul di lokasi tertentu dalam daftar tertaut.</br>
 -Hapus Depan: Hapus tombol di bagian atas daftar link.</br>
 -Kembali Hapus:  Hapus node di bagian bawah daftar link.</br>
 -Hapus Antara:  Hapus node pada posisi yang ditentukan dalam daftar tautan.</br>
 -Hapus daftar (Hapus seluruh daftar):  Hapus semua node dari daftar tertaut.</br>
 -SHOW: Menampilkan semua data yang disimpan dalam daftar tertaut.</br>
 -EXIT: Keluar dari program.</br>
 
Program ini menggunakan pendekatan berbasis menu, di mana pengguna diminta  memilih operasi yang akan dilakukan pada daftar link.Program terus berjalan hingga pengguna memilih keluar dengan memasukkan “0”.



## Kesimpulan
1. Linked List Non Circular: 
 -Linked List Non Circular: adalah jenis daftar tertaut yang tidak memiliki simpul akhir,  tidak terhubung ke simpul pertama.</br>
 -Operasi daftar tertaut non-lingkaran mencakup mendeklarasikan simpul, membuat dan menginisialisasi penunjuk kepala dan ekor, memeriksastatus daftar tertaut, menambahkan simpul, menghapus simpul, dan menampilkan data linked list.</br>
 -Dapat digunakan untuk menyimpan data yang hanya perlu diakses satu kali saja, seperti data siswa.</br>

2. Circular Linked List:   
 -Circular Linked List  adalah jenis linked list yang tidak memiliki simpul akhir,  terhubung ke simpul pertama.</br>
 -Operasi daftar tertaut melingkar mencakup mendeklarasikan simpul, membuat dan menginisialisasi penunjuk kepala dan ekor, memeriksa status daftar tertaut, membuat simpul, menambahkan simpul, menghapus simpul, dan menampilkan daftar linked list.</br>
 -Dapat digunakan untuk menyimpan data yang memerlukan akses berulang, seperti playlist, daftar pesan dalam antrian, atau penggunaan memori berulang dalam suatu aplikasi.</br>

3. Penggunaan Linked List Non Circular dan Circular:
 -Linked List Non Circular dan Circular dapat digunakan untuk menyimpan data yang berbeda-beda, bergantung pada kebutuhan aplikasi.</br>
 -Daftar tertaut non-lingkaran  lebih cocok untuk menyimpan data yang memerlukan akses satu kali, sedangkan daftar tertaut melingkar lebih cocok untuk menyimpan data yang memerlukan banyak akses.</br>

## Referensi
[1] (https://www.semanticscholar.org/paper/Single-linked-list-Putra/80f629e3fddf788644da84f429a544749a4eefe2)

[2] https://www.semanticscholar.org/paper/struktur-data_double-linked-list-circular-yulianti/417f3ca894abfc1d5ac160325493852d5da09767
