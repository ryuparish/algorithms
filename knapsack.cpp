#include <iostream>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <vector>

bool byperweight(std::pair<double, double> &a, std::pair<double, double> &b) {
    return a.second > b.second;
}

int main() {

    // Read in the values for the knapsack and the items with their values 
    double n, value, weight, max = 0;
    double cap;
    std::vector< std::pair<double, double> > items;
    std::cin >> n >> cap;

    // Read in the values and make the second part of the pair the value per unit of weight
    while (std::cin >> value >> weight) {
        double perweight = value / weight;
        std::pair <double, double>  item = std::make_pair(weight, perweight);
        items.push_back(item);
    }

    // Sort the items based on their per weight basis
    std::sort (items.begin(), items.end(), byperweight);

    // For presentation
    std::cout << "\n";

    // Defining an iterator value at 0 then executing a while loop to fill up the bag
    int i = 0;
    while (cap > 0 && i < items.size()) {
        if (cap - items[i].first > 0) {
            cap -= items[i].first;
            max += items[i].first * items[i].second;
            ++i;
        }
        else {
            max += items[i].second * cap;
            cap = 0;
            ++i;
        }
    }

    std::cout << std::fixed << std::setprecision(4) << max;
    return 0;
}




