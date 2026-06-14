#ifndef LOANMANAGER_H
#define LOANMANAGER_H

#include "loan.h"
#include <QObject>
#include <QString>
#include <vector>

class LoanManager : public QObject
{
    Q_OBJECT
private:
    std::vector<Loan> daftarPinjaman;

public:
    explicit LoanManager(QObject *parent = nullptr);

    // Fungsi ini akan dipanggil saat tombol di QML diklik
    Q_INVOKABLE QString tambahPinjaman(QString nama, QString npm, QString kodePB);
};

#endif // LOANMANAGER_H