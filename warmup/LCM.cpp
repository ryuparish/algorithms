#include <iostream>
#include <cstdlib>

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << a*b/gcd(a,b);
    return 0;
}

