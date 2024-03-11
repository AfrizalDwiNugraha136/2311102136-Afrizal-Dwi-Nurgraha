#include <iostream>

// Fungsi untuk menghitung rata-rata dari sejumlah nilai
float hitungRataRata(int jumlahNilai) {
    int total = 0;
    int nilai;

    for (int i = 0; i < jumlahNilai; i++) {
        std::cout << "Masukkan nilai ke-" << i + 1 << ": ";
        std::cin >> nilai;
        total += nilai;
    }

    return static_cast<float>(total) / jumlahNilai;
}

// Fungsi utama
int main() {
    int jumlahNilai;

    std::cout << "Program Menghitung Rata-Rata Nilai\n";
    std::cout << "---------------------------------\n";

    // Input jumlah nilai dari pengguna
    std::cout << "Masukkan jumlah nilai: ";
    std::cin >> jumlahNilai;

    // Memanggil fungsi hitungRataRata dan menampilkan hasil
    float rataRata = hitungRataRata(jumlahNilai);
    std::cout << "Rata-rata nilai adalah: " << rataRata << std::endl;

    return 0;
}
