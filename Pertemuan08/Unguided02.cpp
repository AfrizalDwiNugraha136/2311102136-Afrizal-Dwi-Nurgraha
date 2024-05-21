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