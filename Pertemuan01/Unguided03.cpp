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
