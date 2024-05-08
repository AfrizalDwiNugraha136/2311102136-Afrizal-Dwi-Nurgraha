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

        cout << "[2138] Apakah Anda ingin mencoba kalimat lain? (y/n) : "; // Menanyakan Kepada user apakah ingin mencoba kalimat lain atau tidak
        cin >> LanjutkanInputKalimat_136;
        cin.ignore(); // Untuk membersihkan Kalimat_138 buffer sebelumnya
    } while (LanjutkanInputKalimat_136 == 'y' || LanjutkanInputKalimat_136 == 'Y'); // Untuk melanjutkan input Kalimat_138 atau selesai

    return 0;
}