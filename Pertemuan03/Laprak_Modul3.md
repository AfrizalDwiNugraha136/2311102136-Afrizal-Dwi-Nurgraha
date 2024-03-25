# <h1 align="center">Laporan Praktikum Modul SINGLE AND DOUBLE LINKED LIST</h1>
# <p align="center">Afrizal Dwi Nugraha-2311102136 </p>

## Dasar Teori
Linked List dan Double Linked List adalah dua jenis struktur data yang digunakan untuk menyimpan dan mengelola elemen data dalam suatu program.

1. Linked List  : Linked List adalah  struktur data linier yang terbentuk secara dinamis.Elemen Linked List disimpan sebagai node, yang terdiri dari dua elemen anak: bagian data  menyimpan elemen, dan bagian berikutnya menyimpan link ke node berikutnya. Linked List terbentuk ketika  banyak node dihubungkan bersama dan membentuk sebuah rantai. Setiap node menunjuk ke node berikutnya secara berurutan. Node pertama  selalu digunakan sebagai referensi ketika melintasi daftar yang disebut HEAD, sedangkan node terakhir akan menunjuk ke NULL.

2. Double Linked List : Double Linked List adalah varian dari Linked List, menggunakan pointer berikutnya dan sebelumnya yang masing-       masing menunjuk ke node berikutnya dan sebelumnya. Double Linked List dapat digunakan untuk berpindah dari node pertama ke node          terakhir atau sebaliknya, yang lebih efisien daripada Linked List hanya dengan penunjuk berikutnya.

Double Linked List dapat digunakan untuk mengurutkan data, seperti yang telah dilakukan pada artikel “Menerapkan dan Menganalisis Penyortiran DDouble Linked List. Double Linked List juga dapat digunakan dalam sistem komunikasi, seperti halnya dalam artikel "Design of buffered double linked list for LEO satelit beam-hopping forwarding", yang menggunakan dDouble Linked List. kebijakan Double Linked List untuk transmisi data antara satelit dan pengguna dalam sistem beam-hopping LEO 






## Guided 

### 1.  Tipe Data Primitif

#include <iostream>
#include <iomanip>

using namespace std;

// Tipe Data Primitif 

int main(){
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << "Result: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Result: " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Result: " << num1 * num2 << endl;
        break;
    case '/':
        if (num2 == 0) {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2 << endl;
        } else {
            cout << "Error!: Division by zero" << endl;
        }
        break;

    default:
        cout << "Error! operator is not correct" << endl;
        break;
    }
    return 0;
}
Kode di atas adalah program C++ yang melakukan operasi aritmatika berdasarkan input pengguna. Ini dimulai dengan mendeklarasikan variabel untuk sebuah operator (op), dua operan (num1 dan num2), dan sebuah hasil. Program kemudian meminta pengguna untuk memasukkan operator (+, -, *, /) dan dua operan. Ia menggunakan pernyataan switch untuk menentukan operator yang dimasukkan oleh pengguna dan melakukan operasi aritmatika yang sesuai. Jika operatornya adalah '/', program akan memeriksa apakah pembagi (angka2) adalah nol. Jika ya, ia akan menghitung hasilnya dan menampilkannya menggunakan pernyataan cout. Jika pembaginya bukan nol, pesan kesalahan akan ditampilkan. Terakhir, program mengembalikan 0 untuk menunjukkan eksekusi berhasil.

### 2. Tipe Data Abstrak

   #include <stdio.h>
#include <string.h>

// Struct
struct Mahasiswa
{
    char name[50];
    char address[50];
    int age;
};

// Tipe Data Abstrak by Jordan

int main() {
    // Menggunakan Struct
    struct Mahasiswa mhs1, mhs2;

    // Mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;

    // Mencetak isi dari struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);

    return 0;
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
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
