#include <vector>
#include <iostream>

std::vector<int> Merge(std::vector<int> a, std::vector<int> b);
std::vector<int> Mergesort(std::vector<int> a); 

int main() {
    int a;
    std::vector<int> list;
    while (std::cin >> a) {
        list.push_back(a);
    }

    // Call mergesort then print out the list returned
    std::vector<int> sorted = Mergesort(list);

    // Print out the vector returned
    for (int i = 0; i < sorted.size(); ++i) {
        std::cout << sorted[i] << " ";
    }
    std::cout << "\n";
}


std::vector<int> Mergesort(std::vector<int> a) {
    // If the list is of size 1
    if(a.size() < 2) {
        return a;
    }

    // Split the list into two and then call mergesort on left then right then merge on both and return it
    int half = a.size() / 2;
    std::vector<int> b(a.begin(), a.begin()+half);
    std::vector<int> c(a.begin()+half, a.end());
    //for (int i = 0; i < half; ++i) {
    //    b.push_back(a[i]);
    //}
    //for (int i = half; i < a.size(); ++i) {
    //    c.push_back(a[i]);
    //}

    // Recursively calling mergesort then merge (Dirty: using a and b for assignment of the newly returned values. Although technically they should be the same values just sorted)
    b = Mergesort(b);
    c = Mergesort(c);

    return Merge(b, c);
}

std::vector<int> Merge(std::vector<int> a, std::vector<int> b) {
    std::vector<int> c;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()){
        if (a[i] >= b[j]) {
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
