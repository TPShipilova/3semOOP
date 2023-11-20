#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include <initializer_list>

class Binary {
public:
    Binary();
    Binary (const std::initializer_list<unsigned char> & t);
    Binary (const std::string & t);
    Binary (const Binary &other);
    Binary (Binary &&other) noexcept;
    Binary(const size_t &n, unsigned char t);

    Binary& operator = (const Binary& other);
    Binary& operator = (Binary&& other) noexcept;

    bool operator == (const Binary & t) const;
    bool operator > (const Binary &other) const;
    bool operator < (const Binary &other) const;
    Binary operator + (const Binary & t) const;
    Binary operator - (const Binary & t) const;

    virtual ~Binary() noexcept;

    friend std::ostream& operator << (std::ostream& os, const Binary& number);

private:
    size_t _size;
    unsigned char* _array;
    void copyDigits(const unsigned char* otherDigits, size_t otherSize);
};
