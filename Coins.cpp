#include <iostream>

int main() {
    int value, coins= 0;
    std::cin >> value;
    while (value > 0) {
        if (value - 10 >= 0) {
            coins++;
            value = value - 10;
        }

        else if (value - 5 >= 0) {
            coins++;
            value = value - 5;
        }

        else {
            coins++;
            value = value - 1;
        }
    }
    std::cout << coins;
}

