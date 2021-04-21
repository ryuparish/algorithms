#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

bool byend(std::pair<long long, long long> &a, std::pair<long long, long long> &b) {return a.second < b.second;}
        
int main() {
    
    // Read in values
    int tenants, begins, ends;
    std::vector< std::pair<long long, long long> > endsort;
    std::vector<long long> markings;
    std::cin >> tenants;
    for (int i = 0; i < tenants; ++i) {
        std::cin >> begins >> ends;
        std::pair <long long, long long> slot = std::make_pair (begins, ends);
        endsort.push_back(slot);
    }

    // Sort the end times list from smallest to largest
    std::sort(endsort.begin(), endsort.end(), byend);

    // Find the smallest starting point, then find the smallest end point larger than the current smallest starting point and place a marker there. Repeat the process until the incrementing is past the largest end time
    long long marker = 0;
    while (!endsort.empty()) {

        // Set the marker equal to the lowest earliest end time
        marker = endsort[0].second;
        markings.push_back(marker);
        
        for (int i = 0; i < endsort.size(); ++i) {
            if (endsort[i].first <= marker && endsort[i].second >= marker) {
                endsort.erase(endsort.begin() +i);
                i--;
            }
        }

    }


    // Print out the number of marks and the where they are
    std::cout << "\n" << markings.size() << "\n";
    for (int i = 0; i < markings.size() ; ++i) {
        std::cout << markings[i] << " ";
    }
    return 0;
}
