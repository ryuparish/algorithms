#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    // sumdigit equals 0 in this case because it does not start from the beggining F[0] + F[1] = 1. It instead starts at an arbitrary number
    int a, b, c, sumdigit = 0;
    long long m, n;
    std::cin >> m >> n;
    

    // We need the modulo 60 version of both the starting point and the ending point 
    m = m % 60;
    n = n % 60;

    // When m is lower than 2, there can be two edge cases; m = 0 and n = 1, or m = 1 and n = 2. In either case, if the sum is set to 1, you will get the correct answer.
    // Situation 1: sumdigit = 1, then loop doesn't activate and 1 is printed (correct becuase F[0] = 0 and F[1] = 1)
    // Situation 2: sumdigit = 1, then loop does activate and 1 is added to sumdigit (correct because F[0] + F[1] + F[2] = 2)
    // There is also the edge case where m <= 2 and n = 0 ( 0 0 ). The extra conditional below will not activate on that. Other times, where m = n, the sum is always one.
    // Then there is a third edge case, where m = 2 and n = 3. This is remedied by the else if statement, otherwise it will give you an offset of 1 for the sum in the beginning.
    if (m <= 2 && n != 0) {
        sumdigit = 1;
        // If (1 1), (2 2)
        if (n == m) {
            std::cout << sumdigit;
            return 0;
        }
        // If (2 3)
        else if (m == 2) {
            sumdigit = 0;
        }
    }

    // Special edge case where n < m
    if (n < m) {
        // This will cause the loop to sum from m to n if n overlaps m
        n = 60 + n;
    }

    // Loop through the list from 2, with the first two numbers being 0 and 1 (this method only works if m % 60 > n % 60)
    a = 0;
    b = 1;
    for (int i = 2; i <= n; ++i) {
        c = (a + b) % 10;
        a = b;
        b = c;
        if (i >= m) {
            sumdigit += c;
            sumdigit = sumdigit % 10;
        }
    }
    std::cout << sumdigit;
    return 0;
}

