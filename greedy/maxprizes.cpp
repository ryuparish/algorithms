#include <iostream>
#include <vector>

int main() {
    int a, i;
    std::cin >> a;
    std::vector<int> list;
    for (i = 1; a - i > i; ++i){
        a = a - i;
        list.push_back(i);
    }
    list.push_back(a);

    std::cout << list.size();
    std::cout << "\n";
    for(int i : list)
        std::cout << i << " ";

    return 0;
}
