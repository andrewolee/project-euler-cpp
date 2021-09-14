#include <iostream>
#include <vector>
#include "numtheory.h"

const int N = 2000000;

int main() {
    std::vector<int> primes = eratosthenes(N);
    long result = 0;
    for (int prime : primes)
        result += prime;
    std::cout << result << std::endl;
}