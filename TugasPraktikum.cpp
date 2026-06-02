#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include <exception>

using namespace std;

// ===================== CLASS TOKO ELEKTRONIK =====================
class TokoElektronik {
private:
    array<string, 3> etalase; // enkapsulasi (max 3 barang)

public:
    // constructor (data awal otomatis)
    TokoElektronik() {
        etalase = {"TV Samsung", "Laptop ASUS", "Kulkas LG"};
    }

    // method ambil produk (exception handling)
    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (out_of_range& e) {
            throw runtime_error(
                "Gagal Mengambil Barang : Rak nomor " + to_string(nomorRak) +
                " kosong atau tidak tersedia!"
            );
        }
    }
};

// ===================== FILE FUNCTIONS (CRUD) =====================
const string FILE_NAME = "gudang.txt";

// CREATE
void tambahBarang() {
    ofstream file(FILE_NAME, ios::app);
    string nama;

    cout << "Masukkan nama barang: ";
    cin.ignore();
    getline(cin, nama);

    file << nama << endl;
    file.close();

    cout << "Barang berhasil ditambahkan!\n";
}

// READ
void tampilkanBarang() {
    ifstream file(FILE_NAME);
    string baris;
    int i = 0;

    cout << "\n=== DAFTAR BARANG GUDANG ===\n";

    if (!file.is_open()) {
        cout << "File tidak ditemukan!\n";
        return;
    }

    while (getline(file, baris)) {
        cout << i++ << ". " << baris << endl;
    }

    file.close();
}

// UPDATE
void updateBarang() {
    ifstream file(FILE_NAME);
    vector<string> data;
    string baris;
    int index;
    string baru;

    while (getline(file, baris)) {
        data.push_back(baris);
    }
    file.close();

    tampilkanBarang();

    cout << "Masukkan indeks barang yang ingin diubah: ";
    cin >> index;

    if (index < 0 || index >= data.size()) {
        cout << "Index tidak valid!\n";
        return;
    }

    cin.ignore();
    cout << "Masukkan nama baru: ";
    getline(cin, baru);

    data[index] = baru;

    ofstream out(FILE_NAME);
    for (auto& d : data) {
        out << d << endl;
    }

    out.close();
    cout << "Data berhasil diupdate!\n";
}

// DELETE
void hapusBarang() {
    ifstream file(FILE_NAME);
    vector<string> data;
    string baris;
    int index;

    while (getline(file, baris)) {
        data.push_back(baris);
    }
    file.close();

    tampilkanBarang();

    cout << "Masukkan indeks barang yang ingin dihapus: ";
    cin >> index;

    if (index < 0 || index >= data.size()) {
        cout << "Index tidak valid!\n";
        return;
    }

    data.erase(data.begin() + index);

    ofstream out(FILE_NAME);
    for (auto& d : data) {
        out << d << endl;
    }

    out.close();
    cout << "Data berhasil dihapus!\n";
}

// ===================== SIMULASI ETALASE =====================
void simulasiEtalase() {
    TokoElektronik toko;

    cout << "\n=== SIMULASI ETALASE ===\n";

    // Skenario 1 (sukses)
    try {
        cout << "Rak 1: " << toko.ambilProduk(1) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    // Skenario 2 (error)
    try {
        cout << "Rak 5: " << toko.ambilProduk(5) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

// ===================== MAIN MENU =====================
int main() {
    int pilihan;

    do {
        cout << "\n===== TOKO ELEKTRONIK GIBRAN JAYA =====\n";
        cout << "1. Tambah Barang (Create)\n";
        cout << "2. Lihat Barang (Read)\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang (Delete)\n";
        cout << "5. Simulasi Etalase (Exception Handling)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahBarang();
            break;
        case 2:
            tampilkanBarang();
            break;
        case 3:
            updateBarang();
            break;
        case 4:
            hapusBarang();
            break;
        case 5:
            simulasiEtalase();
            break;
        case 0:
            cout << "Keluar program...\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}