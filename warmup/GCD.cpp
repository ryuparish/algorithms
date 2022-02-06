#include <cstdlib>
#include <iostream>

int gcd(long a, long b) {
    /* Base case if the remainder (in the most current loop the divisor) is zero */
    if (b == 0) {
       return a;
    }
    /* Continuing recursion until one of the variable become zero */
    long aprime = (long)a % b;
    std::cout << b << " divides " << a << " " << (long)a/b << " many times\n";
    std::cout << "b: " << b << " " << a << " mod " << b << ": " << aprime << "\n";
    return gcd(b, aprime);
}


int main() {
    long a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b);
    return 0;
}

