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

