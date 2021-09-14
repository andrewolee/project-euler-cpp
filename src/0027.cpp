#include <iostream>
#include "numtheory.h"

const int N = 1000;

int main() {
    std::vector bs = eratosthenes(N);
    std::unordered_set primes = std::unordered_set(bs.begin(), bs.end());
    int result = 0;
    int max = 0;
    for (int b : bs) {
        for (int a = 2 - b; a < N; a += 2) {
            int n;
            for (n = 0; n < b; n++) {
                if (primes.find(n * n + a * n + b) == primes.end())
                    break;
            }
            if (n > max) {
                max = n;
                result = a * b;
            }
        }
    }
    std::cout << result << std::endl;
}