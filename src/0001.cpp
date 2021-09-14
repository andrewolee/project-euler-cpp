#include <iostream>

const int N = 1000;

int main() {
    int result = 0;
    for (int i = 1; i < N + 1; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            result += i;
    }
    std::cout << result << std::endl;
}