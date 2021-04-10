#include <iostream>
#include <vector>

int main() {
    int a, temp, minindex;
    std::vector<int> list;

    // Since cpp can't terminate an automated cin, you must press ctrl-d on mac to stop this loop after entering in the numbers 
    while (std::cin >> a) {
        list.push_back(a);
    }

    // So the output is horizontal and not right on the command line header
    std::cout << "\n";

    // Typically if you were not printing as you went and needed to do further work on the sorted list, you would only loop the outer loop until list.size() - 2. Think about why that is.
    for (int i = 0; i < list.size(); ++i) {
        minindex = i;
        for (int j = i; j < list.size(); ++j) {
            if (list[j] < list[i]) {
                minindex = j;
            }
        }
        temp = list[i];
        list[i] = list[minindex];
        list[minindex] = temp;
        
        std::cout << list[i] << " ";
    }

    return 0;
}
