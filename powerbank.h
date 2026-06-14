#ifndef POWERBANK_H
#define POWERBANK_H

#include <string>

class Powerbank {
private:
    std::string kode;
    int kapasitas;

public:
    // Constructor
    Powerbank(std::string kode, int kapasitas);

    // Getter
    std::string getKode() const;
    int getKapasitas() const;

    // toString equivalent
    std::string toString() const;
};

#endif // POWERBANK_H