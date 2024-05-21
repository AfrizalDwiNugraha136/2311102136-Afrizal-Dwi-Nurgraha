# <h1 align="center">LAPORAN PRAKTIKUM MODUL 8 : ALGORITMA SEARCHING</h1>
<p align="center">AFRIZAL DWI NUGRAHA - 2311102136</p>

# Dasar Teori

## A. PENGERTIAN ALGORITMA SEARCHING
Pencarian (Searching) adalah  proses untuk menemukan elemen tertentu dalam sekelompok data. Dalam pemrograman C++, dua metode pencarian umum yang digunakan adalah:

1. Pencarian Berurutan (Linear Search) :
Metode ini bekerja dengan membandingkan elemen data yang dicari satu per satu dengan setiap elemen dalam kumpulan data. Sampai elemen yang dicari ditemukan atau seluruh kumpulan data telah diproses, metode ini berfungsi. Meskipun mudah digunakan, pencarian berurutan tidak efektif untuk kumpulan data besar.

2. Pencarian Biner :
Metode ini hanya dapat diterapkan pada kumpulan data yang sudah terurut. Pencarian biner membagi kumpulan data secara berulang menjadi dua bagian dan memeriksa elemen yang dicari dengan elemen tengah. Jika elemen yang dicari lebih kecil atau lebih besar dari elemen tengah, maka pencarian dilanjutkan ke bagian kiri atau kanan kumpulan data.Untuk kumpulan data yang besar, pencarian biner lebih efektif daripada pencarian berurutan.

Faktor-faktor yang mempengaruhi efisiensi searching adalah sebagai berikut:
1. Ukuran Kumpulan Data: Waktu searching lebih lama dengan kumpulan data yang lebih besar.
2. Urutan Kumpulan Data: Hanya kumpulan data yang terurut yang dapat digunakan searching biner.
3. Pilihan Algoritma searching: Karakteristik kumpulan data dan kebutuhan aplikasi menentukan algoritma searching yang tepat.


## Guided 

### 1. Latihan Searching

```C++
#include <iostream>

using namespace std;

int main(){
    int n = 10;
    int data[n] = {9,4,1,7,5,12,4,13,4,10};
    int cari = 10;
    bool ketemu = false;
    int i;

    for (i = 0; i < n; i++){
        if(data[i] == cari){
            ketemu = true;
            break;
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "data : {9,4,1,7,5,12,4,13,4,10}" << endl;

    if (ketemu){
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }else{
        cout << "data tidak ditemukan" << endl;
    }

    return 0;
}
```

### 2. Latihan Searching

```C++
#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void Selection_Sort(){
    int temp, min, i, j;
    for(i = 0; i < 7; i++){
        min = i;
        for(j = i + 1; j < 7; j++){
            if(dataArray[j] < dataArray[min]){
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void BinarySearch(){
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6;
    while(!b_flag && awal <= akhir){
        tengah = (awal + akhir)/2;
        if(dataArray[tengah] == cari){
            b_flag = true;
        } else if(dataArray[tengah] < cari){
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag){
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main(){
    cout << "BINARY SEARCH" << endl;
    cout << "\nData : ";
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;
    
    cout << "\nData diurutkan : ";
    Selection_Sort();

    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    BinarySearch();
    _getche();
    return 0;
}
```

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
#include <iostream>
#include <conio.h>  // Jika menggunakan Windows. Untuk sistem operasi lain, perlu mencari pengganti dari _getche()
#include <string>

using namespace std;

// Fungsi untuk melakukan pencarian binary pada array karakter
int binarySearch_136 (char Array_136 [], int Indeks_136 [], int Size_136, char Target_136) {
    int Kiri_136 = 0;
    int Kanan_136 = Size_136 - 1;

    // Melakukan binary search selama Kiri_136 tidak melebihi Kanan_136
    while (Kiri_136 <= Kanan_136) {
        int Tengah_136 = Kiri_136 + (Kanan_136 - Kiri_136) / 2;

        // Jika huruf Target_136 berada di tengah array
        if (Array_136 [Tengah_136] == Target_136)
            return Indeks_136 [Tengah_136];

        // Jika huruf Target_136 berada di sebelah kiri tengah array
        if (Array_136 [Tengah_136] > Target_136)
            Kanan_136 = Tengah_136 - 1;

        // Jika huruf Target_136 berada di sebelah kanan tengah array
        else
            Kiri_136 = Tengah_136 + 1;
    }

    // Jika huruf Target_136 tidak ditemukan
    return -1;
}
// Fungsi untuk melakukan selection sort pada array karakter
void selectionSort_136 (char Array_136 [], int Indeks_136 [], int Size_136) {
    for (int i_136 = 0; i_136 < Size_136 - 1; ++i_136) {
        int IndeksTengah_136 = i_136;
        for (int j_136 = i_136 + 1; j_136 < Size_136; ++j_136) {
            if (Array_136 [j_136] < Array_136 [IndeksTengah_136]) {
                IndeksTengah_136 = j_136;
            }
        }
        // Menukar elemen minimum dengan elemen pertama
        swap(Array_136 [i_136], Array_136 [IndeksTengah_136]);
        swap(Indeks_136 [i_136], Indeks_136 [IndeksTengah_136]);
    }
}

int main() {
    string sentence_136;
    char Target_136;
    cout << "\n======= SELAMAT DATANG DI PROGRAM BINARY SEARCH BY AFRIZAL DWI NURGRAHA =======" << endl;
    cout << "\n>> Masukkan kalimat : ";
    getline(cin, sentence_136);

    // Membuat array untuk menyimpan karakter dan indeks asli mereka
    int len = sentence_136.size();
    char charArray[100];
    int Indeks_136 [100];
    int Size_136 = 0;

    for (int i_136 = 0; i_136 < len; ++i_136) {
        if (sentence_136[i_136] != ' ') {  // Mengabaikan spasi
            charArray[Size_136] = sentence_136[i_136];
            Indeks_136 [Size_136] = i_136;
            ++Size_136;
        }
    }

    // Mengurutkan array karakter menggunakan selection sort
    selectionSort_136 (charArray, Indeks_136 , Size_136);

    cout << ">> Masukkan huruf yang ingin dicari : ";
    cin >> Target_136;

    // Mencari huruf dalam array yang telah diurutkan
    int Index_136 = binarySearch_136 (charArray, Indeks_136 , Size_136, Target_136);

    if (Index_136 != -1) {
        cout << "[2136] Huruf '" << Target_136 << "' ditemukan pada indeks ke-" << Index_136 << " dalam kalimat." << endl;
    } else {
        cout << "[2136] Huruf '" << Target_136 << "' tidak ditemukan dalam kalimat." << endl;
    }

    _getche();  // Hanya untuk Windows. Jika menggunakan OS lain, gunakan pengganti sesuai kebutuhan
    return 0;
}
```

#### Output:
![SS]()

...

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++
#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk memeriksa apakah sebuah karakter adalah vokal
bool isVowel_136 (char Karakter_136) {
    // Konversi karakter menjadi huruf kecil
    Karakter_136 = tolower(Karakter_136);
    // Periksa apakah karakter adalah salah satu dari 'a', 'e', 'i', 'o', 'u'
    return (Karakter_136 == 'a' || Karakter_136 == 'e' || Karakter_136 == 'i' || Karakter_136 == 'o' || Karakter_136 == 'u');
}

// Fungsi untuk menghitung banyaknya huruf vokal dalam sebuah kalimat
int countVowels_136 (const string &Kalimat_136) {
    int Count_136 = 0;
    for (char Karakter_136 : Kalimat_136) {
        if (isVowel_136 (Karakter_136)) {
            Count_136++;
        }
    }
    return Count_136;
}
int main() {
    string Kalimat_136;
    cout << "\n===== SELAMAT DATANG DI PROGRAM MENCARI KALIMAT VOKAL BY AFRIZAL DWI NUGRAHA =====";
    cout << "\n>> Masukkan sebuah kalimat : ";
    getline(cin, Kalimat_136); // Membaca input kalimat dari pengguna

    int vowelCount_136 = countVowels_136 (Kalimat_136);
    cout << "[2136] Banyaknya huruf vokal dalam kalimat adalah : " << vowelCount_136 << endl;
    return 0;
}
```

#### Output:
![SS]()

...

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```C++
#include <iostream>

using namespace std;

int main(){
    int n_136 = 10;
    int Data_136 [n_136] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int Target_136 = 4;
    int Count_136 = 0;

    // Melakukan pencarian sequential untuk menghitung banyaknya angka 4
    for (int i = 0; i < n_136; i++) {
        if (Data_136 [i] == Target_136) {
            Count_136++;
        }
    }
    cout << "===== SELAMAT DATANG DI PROGRAM SEQUENTIAL SEARCH BY AFRIZAL DWI NUGRAHA =====" << endl;
    cout << "Data : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Angka " << Target_136 << " ditemukan sebanyak " << Count_136 << " kali." << endl;
 return 0;
}
...

#### Output:
![SS]()

...

## Kesimpulan
...


## Referensi
 [1] (https://p3m.sinus.ac.id/jurnal/index.php/TIKomSiN/article/view/546)

 [2] (https://jurnal.untan.ac.id/index.php/jepin/article/view/68389)
