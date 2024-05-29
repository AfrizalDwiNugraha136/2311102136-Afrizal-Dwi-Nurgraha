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
#include<iostream>

using namespace std;

//Prosedur untuk menampilkan huruf-huruf didalam kalimat
void TampilkanHurufKalimat_136(char ArrayKalimat_136[], int PanjangKalimat_136){
    for(int i = 0; i < PanjangKalimat_136; i++){ //perulangan for untuk menampilkan huruf
        cout << ArrayKalimat_136[i] << '\t';
    }
    cout << endl;
}

//Prosedur untuk mengurutkan huruf sesuai abjad menggunakan bubble sort
void BubbleSort_136(char ArrayKalimat_136[], int PanjangKalimat_136){
    bool Urut_136 = true; 
    int j = 0; 
    char temp_136; 
    while(Urut_136){ 
        Urut_136 = false;
        j++; 
        for(int i = 0; i < PanjangKalimat_136 - j; i++){ 
            if(ArrayKalimat_136[i] > ArrayKalimat_136[i + 1]){  
                temp_136 = ArrayKalimat_136[i]; 
                ArrayKalimat_136[i] = ArrayKalimat_136[i + 1]; 
                ArrayKalimat_136[i + 1] = temp_136; 
                Urut_136 = true; 
            }
        }
    }
}

//Prosedur untuk mencari huruf didalam kalimat menggunakan binary search
void BinarySearch_136(char ArrayKalimat_136[], int PanjangKalimat_136, char HurufYangDicari_136){
    int awal_136, tengah_136, akhir_136, Posisi_136;  
    bool b_flag = false; 
    awal_136 = 0; 
    akhir_136 = PanjangKalimat_136; 
    while(!b_flag && awal_136 <= akhir_136){ 
        tengah_136 = (awal_136 + akhir_136)/2; 
        if(HurufYangDicari_136 == ArrayKalimat_136[tengah_136]){ 
            Posisi_136 = tengah_136; 
            b_flag = true; 
            break; 
        } else if(HurufYangDicari_136 < ArrayKalimat_136[tengah_136]){ 
            akhir_136 = tengah_136 - 1; 
        } else if(HurufYangDicari_136 > ArrayKalimat_136[tengah_136]){ 
            awal_136 = tengah_136 + 1; 
        }
    }
    if(b_flag){ 
        cout << "Huruf " << HurufYangDicari_136 << " ditemukan pada index ke-";
        for(int i = 0; i < PanjangKalimat_136; i++){
            if(HurufYangDicari_136 == ArrayKalimat_136[i]){
                cout << i;
                if(ArrayKalimat_136[i + 1] == HurufYangDicari_136){
                    cout << ", ";
                }
            }
        }
    } else { 
        cout << "Huruf " << HurufYangDicari_136 << " tidak ditemukan" << endl;
    }
}

int main(){
    string InputKalimat_136, KalimatTanpaSpasi_136; 
    int PanjangKalimat_136; 
    char HurufYangDicari_136; 
    cout << "--- PROGRAM MENCARI HURUF DALAM KALIMAT BY AFRIZAL DWI NUGRAHA---" << endl;
    cout << "Masukkan kalimat = "; 
    getline(cin, InputKalimat_136); 
    cout << endl;

    // Menghapus karakter spasi dari kalimat
    KalimatTanpaSpasi_136 = ""; 
    for(char c : InputKalimat_136){
        if(c != ' ') { 
            KalimatTanpaSpasi_136 += c; 
        }
    }

    //menghitung panjang kalimat
    PanjangKalimat_136 = KalimatTanpaSpasi_136.length();
    char ArrayKalimat_136[PanjangKalimat_136];
    for(int i = 0; i < PanjangKalimat_136; i++){
        ArrayKalimat_136[i] = KalimatTanpaSpasi_136[i]; 
    }

    //Menampilkan setiap huruf dalam kalimat sebelum di urutkan
    cout << "Urutan huruf dalam kalimat sebelum diurutkan (spasi dihilangkan) = " << endl;
    TampilkanHurufKalimat_136(ArrayKalimat_136, PanjangKalimat_136); 

    //Menampilkan setiap huruf dalam kalimat setelah di urutkan
    cout << "Urutan huruf dalam kalimat setelah diurutkan (spasi dihilangkan) = " << endl;
    BubbleSort_136(ArrayKalimat_136, PanjangKalimat_136); 
    TampilkanHurufKalimat_136(ArrayKalimat_136, PanjangKalimat_136); 
    cout << endl;

    //User menginputkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari = ";
    cin >> HurufYangDicari_136; 

    BinarySearch_136(ArrayKalimat_136, PanjangKalimat_136, HurufYangDicari_136);

    return 0;
}
```

#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan08/Un%20SEARCHING.PNG)

Pengguna dapat mencari huruf tertentu dalam kalimat dengan aplikasi ini, Fitur Utama:
1. Menghapus spasi: Program ini menangani kalimat yang memiliki spasi di tengahnya. Untuk meningkatkan efisiensi, kalimat diurutkan sebelum pencarian.
2. Binary search: Algoritma pencarian biner digunakan untuk mempercepat pencarian huruf.
3. Pesan yang jelas: Untuk setiap langkah, program menampilkan pesan yang jelas kepada pengguna.

Langkah-langkahnya:

1. Membaca kalimat dari pengguna: Pengguna memasukkan kalimat yang ingin dianalisis.
2. Menghapus spasi dari kalimat: Spasi dihilangkan dari kalimat untuk mempermudah proses pencarian.
3. Menghitung panjang kalimat: Panjang kalimat tanpa spasi dihitung.
4. Membuat array untuk menyimpan huruf: Array dibuat dengan panjang yang sama dengan panjang kalimat tanpa spasi. Setiap karakter dari kalimat tanpa spasi disalin ke dalam array.
5. Menampilkan huruf dalam kalimat (sebelum diurutkan): Setiap huruf dalam array dicetak ke layar.
6. Mengurutkan huruf dalam kalimat (menggunakan bubble sort): Algoritma bubble sort digunakan untuk mengurutkan huruf dalam array.
7. Menampilkan huruf dalam kalimat (setelah diurutkan): Setiap huruf dalam array yang telah diurutkan dicetak ke layar.
8. Membaca huruf yang ingin dicari: Pengguna memasukkan huruf yang ingin dicari dalam kalimat.
9. Mencari huruf menggunakan binary search: Algoritma binary search digunakan untuk mencari huruf yang diberikan dalam array yang telah diurutkan.
10. Menampilkan hasil pencarian: Jika huruf ditemukan, program akan menampilkan indeksnya dalam kalimat. Jika huruf tidak ditemukan, program akan menampilkan pesan bahwa huruf tersebut tidak ditemukan.
    

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
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan08/Un%20SEARCHING2.PNG)

Program ini menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna.

Langkah-langkah:

1. Membaca kalimat dari pengguna: Pengguna memasukkan kalimat yang ingin dianalisis.
2. Membuat fungsi isVowel:
   - Fungsi ini menerima karakter sebagai input.</br>
   - Mengubah karakter menjadi huruf kecil menggunakan tolower.</br>
   - Memeriksa apakah karakter tersebut termasuk dalam vokal ('a', 'e', 'i', 'o', 'u').</br>
   - Mengembalikan true jika karakter adalah vokal, dan false jika bukan.</br>
3. Membuat fungsi countVowels:
   - Fungsi ini menerima string sebagai input.</br>
   - Inisialisasi variabel Count dengan 0.</br>
   - Mengulangi setiap karakter dalam string.</br>
   - Mengembalikan nilai Count (jumlah vokal).</br>
4. Fungsi main:
   - Menampilkan pesan selamat datang.</br>
   - Membaca kalimat dari pengguna menggunakan getline.</br>
   - Memanggil fungsi countVowels untuk menghitung jumlah vokal dalam kalimat.</br>
   - Menampilkan hasil perhitungan (jumlah vokal) ke pengguna.</br>

Fitur Utama:
1. Fungsi isVowel: Memisahkan logika pengecekan vokal menjadi fungsi terpisah, sehingga mudah digunakan kembali.
2. Penggunaan loop for-each: Mempermudah iterasi melalui karakter dalam string.
3. Pesan yang jelas: Program menampilkan pesan yang informatif kepada pengguna.
   

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
```

#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan08/Un%20SEARCHING3.PNG)

Program ini menghitung berapa kali angka 4 muncul dalam sebuah array.

Langkah-langkah:

1. Mendefinisikan variabel:
   - n 136: Ukuran array (10).</br>
   - Data_136: Array bilangan bulat dengan panjang n_136.</br>
   - Target_136: Angka yang ingin dicari (4).</br>
   - Count_136: Penghitung kemunculan angka 4.</br>
2. Melakukan pencarian sequential:
   - Perulangan for iterasi melalui setiap elemen dalam array Data_136.</br>
3. Menampilkan hasil:
   - Cetak pesan selamat datang.</br>
   - Cetak array Data_136.</br>
   - Cetak informasi tentang berapa kali angka Target_136 ditemukan.</br>

Fitur Utama:
1. Pencarian sequential: Algoritma pencarian sederhana yang memeriksa setiap elemen dalam array secara berurutan.
2. Loop for: Digunakan untuk mengulangi elemen array secara efisien.
3. Pesan yang jelas: Program menampilkan informasi yang mudah dipahami kepada pengguna.

## Kesimpulan
Hasil dari praktikum struktur data dan algoritma mencakup beberapa algoritma pencarian yang digunakan untuk menemukan nilai tertentu dalam kumpulan data. Dua algoritma pencarian yang dibahas dalam praktikum ini adalah pencarian sequential dan pencarian binar. Pencarian sequential adalah algoritma yang paling umum digunakan untuk data yang tidak terurut. Indeks pertama adalah titik awal dari proses pencarian, yang berlanjut hingga indeks terakhir. Jika data ditemukan, proses pencarian berhenti jika setiap elemen array dibandingkan dengan nilai yang dicari. Jika data tidak ditemukan, proses pencarian juga berhenti.

Sebaliknya, pencarian biner adalah algoritma yang digunakan untuk data terurut. Proses pencarian dimulai dengan membagi data menjadi dua bagian dan menemukan nilai tengahnya. Setelah data yang ditemukan dibandingkan dengan nilai tengah, proses dilanjutkan dengan membagi bagian yang sesuai. Sampai data ditemukan atau tidak ditemukan, proses berhenti. Selain itu, contoh implementasi kedua algoritma ini disajikan dalam praktikum. Menggunakan for loop untuk membandingkan setiap elemen array dengan nilai yang dicari, sedangkan binary search membagi data menjadi dua bagian dan mencari nilai tengahnya.

Kesimpulannya, praktikum struktur data dan algoritma menunjukkan bahwa ada banyak algoritma yang dapat digunakan untuk melakukan pencarian data yang sesuai dengan struktur data dan persyaratan aplikasi.




## Referensi
 [1] (https://p3m.sinus.ac.id/jurnal/index.php/TIKomSiN/article/view/546)

 [2] (https://jurnal.untan.ac.id/index.php/jepin/article/view/68389)
