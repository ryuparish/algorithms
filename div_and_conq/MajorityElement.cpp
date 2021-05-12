#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // size_t list_size
    // cin >> list_size
    // int current = first_item, i = 0
    // vector.push_back(0);
    // for every item in the list:
    //      if the item is not current:
    //          vector.push_back(0);
    //          ++i
    //      vector[i]++
    // size_t half = list_size / 2;
    // for every item in vector:
    //      if (vector[i] > half){
    //          cout << 1;
    //          }
    //
    // cout << 0;
    
    std::size_t list_size;
    std::cin >> list_size;
    long long a;
    std::vector<long long> list;

    // Read in the values 
    for (size_t i = 0; i < list_size; ++i) {
        std::cin >> a;
        list.push_back(a);
    }

    std::sort(list.begin(), list.end());

    // The list where we will count the duplicates
    std::vector<int> collection;

    // We have on of the first item
    long long current = -1;
    size_t total = 0;

    // Loop through the input and add the totals of each unique element into the collection list
    for (size_t i = 0; i < list_size; ++i){
        if (list[i] > current) {
            current = list[i];
            while(i < list_size && list[i] == current){ total++; i++; }
            collection.push_back(total);
            total = 0;
            // Decrementing the i index because a different number was found
            i--;
        }
    }

    // Loop through the collections list and see if there are any values greater than n/2
    size_t half = list_size / 2;
    for (size_t i = 0; i < collection.size(); ++i){
        if (collection[i] > half) {std::cout << 1; return 0;}
    }
    std::cout << 0;
    return 0;
}

