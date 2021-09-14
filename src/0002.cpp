#include <iostream>

const int N = 4000000;

int main() {
    int fib0 = 1;
    int fib1 = 2;
    int result = 0;
    while (fib1 <= N) {
        if (fib1 % 2 == 0)
            result += fib1;
        fib1 += fib0;
        fib0 = fib1 - fib0;
    }
    std::cout << result << std::endl;
}