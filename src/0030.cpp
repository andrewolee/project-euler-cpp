#include <iostream>
#include "numtheory.h"

int main() {
    int fifths[10];
    for (int i = 0; i < 10; i++) {
        fifths[i] = nbt::pow(i, 5);
    }
    int result = 0;
    for (int n = 2; n < 1000000; n++) {
        int m = n;
        int sum = 0;
        while(m) {
            sum += fifths[m % 10];
            m /= 10;
            if (sum > n)
                break;
        }
        if (sum == n)
            result += n;
    }

    std::cout << result << std::endl;
}