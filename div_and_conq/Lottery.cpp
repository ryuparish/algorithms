#include <vector>
#include <algorithm>
#include <iostream>


struct dual{
    long long num;
    int id;
};

int BinarySearch(long long& a, std::vector<dual>& list1, int min, int max);

bool bpe(dual& a, dual& b) {
    if (a.num == b.num){
        return a.id < b.id;
    }
    return (a.num < b.num);
}

// In the case of a beginning, ending, and a point all having the same number, you want the ordering to be B, P, E since our algorithm will use the formula: B - E = # of segments containing P
// B: 0, P: 1, E: 2
int main() {
    long long a, object;
    std::vector< dual > ult_list;
    int s, p;
    dual b;
    std::cin >> s >> p;
    std::vector<long long> searchlist (p, 0);

    // Adding in the segments
    for (int i = 0; i < s; ++i){

        // Adding first object
        std::cin >> object;
        b.num = object;
        b.id = 0;
        ult_list.push_back(b);

        // Adding second object
        std::cin >> object;
        b.num = object;
        b.id = 2;
        ult_list.push_back(b);
    }

    // Adding in the points 
    for (int i = 0; i < p; ++i){
        std::cin >> object;
        // Add the final search list
        searchlist[i] = object;
        // Add the ultimate list
        b.num = object;
        b.id = 1;
        ult_list.push_back(b);
    }

    // Sort the ultimate list to find the inclusive segments for each point
    std::sort(ult_list.begin(), ult_list.end(), bpe);

    std::vector<dual> result;
    int counter = 0;
    for (int i = 0; i < ult_list.size(); ++i){
        if (ult_list[i].id == 0){
            counter++;
        }
        else if (ult_list[i].id == 2){
            counter--;
        }
        else {
            dual a;
            a.num = ult_list[i].num;
            // id for these dual structs will mean the number of segments they fall into
            a.id = counter;
            result.push_back(a);
        }
    }

    // Sort the list of only the actual numbers and sort the list of the points paired with the seg number
    std::sort(result.begin(), result.end(), bpe);
    
    // Search the list for each of the numbers using binary search
    for (int i = 0; i < searchlist.size(); ++i){
        std::cout << BinarySearch(searchlist[i], result, -1, result.size()) << " ";
    }
}

int BinarySearch(long long& a, std::vector<dual>& list1, int min, int max){

    int mid = ((max - min) /2) + min;
    long long mid_value = list1[mid].num;

    if (mid_value != a) {
        if (mid_value > a) {
            max = mid;
        }
        else {
            min = mid;
        }
    }

    if (max - min <= 1) {
        return 0;
    }

    else if (mid_value == a) {
        if (max == 1 && min == -1) {
            return list1[0].id;
        }
        return list1[((max - min) /2) + min].id;
    }

    return BinarySearch(a, list1, min, max);
}



