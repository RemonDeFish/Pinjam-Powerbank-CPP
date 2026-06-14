#include "powerbank.h"

// Constructor: Mengisi nilai awal saat objek Powerbank dibuat
Powerbank::Powerbank(std::string kode, int kapasitas) {
    this->kode = kode;
    this->kapasitas = kapasitas;
}

// Mengambil nilai Kode
std::string Powerbank::getKode() const {
    return kode;
}

// Mengambil nilai Kapasitas
int Powerbank::getKapasitas() const {
    return kapasitas;
}

// Menggabungkan data menjadi teks utuh
std::string Powerbank::toString() const {
    return "Powerbank: " + kode + " - " + std::to_string(kapasitas) + " mAh";
}