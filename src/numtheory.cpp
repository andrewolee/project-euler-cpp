#include "numtheory.h"
using namespace nbt;

long long nbt::gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long nbt::lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long nbt::pow(long long a, long long b) {
    long long n = 1;
    while (b) {
        if (b & 1)
            n *= a;
        a *= a;
        b = b >> 1;
    }
    return n;
}

long long nbt::mod_pow(long long a, long long b, long long m) {
    long long n = 1;
    while (b) {
        if (b & 1)
            n *= a % m;
        a *= a;
        b = b >> 1;
    }
    return n % m;
}

long long nbt::isqrt(long long n) {
    long long x = n;
    long long y = 1;
    while (x > y) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

std::vector<long long> nbt::eratosthenes(long long n) {
    bool sieve[n + 1];
    memset(sieve, true, sizeof(sieve));
    for (long long i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (long long j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
    }
    std::vector<long long> primes;
    for (long long i = 2; i <= n; i++) {
        if (sieve[i])
            primes.push_back(i);
    }
    return primes;
}

std::vector<long long> nbt::p_factor(long long n) {
    std::vector<long long> primes = eratosthenes(isqrt(n) + 1);
    return p_factor(n, primes);
}

std::vector<long long> nbt::p_factor(long long n, std::vector<long long> primes) {
    std::vector<long long> factors;
    for (long long prime : primes) {
        if (prime * prime > n)
            break;
        while (n % prime == 0) {
            factors.push_back(prime);
            n /= prime;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

std::vector<long long> nbt::factor(long long n) {
    std::vector<long long> factors;
    long long m = isqrt(n);
    for (long long i = 1; i <= m; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            factors.push_back(n / i);
        }
    }
    if (m * m == n)
        factors.pop_back();
    return factors;
}