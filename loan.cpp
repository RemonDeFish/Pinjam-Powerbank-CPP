#include "loan.h"

// Constructor: Menggunakan "initializer list" khas C++ untuk memasukkan objek
Loan::Loan(User u, Powerbank pb, std::string tgl) : user(u), powerbank(pb), tanggalPinjam(tgl) {
}

User Loan::getUser() const {
    return user;
}

Powerbank Loan::getPowerbank() const {
    return powerbank;
}

std::string Loan::getTanggal() const {
    return tanggalPinjam;
}

// Menyatukan teks dari User dan Powerbank
std::string Loan::toString() const {
    return user.getNama() + " (" + user.getNPM() + ") meminjam " + powerbank.getKode() + " pada " + tanggalPinjam;
}