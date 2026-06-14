#include "loanmanager.h"
#include <QDateTime> // Pustaka internal Qt untuk waktu

LoanManager::LoanManager(QObject *parent) : QObject(parent)
{
}

QString LoanManager::tambahPinjaman(QString nama, QString npm, QString kodePB)
{
    // 1. Konversi dari QString ke std::string untuk kelas C++ murni kita
    std::string stdNama = nama.toStdString();
    std::string stdNpm = npm.toStdString();
    std::string stdKodePB = kodePB.toStdString();

    // 2. Ambil waktu saat ini secara otomatis
    QString waktuSekarang = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");
    std::string stdWaktu = waktuSekarang.toStdString();

    // 3. Buat objek User dan Powerbank
    User userBaru(stdNama, stdNpm);

    // Asumsi kapasitas berdasarkan kode powerbank yang dipilih
    int kapasitas = (kodePB.contains("20000")) ? 20000 : 10000;
    Powerbank pbBaru(stdKodePB, kapasitas);

    // 4. Buat objek Loan dan masukkan ke dalam vector (ArrayList-nya C++)
    Loan pinjamanBaru(userBaru, pbBaru, stdWaktu);
    daftarPinjaman.push_back(pinjamanBaru);

    // 5. Kembalikan teks status ke QML untuk ditampilkan di layar
    return QString::fromStdString(pinjamanBaru.toString());
}