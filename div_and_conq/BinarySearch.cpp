#include <vector>
#include <iostream>

// Note 1:  We don't need to check if there will be a list of size zero, therefore we don't need to check if we can index (max - min) /2. (minimum possible value would be 0 [min = -1, max = 1], the first item in any list)
int BinarySearch(long long& a, std::vector<long long>& list1, int min, int max) {

    // Setting up the middle index and middle value
    int mid = ((max - min) /2) + min;
    long long mid_value = list1[mid];

    // Not equal to
    if (mid_value != a) {
        // Greater than
        if (mid_value > a) {
            max = mid;
        }
        // Less than
        else {
            min = mid;
        }
    }

    // If there is no space between
    if (max - min <= 1) {
        return -1;
    }

    // If the number has been found
    else if (mid_value == a) {
        // Edge case of min = -1 and max = 1 (would result in -1 being returned)
        if (max == 1 && min == -1) {
            return 0;
        }

        // Return the index of the number in the first list
        return ((max - min) /2) + min;
    }
    
    return BinarySearch(a, list1, min, max);
}

        
int main() {
    long long a, b;
    std::vector<long long> list1, list2;

    // Read in elements from the first list (our searching list)
    std::cin >> a;
    for (int i = 0; i < a; ++i){
        std::cin >> b;
        list1.push_back(b);
    }

    // Read in the elements from the second list (the items we are searching for) 
    std::cin >> a;
    for (int i = 0; i < a; ++i){
        std::cin >> b;
        list2.push_back(b);
    }

    // Implement the binary search
    for (int i = 0; i < list2.size(); ++i) {
        std::cout << BinarySearch(list2[i], list1, -1, list1.size()) << " ";
    }

    return 0;
}
