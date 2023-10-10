#pragma once

#include <iostream>
#include <stdexcept>

class Binary {
private:
    unsigned char* data;
    int length;
public:
    Binary(int len);
    Binary(const Binary& other);
    ~Binary();
    void setBit(int pos, bool value);
    bool getBit(int pos) const;
    Binary operator+(const Binary& other) const;
    Binary operator-(const Binary& other) const;
    Binary& operator=(const Binary& other);
    bool operator==(const Binary& other) const;
    bool operator!=(const Binary& other) const;
    bool operator<(const Binary& other) const;
    bool operator>(const Binary& other) const;
    
};