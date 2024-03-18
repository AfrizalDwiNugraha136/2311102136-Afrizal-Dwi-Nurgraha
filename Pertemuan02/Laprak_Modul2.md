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

```C++
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
```
Kode ini menunjukkan program C++ yang menerima array tiga dimensi sebagai input  dan menampilkan data array. Program ini menggunakan loop bersarang untuk masuk dan keluar data array. Setiap elemen dalam array dimasukkan dan ditampilkan berdasarkan harga. Program ini menggunakan tipe data integer (int) untuk array dan menggunakan loop bersarang untuk masuk dan keluar dari data array. Setiap elemen dalam array dimasukkan menggunakan cout dan cin dan setiap elemen dalam array ditampilkan menggunakan cout. Program ini juga menggunakan fungsi endl untuk membuat  baris baru pada output. Untuk menjalankan program ini, Anda harus memiliki kompiler C++ dan memberikan masukan yang diperlukan.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;
// Program Mencari Nilai Maksimal pada Array
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Kode ini menunjukkan program C++ untuk mencari nilai maksimum dalam sebuah array. Program ini menggunakan loop for untuk memasukkan dan mengeluarkan data array. Setiap elemen dalam array dimasukkan menggunakan cout dan cin, dan nilai maksimum yang ditemukan ditampilkan menggunakan cout. Program ini menggunakan tipe data integer  untuk array dan menggunakan loop for untuk masuk dan keluar dari data array. Setiap elemen dalam array dimasukkan menggunakan cout dan cin, dan nilai maksimum yang ditemukan ditampilkan menggunakan cout. Program ini juga menggunakan variabel posisi untuk menyimpan indeks  elemen array dengan nilai terbesar. Untuk menjalankan program ini, Anda harus memiliki kompiler C++ dan memberikan masukan yang diperlukan.

## Unguided 

### 1. Buatlah program untuk menampilkan output seperti berikut dengan data yang diinputkan oleh user!
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan02/p.jpg?raw=true)

```C++
// LAPRAK 2 : UNGUIDED 1
// AFRIZAL DWI NUGRAHA
// 2311102136
// S1 IF-11-D
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Inisialisasi array
    int dataArray_136[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> Afi_136;
    vector<int> IF11D_136;

    // Memisahkan angka genap dan ganjil
    for (int i_136 = 0; i_136 < sizeof(dataArray_136) / sizeof(dataArray_136[0]); ++i_136) {
        if (dataArray_136[i_136] % 2 == 0) {
            Afi_136.push_back(dataArray_136[i_136]);
        } else {
            IF11D_136.push_back(dataArray_136[i_136]);
        }
    }

    // Menampilkan hasil
    cout << "Data Array   :";
    for (int i_136 = 0; i_136 < sizeof(dataArray_136) / sizeof(dataArray_136[0]); ++i_136) {
        cout << " " << dataArray_136[i_136];
    }
    cout << endl;

    cout << "Nomor Genap  :";
    for (int i_136 = 0; i_136 < Afi_136.size(); ++i_136) {
        cout << " " << Afi_136[i_136];
        if (i_136 < Afi_136.size() - 1) {
            cout << ",";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil :";
    for (int i_136 = 0; i_136 < IF11D_136.size(); ++i_136) {
        cout << " " << IF11D_136[i_136];
        if (i_136 < IF11D_136.size() - 1) {
            cout << ",";
        }
    }
    cout << endl;

    return 0;
}
```
#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan02/Unguided%201%20Array.PNG?raw=true)

Kode ini menunjukkan program C++ yang memisahkan bilangan genap dan ganjil dalam sebuah array. Program ini menggunakan loop for untuk memasukkan dan mengeluarkan data array. Setiap elemen dalam array dimasukkan menggunakan cout dan cin, dan angka genap dan ganjil ditampilkan menggunakan cout. Program ini menggunakan tipe data integer (int) untuk array dan menggunakan vektor untuk menyimpan bilangan genap dan ganjil. Setiap elemen dalam array dimasukkan menggunakan cout dan cin, dan angka genap dan ganjil ditampilkan menggunakan cout. Program ini juga menggunakan variabel posisi untuk menyimpan indeks  elemen array dengan nilai terbesar. Untuk menjalankan program ini, Anda harus memiliki kompiler C++ dan memberikan masukan yang diperlukan.

### 2. Buatlah program input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
// LAPRAK 2 : UNGUIDED 2
// AFRIZAL DWI NUGRAHA          
// 2311102136
// S1 IF-11-D
#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI by AFRIZAL DWI NUGRAHA
int main()
{
    // Deklarasi array dengan ukuran 1x3x8
    int array_136[1][3][8];
    // Input elemen
    for (int x_136 = 0; x_136 < 1; x_136++)
    {
        for (int y_136 = 0; y_136 < 3; y_136++)
        {
            for (int z_136 = 0; z_136 < 8; z_136++)
            {
                cout << "Input Array[" << x_136 << "][" << y_136 << "][" << z_136 << "] = ";
                cin >> array_136[x_136][y_136][z_136];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x_136 = 0; x_136 < 1; x_136++)
    {
        for (int y_136 = 0; y_136 < 3; y_136++)
        {
            for (int z_136 = 0; z_136 < 8; z_136++)
            {
                cout << "Data Array[" << x_136 << "][" << y_136 << "][" << z_136 << "] = " << array_136[x_136][y_136][z_136] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x_136 = 0; x_136 < 1; x_136++)
    {
        for (int y_136 = 0; y_136 < 3; y_136++)
        {
            for (int z_136 = 0; z_136 < 8; z_136++)
            {
                cout << array_136[x_136][y_136][z_136] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
 #### Output:
 ![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan02/Unguided%202%20Array.PNG?raw=true)

Kode ini menunjukkan program C++ yang menerima array tiga dimensi sebagai input  dan menampilkan data array. Program ini menggunakan loop bersarang untuk masuk dan keluar data array. Setiap elemen dalam array dimasukkan menggunakan cout dan cin dan setiap elemen dalam array ditampilkan menggunakan cout. Program ini menggunakan tipe data integer (int) untuk array dan menggunakan loop bersarang untuk masuk dan keluar dari data array. Setiap elemen dalam array dimasukkan menggunakan cout dan cin dan setiap elemen dalam array ditampilkan menggunakan cout. Program ini juga menggunakan fungsi endl untuk membuat  baris baru pada output. Untuk menjalankan program ini, Anda harus memiliki kompiler C++ dan memberikan masukan yang diperlukan.

### 3. Buatlah program menu untuk mencari nilai maksimum, minimum dan nilai rata – rata dari suatu array dengan input yang dimasukkan oleh user!

```C++
// LAPRAK 2 : UNGUIDED 3
// AFRIZAL DWI NUGRAHA
// 2311102136
// S1 IF-11-D
#include <iostream>
using namespace std;

// Fungsi untuk mencari nilai maksimum
int Afi136_Maksimum(const int array_136[], int size_136, int& lokasi_136) {
    int maks_136 = array_136[0];
    lokasi_136 = 0;
    for (int i_136 = 1; i_136 < size_136; ++i_136) {
        if (array_136[i_136] > maks_136) {
            maks_136 = array_136[i_136];
            lokasi_136 = i_136;
        }
    }
    return maks_136;
}

// Fungsi untuk mencari nilai minimum
int Afi136_Minimum(const int array_136[], int size_136, int& lokasi_136) {
    int min_136 = array_136[0];
    lokasi_136 = 0;
    for (int i_136 = 1; i_136 < size_136; ++i_136) {
        if (array_136[i_136] < min_136) {
            min_136 = array_136[i_136];
            lokasi_136 = i_136;
        }
    }
    return min_136;
}

// Fungsi untuk mencari nilai rata-rata atau Average
double Afi136_Average(const int array_136[], int size_136) {
    int total_136 = 0;
    for (int i_136 = 0; i_136 < size_136; ++i_136) {
        total_136 += array_136[i_136];
    }
    return static_cast<double>(total_136) / size_136;
}

int main() {
    int n_136;
    cout << "Masukkan panjang array: ";
    cin >> n_136;
    
    int array_136[n_136];
    cout << "Masukkan " << n_136 << " angka\n";
    for (int i_136 = 0; i_136 < n_136; ++i_136) {
        cout << "Array ke-" << i_136 << ": ";
        cin >> array_136[i_136];
    }

    int Pilihan_136;
    int lokasi_136;
    do {
        cout << "\nMENU OPERASI ARRAY AFRIZAL DWI NUGRAHA:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Cari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih Nomor: ";
        cin >> Pilihan_136;

        switch (Pilihan_136) {
            case 1:
                cout << "Nilai maksimum adalah: " << Afi136_Maksimum(array_136, n_136, lokasi_136) << " \nberada di Array ke-" << lokasi_136 << endl;
                break;
            case 2:
                cout << "Nilai minimum adalah: " << Afi136_Minimum(array_136, n_136, lokasi_136) << " \nberada di Array ke-" << lokasi_136 << endl;
                break;
            case 3:
                cout << "Nilai rata-rata adalah: " << Afi136_Average(array_136, n_136) << endl;
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid, Silahkan coba lagi menggunakan nomor yang tersedia!\n";
        }
    } while (Pilihan_136 != 4);
    return 0;
}
```
#### Output:
 ![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan02/Unguided%203%20Array.PNG?raw=true)

Kode ini menunjukkan program C++ yang menerima input dari array tiga dimensi, dan kode ini menunjukkan program C++ yang menyediakan fungsi untuk mencari nilai maksimum, nilai minimum, dan nilai rata-rata dalam sebuah array. Program ini menggunakan loop for untuk memasukkan dan mengeluarkan data array. Setiap elemen dalam array dimasukkan menggunakan cout dan cin, dan nilai maksimum, minimum, dan rata-rata ditampilkan menggunakan cout. Program ini menggunakan tipe data integer (int) untuk array dan menggunakan fungsi untuk menghitung nilai maksimum, minimum, dan rata-rata. Setiap elemen dalam array dimasukkan menggunakan cout dan cin, dan nilai maksimum, minimum, dan rata-rata ditampilkan menggunakan cout. Program ini juga menggunakan kotak sakelar untuk menampilkan menu operasi tabel dan menampilkan hasil operasi yang dipilih. Untuk menjalankan program ini, Anda harus memiliki kompiler C++ dan memberikan masukan yang diperlukan.

## Kesimpulan
• Array adalah struktur data  paling dasar dan merupakan jenis variabel yang terdiri dari kumpulan data sejenis yang disusun dalam suatu baris atau dimensi. 

• Array satu dimensi adalah jenis penutup variabel terdiri dari sekumpulan data bertipe sama yang disusun dalam satu baris atau berdimensi.

• Array dua dimensi adalah variabel yang terdiri dari kumpulan array satu dimensi bertipe sama yang disusun dalam baris dan kolom.

• Array multidimensi mirip dengan array satu dimensi dan dua dimensi tetapi memiliki kapasitas memori  lebih besar.

• Array ini digunakan untuk merepresentasikan array dengan  lebih dari dua dimensi atau array dengan lebih dari dua indeks, seperti array tiga dimensi, array empat dimensi, array lima dimensi, dll.

• Program yang menggunakan array dapat digunakan untuk menampilkan output  yang diinginkan, mencari nilai maksimum dalam sebuah array, dan menampilkan nilai rata-rata dari sebuah array.

## Referensi
[1] MA Pratama - 2020 - osf.io
