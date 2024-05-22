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