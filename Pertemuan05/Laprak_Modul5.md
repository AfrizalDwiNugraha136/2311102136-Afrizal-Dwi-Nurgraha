# <h1 align="center">Laporan Praktikum HASH TABLE</h1>
# <p align="center">Afrizal Dwi Nugraha-2311102136 </p>

## Dasar Teori

hash table adalah  struktur data yang terdiri dari tabel dan fungsi yang bertujuan untuk memetakan nilai kunci unik  setiap record (baris) ke nomor (hash) untuk posisi record  dalam  tabel. Kelebihan dari struktur table hash  ini adalah waktu pengambilannya yang cukup cepat, jika record yang dicari letaknya tepat pada nomor hash lokasi penyimpanan. Karena pemetaan hash  yang digunakan bukan pemetaan satu-ke-satu (antara dua record berbeda yang  dapat menghasilkan nomor hash yang sama), maka dapat terjadi konflik saat menempatkan record data. diperlukan untuk menerapkan kebijakan resolusi konflik. Kebijakan) untuk menentukan lokasi record dalam tabel. Biasanya kebijakan penyelesaian konflik adalah dengan mencari  tabel  kosong di lokasi setelah lokasi konflik.

hash table menggunakan struktur data array asosiatif yang mengaitkan catatan dengan bidang kunci unik sebagai angka (hash) yang merupakan representasi catatan. Misalnya, Anda ingin menyimpan data sebagai string  dalam tabel hash. String  direpresentasikan dalam bidang kunci k. Ada berbagai cara untuk mendapatkan bidang kunci ini, namun hasil akhirnya adalah nomor hash yang digunakan untuk menemukan rekaman . Nomor hash ini dimasukkan ke dalam fungsi hash  dan membuat indeks lokasi rekaman yang dicatat dalam tabel. Fungsi generator bidang kunci k(x)  (1) Fungsi hash h(x)  (2) 

## Guided 

### 1. Guided 1 

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```
Kode C++ ini mengimplementasikan tabel hash dasar dengan fungsi  penyisipan, pencarian, penghapusan, dan traversal. Berikut detail kodenya: 

- hash_func: Fungsi ini menghitung nilai hash untuk kunci tertentu menggunakan operator modulo.</br>
- Node: Struktur ini mewakili sebuah node dalam tabel hash. Ini berisi pasangan nilai kunci dan penunjuk ke node berikutnya.</br>
- HashTable: Kelas ini mewakili tabel hash. Ini berisi array pointer Node.</br>
- insert: Masukkan pasangan nilai kunci ke dalam tabel hash. Jika kunci sudah ada,  nilai terkait akan diperbarui.</br>
- get: Mendapatkan nilai yang terkait dengan kunci yang ditentukan dari tabel hash.</br>
- remove: Menghapus pasangan nilai kunci yang terkait dengan kunci tertentu dari tabel hash.</br>
- traverse : Cetak semua pasangan nilai kunci di tabel hash.</br>
- main: Fungsi main mendemonstrasikan cara menggunakan tabel hash dengan menyisipkan beberapa pasangan nilai kunci, mencari nilai, mencoba menghapus pasangan nilai kunci, dan menelusuri tabel hash.</br>

### 2. Guided 2

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```
Kode C++ ini mengimplementasikan peta hash sederhana untuk menyimpan nama karyawan dan nomor telepon terkait. Mari kita uraikan kodenya: 

- HashNodeclass: Mewakili sebuah node di peta hash. Setiap node berisi nama dan nomor telepon.</br>
- HashMapclass: Mengimplementasikan fungsionalitas peta hash.</br>
- hashFunc: Hitung nilai hash untuk kunci tertentu (nama karyawan) menggunakan metode penambahan nilai ASCII sederhana.</br>
- insert: Masukkan pasangan nilai kunci baru ke dalam peta hash. Jika kunci sudah ada,  nilai terkait akan diperbarui.</br>
- remove: Menghapus pasangan nilai kunci dari peta hash berdasarkan kunci yang diberikan.</br>
- searchByName: Mencari kunci (nama karyawan) dan mengembalikan nilai yang sesuai (nomor telepon).</br>
- print: Cetak isi peta hash.</br>
- Fungsi utama : mendemonstrasikan penggunaan peta hash dengan menyisipkan beberapa pasangan nilai kunci, mencari nilai, menghapus pasangan nilai kunci, dan mencetak peta hash.</br>

## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : a. Setiap mahasiswa memiliki NIM dan nilai. b. Program memiliki tampilan pilihan menu berisi poin C. c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Struktur data untuk setiap node
struct Node {
    string NIM;
    string nama;
    int nilai;
    Node* next;
    Node(string NIM, string nama, int nilai) : NIM(NIM), nama(nama), nilai(nilai), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;

public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Fungsi hash sederhana
    int hash_func(string NIM) {
        int sum = 0;
        for (char c : NIM) {
            sum += c;
        }
        return sum % MAX_SIZE;
    }

    // Insertion
    void insert(string NIM, string nama, int nilai) {
        int index = hash_func(NIM);
        Node* newNode = new Node(NIM, nama, nilai);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Deletion
    void remove(string NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->NIM == NIM) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Data not found for NIM: " << NIM << endl;
    }

    // Searching by NIM
    void searchByNIM(string NIM) {
        int index = hash_func(NIM);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->NIM == NIM) {
                cout << "Data found - NIM: " << current->NIM << ", Nama: " << current->nama << ", Nilai: " << current->nilai << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data not found for NIM: " << NIM << endl;
    }

    // Searching by range of values (80-90)
    void searchByRange() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                if (current->nilai >= 80 && current->nilai <= 90) {
                    cout << "NIM: " << current->NIM << ", Nama: " << current->nama << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }

    // Menampilkan semua data mahasiswa
    void displayAllData() {
        cout << "Data Mahasiswa:\n";
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << "NIM: " << current->NIM << ", Nama: " << current->nama << ", Nilai: " << current->nilai << endl;
                current = current->next;
            }
        }
    }

    // Menampilkan menu pilihan
    void displayMenu() {
        cout << "Menu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari berdasarkan NIM\n";
        cout << "4. Cari berdasarkan rentang nilai (80-90)\n";
        cout << "5. Tampilkan data mahasiswa\n";
        cout << "6. Keluar\n";
    }
};

int main() {
    HashTable hashTable;

    int choice;
    string NIM, nama;
    int nilai;

    do {
        hashTable.displayMenu();
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan Nama: ";
                cin >> nama;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                hashTable.insert(NIM, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> NIM;
                hashTable.remove(NIM);
                break;
            case 3:
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> NIM;
                hashTable.searchByNIM(NIM);
                break;
            case 4:
                cout << "Data dengan nilai antara 80-90:\n";
                hashTable.searchByRange();
                break;
            case 5:
                hashTable.displayAllData();
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang benar.\n";
        }
    } while (choice != 6);
    
return 0;
}
```

#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/Pertemuan01/Unguided%201%20tipe%20data.PNG?raw=true)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.   

## Kesimpulan
Hash Table adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai.
Hash Table terdiri dari dua komponen utama: array (atau vektor) dan fungsi hash.
Hashing adalah teknik untuk mengubah nilai kunci menjadi rentang indeks array.
Fungsi hash digunakan untuk menghasilkan nilai unik dari setiap data item, yang digunakan sebagai array indeks. Setiap ember dapat menampung satu atau beberapa data item.
Ketika data perlu dicari, masukan kunci dijadikan sebagai parameter untuk fungsi hash, dan indeks posisi array yang dihasilkan digunakan untuk mencari data.
Dalam kasus tabrakan hash, di mana dua atau lebih data memiliki nilai hash yang sama, tabel hash menyimpan data tersebut dalam slot yang sama dengan Teknik yang disebut chaining.
Praktikum Struktur Data dan Algoritma mencakup pengertian, dasar teori, dan operasi tabel hash, serta contoh penggunaan tabel hash dalam pemrograman.

## Referensi
[1] (https://elektro.um.ac.id/wp-content/uploads/2016/04/Struktur-Data-Modul-Praktikum-11-Hashing-Table.pdf)
