# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
# <p align="center">Afrizal Dwi Nugraha-2311102136 </p>

## Dasar Teori

Tipe data pemrograman merupakan atribut yang berkaitan dengan data yang akan memberi tahu sistem komputer. Sehingga nantinya bisa menafsirkan nilai dari data tersebut. Secara khusus, tipe data adalah format penyimpanan data. Data bisa dalam bentuk variabel untuk tipe data tertentu.
1. Tipe data primitif adalah tipe data bawaan dari bahasa pemrograman, di Java ada delapan tipe data primitif, dan semuanya sudah kita bahas yaitu : byte, short, int, long, float, double, boolean,dan char

2. Tipe data abstrak, adalah tipe data yang merupakan hasil imajinasi kita dengan memberikan beberapa batasan domain maupun operasinya. Contoh : usia, daftar nilai.

3. Tipe data koleksi adalah suatu kumpulan data yang terstruktur dalam bentuk list, tuple, set, atau dictionary. Python menyediakan beberapa tipe data koleksi yang dapat menyimpan berbagai macam tipe data, termasuk string, numerik, dan koleksi. Tipe data koleksi dapat berisi obyek lain dengan berbagai macam tipe data, dan dapat berubah-ubah (mutable) atau tidak berubah (immutable) tergantung pada tipe data koleksi yang digunakan.

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
 ![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Unguided%202%20tipe%20data.PNG?raw=true).

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

#include <iostream>
#include <map>
#include <string>
#include <sstream>

using using namespace std;

int main() {
    string kalimat;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    map<string, int> frekuensiKata;

    stringstream ss(kalimat);
    string kata;

    while (ss >> kata) {
        // Mengonversi kata menjadi lowercase untuk menghindari perbedaan antara huruf besar dan kecil
        for (char& c : kata) {
            c = tolower(c);
        }

        // Menambah frekuensi kemunculan kata dalam map
        frekuensiKata[kata]++;
    }

    // Menampilkan hasil frekuensi kemunculan kata
    cout << "\nFrekuensi Kemunculan Kata:\n";
    for (const auto& pair : frekuensiKata) {
        cout << pair.first << ": " << pair.second << " kali\n";
    }

    return 0;
} 

#### Output:
 ![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan01/unguided%203.PNG?raw=true).


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] [https://it.telkomuniversity.ac.id/6-tipe-data-pemrograman-yang-harus-anda-pahami-apa-saja/](https://it.telkomuniversity.ac.id/6-tipe-data-pemrograman-yang-harus-anda-pahami-apa-saja/#:~:text=Tipe%20data%20pemrograman%20merupakan%20atribut,variabel%20untuk%20tipe%20data%20tertentu.)https://it.telkomuniversity.ac.id/6-tipe-data-pemrograman-yang-harus-anda-pahami-apa-saja/#:~:text=Tipe%20data%20pemrograman%20merupakan%20atribut,variabel%20untuk%20tipe%20data%20tertentu.

[2] https://www.programmerzamannow.com/pemrograman/java/dasar/tipe-data-bukan-primitif/#:~:text=Tipe%20data%20primitif%20adalah%20tipe,int

[3] https://id.scribd.com/document/626864127/Tipe-Data-Koleksi
