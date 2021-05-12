#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

bool bystart(long long &a, long long &b) {return a < b;}
bool byend(long long &a, long long &b) {return a < b;}

long long next(std::vector<long long> &b, std::vector<long long> &e, long long &start, char &list) {
    long long next = 0;
    int i;
    // Loop for as long as we are not yet at the end of the list and the next landing point is not greater than the current starting point (both lists are always the same size)
    for (i = 0; next <= start && i < b.size(); ++i) {

        // If we are looping through the beginning list 
        // Set the next beginning equal to the next place we are going to start (as long as the place is greater than our original position) (Finding the next segment in which to place the meeting)
        if (list == 'b') {
            next = b[i];
        }

        // If we are looping through the ending times list
        // Set the next ending (and meeting) to the next ending point, so long as we select an ending that is greater than or equal to the starting point. (the equal to the starting point situation will not be caught by the loop, so we catch it 
        // in the conditional instead
        else if (list == 'e' && b[i] >= start) {
            next = e[i];
            if (next == start) {
                return next;
            }
        }
    }

    // i being the same size as the list and next being less than the limit we need to be greater than 
    if (i == b.size() && next <= start) { return -1; }

    // Return the next smallest begintime or endtime larger than the current earliest begintime or endtime. Or return 0 if there is none
    return next;
}

        
int main() {
    
    // Read in values
    int tenants;
    long long begins, ends;
    std::vector<long long> beginsort;
    std::vector<long long> endsort;
    std::vector<long long> markings;
    std::cin >> tenants;
    for (int i = 0; i < tenants; ++i) {
        std::cin >> begins >> ends;
        beginsort.push_back(begins);
        endsort.push_back(ends);
    }

    // Sort the end times list from smallest to largest
    std::sort(endsort.begin(), endsort.end(), byend);

    // Sort the begin times list from smallest to largest
    std::sort(beginsort.begin(), beginsort.end(), bystart);

    // Find the smallest starting point, then find the smallest end point larger than the current smallest starting point and place a marker there. Repeat the process until the incrementing is past the largest end time
    long long marker = 0;
    char list;
    while (true) {

        // Set the marker equal to the earliest start time
        list = 'b';
        marker = next(beginsort, endsort, marker, list);
        if (marker == -1) { break; }

        // Set the marker equal to the lowest earliest end time
        list = 'e';
        marker = next(beginsort, endsort, marker, list);
        std::cout << "Placing a marker here: " << marker << "\n";
        markings.push_back(marker);
        
        // Delete all segments in both begin list and end list that include the marker we just produced 
        int i = 0;
        while (i != endsort.size()) {
            if (endsort[i] <= marker) {
                beginsort.erase(beginsort.begin() + i);
                endsort.erase(endsort.begin() + i);
            }
            ++i;
        }
    }


    // Print out the number of marks and the where they are
    std::cout << "\n" << markings.size() << "\n";
    for (int i = 0; i < markings.size() ; ++i) {
        std::cout << markings[i] << " ";
    }
    return 0;
}
