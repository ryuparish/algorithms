#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    int n;
    std::cin >> n;
    // Create the list
    std::vector<int> fiblist(3,0);
    
    // Loop through the list from 2, with the first two numbers being 0 and 1
    fiblist[0] = 0;
    fiblist[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fiblist[2] = fiblist[1] + fiblist[0];
        fiblist[0] = fiblist[1];
        fiblist[1] = fiblist[2];
    }
    if (n > 1) {
        std::cout << fiblist[2];
    }
    else {
        std::cout << n;
    }
}

