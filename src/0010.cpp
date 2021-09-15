#include <iostream>
#include <vector>
#include "numtheory.h"

const int N = 2000000;

int main() {
    std::vector<long long> primes = nbt::eratosthenes(N);
    long long result = 0;
    for (long long prime : primes)
        result += prime;
    std::cout << result << std::endl;
}