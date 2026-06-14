#include "user.h"

// Constructor: Mengisi nilai awal saat objek User dibuat
User::User(std::string nama, std::string NPM) {
    this->nama = nama;
    this->NPM = NPM;
}

// Mengambil nilai Nama
std::string User::getNama() const {
    return nama;
}

// Mengambil nilai NPM
std::string User::getNPM() const {
    return NPM;
}

// Menggabungkan data menjadi satu teks utuh (seperti di Java)
std::string User::toString() const {
    return "User: " + nama + " (" + NPM + ")";
}