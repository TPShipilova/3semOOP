#include <iostream>
#include "computator.h"

int main(){
    int n, m;
    std::cin >> n >> m;
    
    int cuts_quantity = count_cuts(m, n);
    if (cuts_quantity != -1)
       std::cout << "Количество разрезов равно: "<< cuts_quantity << std::endl;
    else
       std::cout << "Входные данные не допустимы "<< std::endl;
}