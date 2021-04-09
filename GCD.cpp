#include <cstdlib>
#include <iostream>

int gcd(int a, int b) {
    /* Base case if the remainder (in the most current loop the divisor) is zero */
    if (b == 0) {
       return a;
    }
    /* Continuing recursion until one of the variable become zero */
    int aprime = (int)a % b;
    return gcd(b, aprime);
}


int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b);
    return 0;
}

