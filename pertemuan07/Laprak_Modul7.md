# <h1 align="center">LAPORAN PRAKTIKUM MODUL 7 : QUEUE</h1>
<p align="center">AFRIZAL DWI NUGRAHA - 2311102136</p>

# Dasar Teori

## A. PENGERTIAN QUEUE
Queue adalah struktur data linier yang beroperasi berdasarkan prinsip FIFO (First In, First Out). Daftar terhubung digunakan untuk menjalankan queue, di mana setiap node memiliki nilai dan penunjuk ke node berikutnya linked list. Artinya, elemen pertama yang ditambahkan ke queue adalah elemen pertama yang dihapus. Kelangkaan depan menunjukkan elemen pertama, dan kelangkaan belakang menunjukkan elemen terakhir. Operasi queue termasuk menambah elemen (enqueue), mengeluarkan elemen (dequeue), dan mengetahui apakah queue kosong atau tidak. Untuk menjaga urutan dan aksesibilitas elemen yang benar, implementasi queue melibatkan pengelolaan node dan pointer ini. queue biasanya digunakan dengan kelas, yang memiliki metode untuk menambah dan menghapus elemen serta memeriksa kekosongan. Anggota data untuk bagian depan dan belakang antrian, serta penunjuk ke node saat ini, termasuk dalam kelas ini. Untuk menggunakan banyak aplikasi seperti penjadwalan pekerjaan, protokol jaringan, dan sistem lain yang memerlukan komponen pemrosesan dalam urutan tertentu, queueing sangat penting.  

## Guided 

### 1. [Program Operasi QUEUE]

```C++
#include <iostream>
using namespace std;
const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan
bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

## Unguided 

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list.]

```C++
// LAPRAK 7 : UNGUIDED 1
// AFRIZAL DWI NUGRAHA
// 2311102136
// S1 IF-11-D

#include <iostream>
using namespace std;

// Mendefinisikan node untuk linked list
struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front; // Pointer ke depan antrian
    Node* rear;  // Pointer ke belakang antrian
    int size;    // Ukuran antrian

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Fungsi untuk menambahkan elemen ke belakang antrian
    void enqueueAntrian(string data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        
        // Jika antrian kosong
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Fungsi untuk menghapus elemen dari depan antrian
    void dequeueAntrian() {
        // Jika antrian kosong
        if (front == nullptr) {
            cout << "Antrian kosong" << endl;
            return;
        }
        
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    // Fungsi untuk menampilkan seluruh elemen antrian
    void viewQueue() {
        if (front == nullptr) {
            cout << "Antrian kosong" << endl;
            return;
        }
        
        cout << "Data antrian teller:" << endl;
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Fungsi untuk menghitung jumlah elemen dalam antrian
    int countQueue() {
        return size;
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clearQueue() {
        while (front != nullptr) {
            dequeueAntrian();
        }
    }

    // Destruktor untuk menghapus seluruh elemen pada akhir program
    ~Queue() {
        clearQueue();
    }
};

int main() {
    Queue antrian;
    antrian.enqueueAntrian("Andi");
    antrian.enqueueAntrian("Maya");
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.dequeueAntrian();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.clearQueue();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    return 0;
}


```
#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/pertemuan07/Un%20QUEUE.PNG)

Ini adalah ringkasan singkat dari fungsinya:

1. Palindrom_136: Fungsi ini menentukan apakah string tertentu adalah palindrom, membersihkan kata_136: Fungsi ini membersihkan string masukan dengan menghapus spasi dan karakter non-alfanumerik serta mengubah semua karakter menjadi huruf kecil. Karakter dari string paruh pertama dan kedua dibandingkan menggunakan tumpukan.

2. Main: Anda berulang kali meminta pengguna memasukkan kalimat atau kata dalam fungsi utama. Selanjutnya, Anda menggunakan BersihkanKata_136 untuk membersihkan input dan menggunakan Palindrom_136 untuk mengetahui apakah itu palindrom. Terakhir, Anda meminta pengguna untuk mencoba input tambahan dan melanjutkan jika mereka memilih untuk melakukannya.

### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]

```C++
// LAPRAK 7 : UNGUIDED 2
// AFRIZAL DWI NUGRAHA
// 2311102136
// S1 IF-11-D

#include <iostream>
using namespace std;

// Struktur Node untuk menyimpan data Mahasiswa dan pointer ke node selanjutnya
struct MahasiswaNode {
    string nama_136;
    string nim_136;
    MahasiswaNode* next;
};

// Kelas Queue menggunakan linked list untuk Mahasiswa
class MahasiswaQueue {
private:
    MahasiswaNode* front; // Node pertama dalam queue
    MahasiswaNode* back;  // Node terakhir dalam queue
public:
    MahasiswaQueue() {
        front = nullptr;
        back = nullptr;
    }

    // Fungsi untuk mengecek apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Fungsi untuk menambahkan data Mahasiswa ke dalam queue
    void enqueue(string nama_136, string nim_136) {
        MahasiswaNode* newNode = new MahasiswaNode(); // Membuat node baru
        newNode->nama_136 = nama_136;
        newNode->nim_136 = nim_136;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    // Fungsi untuk menghapus data Mahasiswa dari queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        MahasiswaNode* temp = front;
        front = front->next;
        delete temp;
    }

    // Fungsi untuk melihat data Mahasiswa yang ada di queue
    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        cout << "Data antrian mahasiswa:" << endl;
        MahasiswaNode* current = front;
        int position = 1;
        while (current != nullptr) {
            cout << position << ". Nama: " << current->nama_136 << ", NIM: " << current->nim_136 << endl;
            current = current->next;
            position++;
        }
    }

    // Fungsi untuk menghitung jumlah data Mahasiswa di queue
    int countQueue() {
        int count = 0;
        MahasiswaNode* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi untuk membersihkan queue
    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    MahasiswaQueue queue; // Membuat objek queue

    char tambahLagi;
    do {
        string nama, nim;
        cout << "Masukkan nama mahasiswa: ";
        getline(cin, nama);
        cout << "Masukkan NIM mahasiswa: ";
        getline(cin, nim);
        queue.enqueue(nama, nim);

        cout << "Apakah ingin menambahkan mahasiswa lagi? (y/n): ";
        cin >> tambahLagi;
        cin.ignore(); // Untuk membersihkan newline di buffer stdin
    } while (tambahLagi == 'y' || tambahLagi == 'Y');

    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}
```

#### Output:
![SS](https://github.com/AfrizalDwiNugraha136/2311102136-Afrizal-Dwi-Nurgraha/blob/main/pertemuan07/Un%20QUEUE2.PNG)

Berikut adalah beberapa kesimpulan singkat:

1.Validasi Input: Meskipun program ini tidak meminta pengguna memasukkan kalimat dengan minimal tiga kata, mungkin ingin menambahkan beberapa validasi untuk memastikan bahwa input memenuhi persyaratan ini.

2.Merawat Baris Baru: Ketika seseorang memasukkan kalimat dan tidak mengetik apa pun, mereka akan menghasilkan string kosong yang sedang diproses. Anda mungkin ingin mengatasi hal ini dengan memeriksa input kosong dan meminta mereka memasukkan kalimat yang benar.

3.Efisiensi: Metode ini sederhana dan efektif untuk input yang lebih kecil. Namun, untuk input yang lebih besar, terutama kalimat dengan banyak karakter, menggunakan tumpukan untuk pembalikan mungkin bukan metode yang paling efektif.  dapat mencoba salah kalimat dengan dua petunjuk atau mengubah string secara langsung.
Bertanya dalam Nama: Nama


## Kesimpulan
Dalam metode FIFO, atau First-In First-Out, di mana data pertama dimasukkan ke dalam antrian akan dikeluarkan dari antrian, antrian adalah struktur data yang digunakan untuk menyimpan data. Ini adalah kesimpulan dari praktikum Struktur data dan algoritma yang membahas antrian. Untuk melaksanakan antrian, Anda dapat menggunakan array atau linked list. Dalam kasus array, antrian terdiri dari dua pointer, depan dan belakang, yang digunakan untuk mengatur operasi, menambah, dan menampilkan data dalam antrian. Dalam antrian, Anda dapat melakukan beberapa operasi, seperti menambahkan data, menghapus data, peek untuk mengambil data tanpa menghapusnya, isEmpty untuk mengetahui apakah antrian kosong atau penuh, size untuk mengetahui jumlah elemen dalam antrian, dan clearQueue untuk menghapus semua data linked list. Contoh implementasi antrian menggunakan array dan linked list, serta contoh penggunaan operasi antrian untuk mengatur antrian teller, diberikan dalam praktikum.  


## Referensi
 [1] https://www.researchgate.net/profile/Steven-Carroll-8/publication/336580303_A_C_Implementation_of_a_Threadsafe_Priority_Queue_Based_on_Multi-Dimensional_Linked_Lists_and_MRLock/links/5da6ff6a92851caa1ba708d9/A-C-Implementation-of-a-Threadsafe-Priority-Queue-Based-on-Multi-Dimensional-Linked-Lists-and-MRLock.pdf

 [2] https://www.researchgate.net/profile/Steven-Carroll-8/publication/337844833_A_C_Implementation_of_a_Lock-Free_Priority_Queue_Based_on_Multi-Dimensional_Linked_List/links/5deed82fa6fdcc2837146d0e/A-C-Implementation-of-a-Lock-Free-Priority-Queue-Based-on-Multi-Dimensional-Linked-List.pdf
