#include <iostream>
#include <vector>

int main() {
    std::vector<int> list;
    int a = 0, temp;
    bool flip;
    while (std::cin >> a) {
        list.push_back(a);
    }
    
    // We loop the outer loop until size - 1 because the last spot will already be sorted if all other are as well
    for (int j = 0; j < list.size() - 1; ++j) {

        // Setting up a flip to signal if the sorting finishes early
        flip = true;

        // We loop the inner loop until size - 1 because the last element, n - 1, will not have a partner (i + 1 at n - 1 will try to index list[n] which will give an error)
        for (int i = 0; i < list.size() - 1; ++i) {
            if (list[i] > list[i + 1]) {
                temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                flip = false;
            }
        }

        // If we don't need to iterate across the list anymore
        if (flip == true) {
            break;
        }
    }

    for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    // For presenting below the command line header
    std::cout << "\n";
}

