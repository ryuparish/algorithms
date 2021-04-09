#include <iostream>
#include <vector>

int main() {

    // Create list to loop fibonacci numbers. We start at F3 and F4 because every Pisano sequence is at least 3
    int sum = 0;
    std::vector<long long> Fib;
    Fib.push_back(0);
    Fib.push_back(1);

    // "i" will become our Pisano sequence. Don't forget to add 3 to the final out Pisano sequence, since we started with a head start of 3
    for (int j = 0; j <= 60 ; ++j) {
       Fib.push_back((Fib[j] + Fib[j + 1]) % 10);

       // Return the correct modulo number of the fibonacci sequence
       if (Fib[j+1] == 0 && Fib[j+2] == 1) {
           for (int i = 0; i <= j; ++i){
               sum += Fib[i];
           }
           std::cout << sum;
       }

    }
}
