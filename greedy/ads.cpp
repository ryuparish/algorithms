#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>

int main() {
    int ads;
    long long a;
    std::vector<long long> clicks;
    std::vector<long long> profit;
    // Read in the number of ads, profit, and the clicks
    std::cin >> ads;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < ads; ++j) {
            std::cin >> a;
            if (i == 0) {profit.push_back(a);}
            else {clicks.push_back(a);}
        }
    }

    std::sort(profit.begin(), profit.end());
    std::reverse(profit.begin(), profit.end());
    std::sort(clicks.begin(), clicks.end());
    std::reverse(clicks.begin(), clicks.end());

    // Sum the revenue in a
    a = 0;
    for (int i = 0; i < profit.size(); ++i) {
        a += (profit[i] * clicks[i]);
    }

    std::cout << "\n" << a;
    return 0;
}
// Tried Stress Testing, and it did not help find the problem with the segmentation fault (the segfault only happened with larger numbers as elements, as in the size of the list did not cause any errors with smaller numbers as elements)
//long long bruteforce(std::vector<int> a, std::vector<int> b) {
//    // Counter for the while loop
//    int i = 0; 
//    long long maxprofit = 0;
//    long long original_size = a.size();
//    while (i < original_size) {
//        int amax = -100000, amaxindex;
//        int bmax = -100000, bmaxindex;
//        for (int j = 0; j < a.size(); ++j) {
//            if (a[j] > amax) {
//                amax = a[j];
//                amaxindex = j;
//            }
//        }
//        for (int k = 0; k < b.size(); ++k) {
//            if (b[k] > bmax) {
//                bmax = b[k];
//                bmaxindex = k;
//            }
//        }
//        ++i;
//        maxprofit += amax * bmax;
//        a.erase(a.begin() + amaxindex);
//        b.erase(b.begin() + bmaxindex);
//    }
//    return maxprofit;
//}
//
//        
//int main() {
//    while (true) {
//        int n = rand() % 1000 + 1;
//        std::cout << n << "\n";
//        std::vector<int> a;
//        std::vector<int> b;
//        for (int i = 0; i < n; ++i) {
//            a.push_back(rand() % 2000 - 1000);
//            b.push_back(rand() % 2000 - 1000);
//        }
//        for (int i = 0; i < n; ++i) {
//            std::cout << a[i] << " "; 
//        }
//        std::cout << "\n";
//        for (int i = 0; i < n; ++i) {
//            std::cout << b[i] << " "; 
//        }
//        
//        std::cout << "\n";
//        long long res1 = ryusolution(a, b);
//        long long res2 = bruteforce(a, b);
//        if (res1 != res2) {
//            std::cout << "Wrong answer: " << res1 << " " << res2 << "\n";
//            break;
//        }
//        else {
//            std::cout << "OK!\n";
//        }
//    }
//
//    int ads, c;
//    // STRESS TESTING //std::vector<int> profit;
//    std::vector<int> clicks;
//    std::vector<int> profit;
//    // Read in the number of ads, profit, and the clicks
//    std::cin >> ads;
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < ads; ++j) {
//            std::cin >> c;
//            if (i == 0) {profit.push_back(c);}
//            else {clicks.push_back(c);}
//        }
//    }
//    
//    int maxprofit = ryusolution(profit, clicks);
//
//    std::cout << maxprofit << "\n";
//    return 0;
//}

