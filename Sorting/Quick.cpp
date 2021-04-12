#include<iostream>
#include<algorithm>
#include<vector>

void Quicksort(std::vector<int> &a, int start, int end);
int Partition(std::vector<int> &a, int start, int end);

int main() {
    int a;
    std::vector<int> list;
    while(std::cin >> a) {
        list.push_back(a);
    }

    // Call quicksort and retrieve the returned value
    Quicksort(list, 0, list.size() - 1);

    // Print out the list
    for (int i = 0; i < list.size(); ++i){
        std::cout << list[i] << " ";
    }

    std::cout << "\n";
    return 0;
}

void Quicksort(std::vector<int> &a, int start, int end) {
    if (start < end) {
        int pindex = Partition(a, start, end);
        Quicksort(a, start, pindex - 1);
        Quicksort(a, pindex + 1, end);
    }
}


int Partition(std::vector<int> &a, int start, int end) {
    int pindex = start;
    int pivot = a[end];
    for (int i = start; i < end; ++i){
        if (a[i] <= pivot) {
            std::swap(a[i], a[pindex]);
            pindex++;
        }
    }
    // Swap the pivoting point with it's calculated pindex spot (less on the left and greater on the right)
    std::swap(a[pindex], a[end]);
    return pindex;
}

