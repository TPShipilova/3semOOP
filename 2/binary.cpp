#include "Binary.h"
#include <iostream>

Binary::Binary(int len) {
    if (len <= 0) {
        throw std::invalid_argument("Length should be positive");
    }
    length = len;
    data = new unsigned char[(length + 7) / 8];
    for (int i = 0; i < (length + 7) / 8; i++) {
        data[i] = 0;
    }
}

Binary::Binary(const Binary& other) {
    length = other.length;
    data = new unsigned char[(length + 7) / 8];
    for (int i = 0; i < (length + 7) / 8; i++) {
        data[i] = other.data[i];
    }
}

Binary::~Binary() {
    delete[] data;
}

void Binary::setBit(int pos, bool value) {
    if (pos < 0 || pos >= length) {
        throw std::out_of_range("Position is out of range");
    }
    int bytePos = pos / 8;
    int bitPos = pos % 8;
    if (value) {
        data[bytePos] |= (1 << bitPos);
    } else {
        data[bytePos] &= ~(1 << bitPos);
    }
}

bool Binary::getBit(int pos) const {
    if (pos < 0 || pos >= length) {
        throw std::out_of_range("Position is out of range");
    }
    int bytePos = pos / 8;
    int bitPos = pos % 8;
    return (data[bytePos] & (1 << bitPos)) != 0;
}

bool Binary::operator==(const Binary& other) const {
    if (length != other.length) {
        return false;
    }
    for (int i = 0; i < (length + 7) / 8; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool Binary::operator!=(const Binary& other) const {
    return !(*this == other);
}

bool Binary::operator<(const Binary& other) const {
    if (length != other.length) {
        throw std::invalid_argument("Lengths should be equal");
    }
    for (int i = length - 1; i >= 0; i--) {
        if (getBit(i) < other.getBit(i)) {
            return true;
        } else if (getBit(i) > other.getBit(i)) {
            return false;
        }
    }
    return false;
}

bool Binary::operator>(const Binary& other) const {
    if (length != other.length) {
        throw std::invalid_argument("Lengths should be equal");
    }
    for (int i = length - 1; i >= 0; i--) {
        if (getBit(i) > other.getBit(i)) {
            return true;
        } else if (getBit(i) < other.getBit(i)) {
            return false;
        }
    }
    return false;
}

Binary Binary::operator+(const Binary& other) const {
    if (length != other.length) {
        throw std::invalid_argument("Lengths should be equal");
    }
    Binary result(length);
    bool carry = false;
    for (int i = 0; i < length; i++) {
        bool sum = getBit(i) ^ other.getBit(i) ^ carry;
        carry = (getBit(i) && other.getBit(i)) || (getBit(i) && carry) || (other.getBit(i) && carry);
        result.setBit(i, sum);
    }
    return result;
}

Binary Binary::operator-(const Binary& other) const {
    if (length != other.length) {
        throw std::invalid_argument("Lengths should be equal");
    }
    for (int i = length - 1; i >= 0; i--) { 
        if (getBit(i) < other.getBit(i)) { 
            throw std::invalid_argument("Cannot subtract from a smaller number"); 
        } else
        if (getBit(i) > other.getBit(i)) { 
            break; 
        } 
    } 
    Binary result(length);
    bool borrow = false;
    for (int i = 0; i < length; i++) {
        bool diff = getBit(i) ^ other.getBit(i) ^ borrow;
        borrow = (!getBit(i) && other.getBit(i)) || ((!getBit(i) || other.getBit(i)) && borrow);
        result.setBit(i, diff);
    }
    return result;
}

Binary& Binary::operator=(const Binary& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new unsigned char[(length + 7) / 8];
        for (int i = 0; i < (length + 7) / 8; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}


