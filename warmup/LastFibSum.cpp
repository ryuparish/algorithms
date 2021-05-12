#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    long long n, a = 0, b = 1, c, sumdigit = 0;
    std::cin >> n;

    // Thankfully, the sum of the Pisano sequence of 10 is 280, meaning that the Pisano sequence sum modulo 10 does not stack or change at any given location of the sum.
    // Getting the Pisano period truncated version of n (n % 60)
    n = n % 60;

    // In case the sum of fib numbers is equal to n itself
    if (n <= 2) {
        std::cout << n;
        return 0;
    }

    // We add 1 to sumdigit because we start the loop with a = 0 and b = 1, so we will already have a sum of 1.
    // The edge case of numbers divisible by 60 would break this method if we placed it above the "n = n % 60"
    sumdigit += 1;

    // Since the Pisano Period of 10 summed up and then modulo'ed by 10 will give the last digit, we loop only until the remainder of n / 60 (the pisano period of 10 is 10)
    for (int i = 2; i <= n; ++i) {
        c = (a + b) % 10;
        a = b;
        b = c;
        sumdigit += c;
        sumdigit = sumdigit % 10;
    }

    std::cout << sumdigit;
    return 0;
}

