# <h1 align="center">Laporan Praktikum Modul Array</h1>
# <p align="center">Afrizal Dwi Nugraha-2311102136 </p>

## Dasar Teori

• Array adalah  struktur yang terdiri dari sejumlah elemen tertentu dengan tipe data yang sama. Elemen-elemen array disusun secara berurutan dalam memori komputer. Semua elemen dalam array memiliki tipe yang sama. Array cocok untuk mengatur kumpulan data homogen yang ukuran atau jumlah maksimum elemennya diketahui sejak awal. Seragam artinya setiap elemen dalam array tertentu harus mempunyai tipe data yang sama.

• Array satu dimensi adalah kumpulan elemen identik yang disusun dalam satu baris, tetapi isi  elemen tersebut bisa berbeda. Bisa juga disebut  vektor yang mendeskripsikan data secara berurutan Deklarasi: Data_Type Variable_Name [index] Contoh: int A[5];

• Array dua dimensi, sering disebut sebagai matriks, merupakan perpanjangan dari  array satu dimensi. Jika array satu dimensi hanya terdiri dari satu baris dengan beberapa kolom elemen, maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Mendeklarasikan array dua dimensi hampir sama dengan mendeklarasikan array satu dimensi, hanya saja array tersebut merupakan array dua dimensi.

• Array Tiga Dimensi Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atau tiga sisi. 
Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3]; 
Misal : int A [3][4][2];

## Guided 

### 1.  Program Input Array Tiga Dimensi

#include <iostream>
using namespace std;
// Program input array 3 dimensi
int main()
{
    // Deklarasi array
    int arr[2][3][3];

    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
Kode di atas adalah program C++ yang melakukan operasi aritmatika berdasarkan input pengguna. Ini dimulai dengan mendeklarasikan variabel untuk sebuah operator (op), dua operan (num1 dan num2), dan sebuah hasil. Program kemudian meminta pengguna untuk memasukkan operator (+, -, *, /) dan dua operan. Ia menggunakan pernyataan switch untuk menentukan operator yang dimasukkan oleh pengguna dan melakukan operasi aritmatika yang sesuai. Jika operatornya adalah '/', program akan memeriksa apakah pembagi (angka2) adalah nol. Jika ya, ia akan menghitung hasilnya dan menampilkannya menggunakan pernyataan cout. Jika pembaginya bukan nol, pesan kesalahan akan ditampilkan. Terakhir, program mengembalikan 0 untuk menunjukkan eksekusi berhasil.

### 1.  Program Input Array Tiga Dimensi

   #include <iostream> 
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
 // Deklarasi array 
 int arr[2][3][3];
 // Input elemen
 for (int x = 0; x < 2; x++)
 {
    for (int y = 0; y < 3; y++)
     {
        for (int z = 0; z < 3; z++)
         {
            cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
            cin >> arr[x][y][z];
         }
      }
      cout << endl;
    }
 // Output Array
 for (int x = 0; x < 2; x++)
 {
    for (int y = 0; y < 3; y++)
     {
        for (int z = 0; z < 3; z++)
         {
             cout << "Data Array[" << x << "][" << y << "][" << z<< "] = " << arr[x][y][z] << endl;
         }
     }
 }
 cout << endl;
 // Tampilan array
for (int x = 0; x < 2; x++)
{
 for (int y = 0; y < 3; y++)
 {
    for (int z = 0; z < 3; z++)
    {
    cout << arr[x][y][z] << ends;
    }
    cout << endl;
 }
 cout << endl;
 }
}

Kode yang diberikan adalah program C yang mendefinisikan sebuah struct bernama Mahasiswa, yang memiliki tiga field: nama (array karakter berukuran 50), alamat (array karakter lain berukuran 50), dan umur (sebuah bilangan bulat). Program kemudian membuat dua contoh struct, mhs1 dan mhs2, dan memberikan nilai ke bidangnya masing-masing. Terakhir, ia mencetak nilai kolom menggunakan fungsi printf.
Kode ini menggunakan fungsi strcpy dari pustaka string.h untuk menyalin nilai string ke dalam bidang nama dan alamat struct. Itu juga menggunakan fungsi printf untuk memformat dan mencetak nilai bidang. Program ini mendemonstrasikan cara mendefinisikan dan menggunakan struct di C, serta cara mengakses dan memanipulasi bidangnya.

### 3. Tipe Data Koleksi

#include <iostream>
#include <array>
using namespace std;

// Tipe Data Koleksi by Jordan

int main() {
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;

    return 0;
}
Kode yang diberikan adalah program C++ sederhana yang mendeklarasikan dan menginisialisasi array bilangan bulat yang disebut "nilai". Ia kemudian mencetak nilai setiap elemen dalam array menggunakan pernyataan "cout". Outputnya akan menampilkan nilai elemen array sesuai urutan penetapannya, dipisahkan oleh baris baru.

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
[1] MA Pratama - 2020 - osf.io
