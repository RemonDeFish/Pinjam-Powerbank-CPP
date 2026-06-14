#ifndef LOAN_H
#define LOAN_H

#include "user.h"
#include "powerbank.h"
#include <string>

class Loan {
private:
    User user;
    Powerbank powerbank;
    std::string tanggalPinjam;

public:
    // Constructor
    Loan(User u, Powerbank pb, std::string tgl);

    // Getter
    User getUser() const;
    Powerbank getPowerbank() const;
    std::string getTanggal() const;

    // Fungsi untuk menggabungkan info pinjaman jadi satu baris teks
    std::string toString() const;
};

#endif // LOAN_H