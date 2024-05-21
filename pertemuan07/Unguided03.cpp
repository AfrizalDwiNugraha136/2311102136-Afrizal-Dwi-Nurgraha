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