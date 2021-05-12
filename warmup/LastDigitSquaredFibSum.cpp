#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    int a, b, c;
    long long n;
    std::cin >> n;

    // We module 60 since 60 is the pisano period of 10 and it also sums to 280 (280 mod 10 is 0, which means the sum resets at every period as well).
    n = n % 60;
    
    // If n is equal to it's fibonacci sum
    if (n <= 2) {
        std::cout << n;
        return 0;
    }

    // Loop through the list from 2, with the first two numbers being 0 and 1
    a = 1;
    b = 1;
    
    // We go until n + 1 for the formula of (F[n+1] * F[n])
    // We also do not have to do a summation, just the equation above. Therefore, no edge cases will be triggered by setting i = 3, a = 1, and b = 1
    for (int i = 3; i <= n + 1; ++i) {
        c = (b + a) % 10;
        a = b;
        b = c;
    }

    // a will hold F[n], b = F[n + 1], and c = F[n + 1]
    std::cout << (c * a) % 10;
    return 0;
}

