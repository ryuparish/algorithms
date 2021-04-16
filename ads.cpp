#include <algorithm>
#include <vector>
#include <iostream>

int gtol (int &a, int &b) { return a > b; }
int main() {
    int ads, a;
    std::vector<int> profit;
    std::vector<int> clicks;
    // Read in the number of ads, profit, and the clicks
    std::cin >> ads;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < ads; ++j) {
            std::cin >> a;
            if (i == 0) {profit.push_back(a);}
            else {clicks.push_back(a);}
        }
    }

    std::sort(profit.begin(), profit.end(), gtol);
    std::sort(clicks.begin(), clicks.end(), gtol);

    // Sum the revenue in a
    a = 0;
    for (int i = 0; i < profit.size(); ++i) {
        a += (profit[i] * clicks[i]);
    }

    std::cout << "\n" << a;
}

        

