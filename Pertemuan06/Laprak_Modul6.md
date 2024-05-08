# <h1 align="center">LAPORAN PRAKTIKUM MODUL 6 : STACK</h1>
<p align="center">AFRIZAL DWI NUGRAHA - 2311102136</p>

# Dasar Teori

## A. PENGERTIAN STACK
Kumpulan elemen data yang dismpan dalam satu lajur linier disebut tumpukan. Elemen data hanya dapat diakses pada satu lokasi, yaitu pada posisi ATAS (TOP) tumpukan.Tumpukan elemen dapat berisi data integer, nyata, rekaman, atau terstruktur.Penambahan elemen baru (PUSH) dan penghapusan elemen dari tumpukan (POP) adalah cara tumpukan disebut "Push Down Stack". Tumpukan ini menggunakan prinsip LIFO, yang berarti Masuk Terakhir Keluar Pertama.

## Guided 

### 1. [Program Operasi Stack]

```C++
#include <iostream>
using namespace std;

// Array untuk menyimpan nama-nama buku
string arrayBuku[5];

// Maksimum data yang bisa disimpan dalam stack
int maksimal = 5;

// Pointer untuk menunjukkan posisi teratas dalam stack
int top = 0;

// Fungsi untuk mengecek apakah stack sudah penuh
bool isFull() {
    return (top == maksimal);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return (top == 0);
}

// Fungsi untuk menambahkan data ke dalam stack
void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

// Fungsi untuk menghapus data dari stack
void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

// Fungsi untuk melihat data pada posisi tertentu dalam stack
void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

// Fungsi untuk menghitung jumlah data dalam stack
int countStack() {
    return top;
}

// Fungsi untuk mengubah data pada posisi tertentu dalam stack
void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

// Fungsi untuk menghapus semua data dalam stack
void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

// Fungsi untuk mencetak semua data dalam stack
void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    // Memasukkan beberapa data ke dalam stack buku
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    // Mencetak semua data dalam stack buku
    cetakArrayBuku();
    cout << "\n";

    // Menampilkan apakah stack penuh atau kosong
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    // Melihat data pada posisi tertentu dalam stack buku
    peekArrayBuku(2);
    
    // Menghapus data dari stack buku
    popArrayBuku();

    // Menampilkan jumlah data dalam stack buku
    cout << "Banyaknya data = " << countStack() << endl;

    // Mengubah data pada posisi tertentu dalam stack buku
    changeArrayBuku(2, "Bahasa Jerman");
    
    // Mencetak semua data dalam stack buku setelah perubahan
    cetakArrayBuku();
    cout << "\n";

    // Menghapus semua data dalam stack buku
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    
    // Mencetak semua data dalam stack buku setelah dihapus
    cetakArrayBuku();

    return 0;
}

```

## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]

```C++
// LAPRAK 6 : UNGUIDED 1
// AFRIZAL DWI NUGRAHA
// 2311102136
// S1 IF-11-D

// Program Stack untuk menentukan apakah kalimat tersebut Palindrom/tidak
#include <iostream>
#include <string> //library untuk menggunakan string
#include <stack> //library untuk menggunakan stack

using namespace std;

// Fungsi untuk membersihkan Kata_138 dari spasi dan karakter non-alphanumeric
string BersihkanKata_136 (string Kata_136) {
    string KataBersih_136;
    for (char & c_136 : Kata_136) {
        if (isalpha(c_136)) { // Memeriksa apakah karakter adalah huruf
            KataBersih_136 += tolower(c_136); // Mengubah huruf menjadi huruf kecil atau bersih
        }
    }
    return KataBersih_136;
}

// Fungsi untuk memeriksa apakah sebuah string adalah palindrom
bool Palindrom_136 (string Kata_136) {
    stack<char> TumpukkanKata_136;
    int Length_136 = Kata_136.length();

    // Memasukkan setengah karakter pertama ke dalam tumpukan
    for (int i_136 = 0; i_136 < Length_136 / 2; i_136++) {
        TumpukkanKata_136.push(Kata_136[i_136]);
    }

    // Menentukan titik awal untuk membandingkan karakter kedua setengah
    int Mulai_136 = Length_136 / 2;
    if (Length_136 % 2 != 0) {
        Mulai_136++;
    }

    // Membandingkan karakter kedua setengah dengan karakter dalam tumpukan
    for (int i_136 = Mulai_136; i_136 < Length_136; i_136++) {
        if (TumpukkanKata_136.empty() || Kata_136[i_136] != TumpukkanKata_136.top()) {
            return false;
        }
        TumpukkanKata_136.pop();
    }

    return true;
}

int main() {
    char LanjutkanInputKata_136;
    cout << "\n>>>> SELAMAT DATANG DI PROGRAM PALINDROM BY AFRIZAL DWI NUGRAHA 2311102136 <<<<" << endl; // Judul Program

    do {
        // Memasukkan Kata_136 atau kalimat yang ingin dimasukkan
        string Kata_136;
        cout << "\n>> Masukkan kalimat : "; // User diminta untuk memasukan kata atau kalimat yang ingin dimasukkan
        getline(cin, Kata_136);

        // Membersihkan Kata_136 dari spasi, karakter non-alphanumeric, dan mengubah huruf menjadi huruf kecil
        string KataBersih_136 = BersihkanKata_136 (Kata_136);

        // Memeriksa apakah Kata_136 adalah palindrom setelah dibersihkan
        if (Palindrom_136 (KataBersih_136)) {
            cout << "== Kalimat tersebut adalah : Palindrom" << endl; // Hasil yang berarti kata atau kalimat tersebut Palindrom
        } else {
            cout << "== Kalimat tersebut adalah : Bukan Palindrom" << endl; // Hasil yang berarti kata atau kalimat tersebut Bukan Palindrom
        }

        cout << "[2136] Apakah Anda ingin mencoba kalimat lain? (y/n) : "; // Menanyakan Kepada user apakah ingin mencoba kalimat lain atau tidak
        cin >> LanjutkanInputKata_136;
        cin.ignore(); // Untuk membersihkan buffer Kata_136 sebelumnya
    } while (LanjutkanInputKata_136 == 'y' || LanjutkanInputKata_136 == 'Y'); // Untuk melanjutkan input kata atau selesai

    return 0;
}

```
#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan06/Un%20Stak.PNG)

Ini adalah ringkasan singkat dari fungsinya:

1. Palindrom_136: Fungsi ini menentukan apakah string tertentu adalah palindrom, membersihkan kata_136: Fungsi ini membersihkan string masukan dengan menghapus spasi dan karakter non-alfanumerik serta mengubah semua karakter menjadi huruf kecil. Karakter dari string paruh pertama dan kedua dibandingkan menggunakan tumpukan.

2. Main: Anda berulang kali meminta pengguna memasukkan kalimat atau kata dalam fungsi utama. Selanjutnya, Anda menggunakan BersihkanKata_136 untuk membersihkan input dan menggunakan Palindrom_136 untuk mengetahui apakah itu palindrom. Terakhir, Anda meminta pengguna untuk mencoba input tambahan dan melanjutkan jika mereka memilih untuk melakukannya.

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

```C++
// LAPRAK 6 : UNGUIDED 2
// AFRIZAL DWI NUGRAHA
// 2311102136
// S1 IF-11-D

// Program Stack untuk melakukan pembalikan terhadap kalimat
#include <iostream>
#include <string> //library untuk menggunakan string
#include <stack>  //library untuk struktur data stack

using namespace std;

int main() {
    stack<char> CharStack_136;      // Inisialisasi stack untuk menyimpan karakter
    char LanjutkanInputKalimat_136; // Untuk melanjutkan input kalimat
    cout << "\n>>>> SELAMAT DATANG DI PROGRAM PEMBALIKAN KALIMAT BY AFRIZAL DWI NUGRAHA 2311102136 <<<<" << endl; // Judul Program

    do {
        string Kalimat_136, KalimatDibalik_136;
        cout << "\n>> Masukkan kalimat minimal 3 kata : "; // User diminta untuk memasukan kalimat yang ingin dimasukkan, dengan minimal 3 kata
        getline(cin, Kalimat_136);  // Membaca input Kalimat_138 dari pengguna

        for (char c_136 : Kalimat_136) {
            CharStack_136.push(c_136); // Menambahkan setiap karakter ke dalam stack
        }

        while (!CharStack_136.empty()) { // Untuk memeriksa apakah stack tersebut kosong atau tidak
            if (CharStack_136.top() == ' ') {
                KalimatDibalik_136 += ' '; // Menambahkan spasi ke Kalimat_138 terbalik jika karakter teratas adalah spasi
            } else {
                KalimatDibalik_136 += CharStack_136.top(); // Menambahkan karakter teratas dari stack ke Kalimat_138 terbalik
            }
            CharStack_136.pop(); // Menghapus karakter teratas dari stack
        }

        cout << "== Hasil kalimat yang dibalikkan : " << KalimatDibalik_136 << endl; // Hasil kalimat yang dibalikan

        cout << "[2136] Apakah Anda ingin mencoba kalimat lain? (y/n) : "; // Menanyakan Kepada user apakah ingin mencoba kalimat lain atau tidak
        cin >> LanjutkanInputKalimat_136;
        cin.ignore(); // Untuk membersihkan Kalimat_138 buffer sebelumnya
    } while (LanjutkanInputKalimat_136 == 'y' || LanjutkanInputKalimat_136 == 'Y'); // Untuk melanjutkan input Kalimat_138 atau selesai

    return 0;
}
```
#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan06/Un%20Stak01.PNG)

Berikut adalah beberapa kesimpulan singkat:

1.Validasi Input: Meskipun program ini tidak meminta pengguna memasukkan kalimat dengan minimal tiga kata, mungkin ingin menambahkan beberapa validasi untuk memastikan bahwa input memenuhi persyaratan ini.

2.Merawat Baris Baru: Ketika seseorang memasukkan kalimat dan tidak mengetik apa pun, mereka akan menghasilkan string kosong yang sedang diproses. Anda mungkin ingin mengatasi hal ini dengan memeriksa input kosong dan meminta mereka memasukkan kalimat yang benar.

3.Efisiensi: Metode ini sederhana dan efektif untuk input yang lebih kecil. Namun, untuk input yang lebih besar, terutama kalimat dengan banyak karakter, menggunakan tumpukan untuk pembalikan mungkin bukan metode yang paling efektif.  dapat mencoba salah kalimat dengan dua petunjuk atau mengubah string secara langsung.
Bertanya dalam Nama: Nama


## Kesimpulan
Kesimpulan dari praktikum struktur data dan algoritma tentang stack adalah struktur data yang memungkinkan penyimpanan dan penghapusan elemen secara terurut. Ini adalah kesimpulan dari praktikum Struktur data dan algoritma stack. Untuk menyelesaikan berbagai masalah, seperti mencari elemen tertentu, menghapus elemen, atau memaksakan urutan elemen, tumpukan dapat digunakan. Dalam praktikum, contoh penggunaan stack dalam bahasa C++ menunjukkan bagaimana operasi dasar seperti push, pop, dan peek dapat digunakan untuk mengelola stack. Kesimpulannya juga menunjukkan bahwa stack dapat digunakan dalam berbagai aplikasi, seperti mencari kalimat palindrom atau simetri, serta memahami konsep dasar kalimat stack dan cara programnya bekerja.


## Referensi
 [1] [Dr. Joseph Teguh Santoso. Struktur Data dan ALgoritma. Semarang: Yayasan Prima Agus Teknik. 2021.](https://ocw.upj.ac.id/files/Handout-TIF104-Modul-Praltikum-Struktur-Data.pdf)

 [2] [Muhammad Nugraha. Dasar Pemrograman Dengan C++ Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta. 2021.](https://sisfo.itp.ac.id/bahanajar/BahanAjar/Anisya/Modul%203%20-%20Tumpukan.pdf)
