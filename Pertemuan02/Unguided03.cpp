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
