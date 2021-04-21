#include <vector>
#include <iostream>
#include <string>
#include <algorithm>


bool isGreaterThanOrEqual(int &a, int &b) {

    std::string combo1 = std::to_string(a) + std::to_string(b);
    std::string combo2 = std::to_string(b) + std::to_string(a);
    return std:: stoi (combo1, nullptr, 10) >= std:: stoi (combo2, nullptr, 10);
}


// Naive Method Helper
// Function to turn integers into vectors
//std::vector<int> inttovec(int a) {
//    std::vector<int> list;
//    while (a != 0) {
//        list.push_back(a % 10);
//        a = a / 10;
//    }
//    if (list.size() > 1) {std::reverse(list.begin(), list.end());}
//    return list;
//}

// Naive Method
// Function to compare two number for ordering (if greater than or equal to in producing the maximum salary)
//bool isGreaterThanOrEqual(int &a, int &b) {
//
//    // Comparing the size of both of the numbers' digits and seeing if we can compare just 1 (both are single digits) or if we have to compare all the digits until they are different (both are not the same and at least one has 2 digits)
//    // If they are both single digits
//    if (a % 10 == a && b % 10 == b) {
//        return a >= b;
//    }
//
//    // Otherwise if at least one of the numbers is greater than 9 (or has double digits)
//    std::vector<int> num1 = inttovec(a);
//    std::vector<int> num2 = inttovec(b);
//    int i = 0, j = 0;
//    if (num1[i] == num2[j]) {
//        // We need to avoid the situation where we index to past the end of the vector
//        // Also need to avoid where both numbers are of different lengths of digits, yet have only a single number taking up all the digits
//        while (num1.size() > i + 1 || num2.size() > j + 1) {
//            if (num1.size() > i + 1) {
//                ++i;
//            }
//            if (num2.size() > j + 1) {
//                ++j;
//            }
//        }
//    }
//    return num1[i] >= num2[j];
//}

int main() {
    int a, length;
    std::cin >> length;
    std::vector<int> list;
    while (std::cin >> a){
        list.push_back(a);
    }
    
    // Set a maximum equal to a very small number than find the largest in the list to append to the final number and then pop that number from the list and search the list again until there is only one number in the list
    std::vector<int> salary;
    while (!list.empty()) {
        int max = -1, maxindex = 0;
        for (int i = 0; i < list.size(); ++i) {
            if (isGreaterThanOrEqual(list[i], max)) {
                max = list[i];
                maxindex = i;
            }
        }
        
        salary.push_back(max);
        list.erase(list.begin() + maxindex);
    }

    // Print out the salary vector with no spaces
    for (int i = 0; i < salary.size(); ++i) {
        std::cout << salary[i];
    }
    return 0;
}
