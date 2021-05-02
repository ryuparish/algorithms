#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>

// For passing back both m1 and m2
struct Part_index{
    int m1;
    int m2;
};

void Quicksort(std::vector<long long> &a, int start, int end);
Part_index Partition(std::vector<long long> &a, int start, int end);

int main() {
    long long a;
    std::vector<long long> list;
    // Reading in the first number that signifies the number of incoming inputs and tossing it since we don't care
    std::cin >> a;
    while(std::cin >> a) {
        list.push_back(a);
    }

    // Call quicksort and retrieve the returned value
    Quicksort(list, 0, list.size() - 1);

    // Print out the list
    for (int i = 0; i < list.size(); ++i){
        std::cout << list[i] << " ";
    }

    return 0;
}

void Quicksort(std::vector<long long> &a, int start, int end) {
    if (start < end) {
        Part_index pindex = Partition(a, start, end);
        Quicksort(a, start, pindex.m1 - 1);
        Quicksort(a, pindex.m2 + 1, end);
    }
}

Part_index Partition(std::vector<long long> &a, int start, int end) {
    // Setting the partition index, pivot index, and pivot value for comparison
    Part_index third_part;
    third_part.m1 = start;
    third_part.m2 = start;

    // Randomizing the selection
    int pivot_index = (rand() % ((end - start) + 1)) + start;
    std::swap(a[end], a[pivot_index]);
    long long pivot_value = a[end];


    // Perform the swapping and incrementing of the pivot position
    for (int i = start; i < end; ++i){
        if (a[i] <= pivot_value) {
            std::swap(a[i], a[third_part.m1]);
            third_part.m1++;
            third_part.m2++;
        }
    }

    // Swap the pivoting point with it's calculated pindex spot (less on the left and greater on the right)
    std::swap(a[third_part.m1], a[end]);

    // Quick3
    // Search the left end to possibly create a third real partition
    std::vector<long long> dupes;
    for (int i = 0; i < third_part.m1; ++i){

        // This should be loading all the indices of the duplicates in least the greatest order 
        if (a[i] == pivot_value) {
            dupes.push_back(i);
        }
    }

    // If they are ALL the same duplicate
    if (dupes.size() == a.size()/2) {
        third_part.m1 = 0;
        return third_part;
    }

    // If NONE of them are duplicates
    else if (dupes.empty()){
        return third_part;
    }
    
    // Then swapping each of the duplicates with the closest non-duplicate occupied spot to the middle part
    // Until the list of dupes runs out or until the decrementer reaches the beginning of the list
    for (int i = third_part.m1 - 1; i >= 0 && dupes.size() > 0; --i) {
        if (a[i] == pivot_value) {
            third_part.m1--;
            dupes.pop_back();
        }
        else {
            third_part.m1--;
            std::swap(a[i], a[dupes.back()]);
            dupes.pop_back();
        }
    }
            
    return third_part;
}

