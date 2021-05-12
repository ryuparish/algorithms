#include <iostream>
#include <vector>

long long Pisano(long long a, long long b) {

    // Create list to loop fibonacci numbers. We start at F3 and F4 because every Pisano sequence is at least 3
    std::vector<long long> Fib;
    Fib.push_back(0);
    Fib.push_back(1);

    // "i" will become our Pisano sequence. Don't forget to add 3 to the final out Pisano sequence, since we started with a head start of 3
    for (int j = 0; true ; ++j) {
       Fib.push_back((Fib[j] + Fib[j + 1]) % b);

       // Return the correct modulo number of the fibonacci sequence
       if (Fib[j+1] == 0 && Fib[j+2] == 1) {
           // We add one to get the pisano period because j counts the number of slides. In the beginning, you already have a Pisano of 3 no matter what number you use.
           // The last two increments of j will just confirm the repeat and will be excess. If you add 1 to the j value, you will have the pisano period length (since 
           // it start with 3 in the beginning)
           a = a % (j+1);

           // a is now the remainder of itself divided by the Pisano length
           // This a value is what you want to 'mod b' with to obtain F(a) mod b.
           return Fib[a] % b;
       }

       // Incrementing Pisano sequence as well
       
    }
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << Pisano(a, b);
}

