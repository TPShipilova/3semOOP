#include <iostream>
#include "Binary.h"

int main() {
    Binary b1(8); //10101010
    b1.setBit(0, '1');
    b1.setBit(1, '0');
    b1.setBit(2, '1');
    b1.setBit(3, '0');
    b1.setBit(4, '1');
    b1.setBit(5, '0');
    b1.setBit(6, '1');
    b1.setBit(7, '0');

    Binary b2 = b1;
    std::cout << "b1: ";
    for (int i = 0; i < 8; i++) {
        std::cout << b1.getBit(i);
    }
    std::cout << std::endl;

    std::cout << "b2: ";
    for (int i = 0; i < 8; i++) {
        std::cout << b2.getBit(i);
    }
    std::cout << std::endl;

    Binary b3(8); 
    b3.setBit(0, '1');
    b3.setBit(1, '1');
    b3.setBit(2, '0');
    b3.setBit(3, '0');
    b3.setBit(4, '1');
    b3.setBit(5, '1');
    b3.setBit(6, '0');
    b3.setBit(7, '0');

    Binary b4 = b1 + b3;
    std::cout << "b4: ";
    for (int i = 0; i < 8; i++) {
        std::cout << b4.getBit(i);
    }
    std::cout << std::endl;

    Binary b5 = b1 - b3;
    std::cout << "b5: ";
    for (int i = 0; i < 8; i++) {
        std::cout << b5.getBit(i);
    }
    std::cout << std::endl;

    if (b1 == b2) {
        std::cout << "b1 and b2 are equal" << std::endl;
    }
    else {
        std::cout << "b1 and b2 are not equal" << std::endl;
    }

    if (b1 < b3) {
        std::cout << "b1 is less than b3" << std::endl;
    }
    else {
        std::cout << "b1 is not less than b3" << std::endl;
    }

    return 0;
} 