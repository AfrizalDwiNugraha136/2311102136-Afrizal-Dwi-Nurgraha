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