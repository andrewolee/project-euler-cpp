#ifndef NUMTHEORY_H
#define NUMTHEORY_H

#include <vector>
#include <unordered_set>

namespace nbt {
    long long gcd(long long a, long long b);

    long long lcm(long long a, long long b);

    long long pow(long long a, long long b);

    long long mod_pow(long long a, long long b, long long m);

    long long isqrt(long long n);

    std::vector<long long> eratosthenes(long long n);

    std::vector<long long> p_factor(long long n);

    std::vector<long long> p_factor(long long n, std::vector<long long> primes);

    std::vector<long long> factor(long long n);
}

#endif