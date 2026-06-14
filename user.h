#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string nama;
    std::string NPM;

public:
    // Constructor
    User(std::string nama, std::string NPM);

    // Getter
    std::string getNama() const;
    std::string getNPM() const;

    // toString equivalent
    std::string toString() const;
};

#endif // USER_H