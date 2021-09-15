#include <iostream>
#include <vector>
#include <unordered_set>
#include "numtheory.h"

const int N = 28123;

int main() {
    std::vector<int> abundants;
    for (int n = 12; n < N; n++) {
        std::vector<long long> factors = nbt::factor(n);
        int sumFactors = -n;
        for (long long factor : factors) {
            sumFactors += factor;
            if (sumFactors > n) {
                abundants.push_back(n);
                break;
            }
        }
    }
    
    std::unordered_set<int> abunSet = std::unordered_set(abundants.begin(), abundants.end());
    int result = 0;
    for (int n = 1; n < N; n++) {
        for (int abundant : abundants) {
            if (abundant >= n) {
                result += n;
                break;
            }
            if (abunSet.find(n - abundant) != abunSet.end())
                break;
        }
    }
    std::cout << result << std::endl;
}
