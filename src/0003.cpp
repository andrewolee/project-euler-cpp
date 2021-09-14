#include <iostream>
#include "numtheory.h"

int main() {
    std::vector<int> primes = eratosthenes(100);
    for (int prime : primes)
        std::cout << prime << ", ";
    std::cout << std::endl;
}