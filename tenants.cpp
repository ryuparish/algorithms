#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

bool bystart(std::pair<int, int> &a, std::pair<int, int> &b) {return a.first < b.first;}
bool byend(std::pair<int, int> &a, std::pair<int, int> &b) {return a.second < b.second;}

int next(std::vector< std::pair<int, int> > &a, int &start, char &list) {
    int next = 0;
    int i;
    for (i = 0; next <= start && i < a.size(); ++i) {

        // If we are looping through the beginning list 
        if (list == 'b')
            next = a[i].first;

        // If we are looping through the ending times list
        else if (list == 'e' && a[i].first >= start) 
            next = a[i].second;
    }

    // i being the same size as the list and next being less than the limit we need to be greater than 
    if (i == a.size() && next <= start) { return -1; }

    // Return the next smallest begintime or endtime larger than the current earliest begintime or endtime. Or return 0 if there is none
    return next;
}

        
int main() {
    
    // Read in values
    int tenants, begins, ends;
    std::vector< std::pair<int, int> > beginsort;
    std::vector< std::pair<int, int> > endsort;
    std::vector<int> markings;
    std::cin >> tenants;
    for (int i = 0; i < tenants; ++i) {
        std::cin >> begins >> ends;
        std::pair <int, int> slot = std::make_pair (begins, ends);
        beginsort.push_back(slot);
    }

    // Copy the original list into for sorting by the smallest ending times
    endsort = beginsort;

    // Sort the end times list from smallest to largest
    std::sort(endsort.begin(), endsort.end(), byend);

    // Sort the begin times list from smallest to largest
    std::sort(beginsort.begin(), beginsort.end(), bystart);

    // Find the smallest starting point, then find the smallest end point larger than the current smallest starting point and place a marker there. Repeat the process until the incrementing is past the largest end time
    int marker = 0;
    char list;
    while (true) {

        // Set the marker equal to the earliest start time
        list = 'b';
        marker = next(beginsort, marker, list);
        if (marker == -1) { break; }

        // Set the marker equal to the lowest earliest end time
        list = 'e';
        marker = next(endsort, marker, list);
        markings.push_back(marker);

    }


    // Print out the number of marks and the where they are
    std::cout << "\n" << markings.size() << "\n";
    for (int i = 0; i < markings.size() ; ++i) {
        std::cout << markings[i] << " ";
    }
    return 0;
}
