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
