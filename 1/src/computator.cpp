#include <iostream>

int count_cuts (int m, int n){
    int ans;
    if (m * n != 1)
       ans = n - 1 + n * (m - 1);
    else
    if (m <= 0 || n <= 0)
       ans = -1;
    else
       ans = 0;
    return ans;
}