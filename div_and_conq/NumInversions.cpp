#include <vector>
#include <iostream>

std::vector<long long> Merge(std::vector<long long> a, std::vector<long long> b, int& invs);
std::vector<long long> Mergesort(std::vector<long long> a, int& invs); 


int main() {
    int a;
    std::vector<long long> list;
    std::cin >> a;
    while (std::cin >> a) {
        list.push_back(a);
    }

    int inversions = 0;

    // Call mergesort then print out the list returned
    // We need to send the reference variable to the inversions lvalue so the inversions can be kept track of through the recursions
    std::vector<long long> sorted = Mergesort(list, inversions);

    // Print out the vector returned (Omitted for the assignment)
    // for (int i = 0; i < sorted.size(); ++i) {
    //    std::cout << sorted[i] << " ";
    // }
    //std::cout << "\n";

    // Print the number of inversions
    std::cout << inversions;
}


std::vector<long long> Mergesort(std::vector<long long> a, int& invs) {
    // If the list is of size 1
    if(a.size() < 2) {
        return a;
    }

    // Split the list into two and then call mergesort on left then right then merge on both and return it
    int half = a.size() / 2;
    std::vector<long long> b;
    std::vector<long long> c;
    for (int i = 0; i < half; ++i) {
        b.push_back(a[i]);
    }
    for (int i = half; i < a.size(); ++i) {
        c.push_back(a[i]);
    }

    // Recursively calling mergesort then merge (Dirty: using a and b for assignment of the newly returned values. Although technically they should be the same values just sorted)
    b = Mergesort(b , invs);
    c = Mergesort(c, invs);

    return Merge(b, c, invs);
}

std::vector<long long> Merge(std::vector<long long> a, std::vector<long long> b, int& invs) {
    std::vector<long long> c;
    int i = 0, j = 0;
    //DEBUG 
    //std::cout << "\nHere is list a: ";
    //for(int i = 0; i < a.size(); ++i){
    //    std::cout << a[i] << " ";
    //}

    //std::cout << "\nHere is list b: ";
    //for(int i = 0; i < b.size(); ++i){
    //    std::cout << b[i] << " ";
    //}
    //std::cout << "\n";

    while (i < a.size() && j < b.size()){
        if (a[i] > b[j]) {
            //DEBUG std::cout << a[i] << " and " << b[j] << " are inversions \n";
            invs = invs + (a.size() - i);
            c.push_back(b[j]);
            ++j;
        }
        else {
            c.push_back(a[i]);
            ++i;
        }
    }

    while (i < a.size()){
        c.push_back(a[i]);
        ++i;
    }

    while (j < b.size()){
        c.push_back(b[j]);
        ++j;
    }

    return c;
}




