#include "numtheory.h"

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int pow(int a, int b) {
    int n = 1;
    while (b) {
        if (b & 1)
            n *= a;
        a *= a;
        b = b >> 1;
    }
    return n;
}

int mod_pow(int a, int b, int m) {
    int n = 1;
    while (b) {
        if (b & 1)
            n *= a % m;
        a *= a;
        b = b >> 1;
    }
    return n % m;
}

std::vector<int> eratosthenes(int n) {
    bool sieve[n + 1];
    memset(sieve, true, sizeof(sieve));
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (sieve[i])
            primes.push_back(i);
    }
    return primes;
}