#include <vector>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>
#include <utility>

void GridFiller(std::vector< std::vector<std::pair<int, std::pair<int, int> > > >& grid, std::vector<int>& num_1, std::vector<int>& num_2){
    int n = num_2.size();
    int m = num_1.size();
    int match, diagonal_value, left_value, top_value;
    // i is down the row and j is down the column
    // Therefore , when indexing treat j as the row and i as the column
    // Outer loop is the second num since we are going left to right on the second num and going down the row for each shift leftward 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            match = 0;

            // DEBUG for checking the correct letter checking
            //std::cout << "Comparing: " << num_2[i-1] << " to " << num_1[j-1] << "\n";
            if(num_1[j - 1] == num_2[i - 1]){match = 1;}

            // Maybe RTW
            diagonal_value = grid[j-1][i-1].first + match;
            left_value = grid[j][i-1].first;
            top_value = grid[j-1][i].first;

            // If the diagonal plus the possible match-reward is more than top-vertical value
            if(diagonal_value >= (top_value)){

                // If the diagonal plus the possible penalty is more than the left-horizontal value
                if((diagonal_value) >= (left_value)){
                    // DEBUG
                    //std::cout << "Diagonal is the largest at (" << j << "," << i << ")\n";
                    //std::cout << "Diagonal(" << j - 1 << "," << i-1 << "): " << grid[j-1][i-1].first << "\n";
                    //std::cout << "Value of mismatch: " << mismatch << "\n";
                    //std::cout << "Value of grid[j-1][i-1].first: " << grid[j-1][i-1].first << "\n";
                    // Setting the value of the edge plus the largest value
                    grid[j][i].first = diagonal_value;
                    // Setting the second value to be the coordinate-position of the previous spot
                    grid[j][i].second.first = j - 1;
                    grid[j][i].second.second = i - 1;
                }

                // The left-horizontal value is the largest compared to the top-vertical value
                else {
                    // DEBUG
                    //std::cout << "Left-horizontal is the largest at (" << j << "," << i << ")\n";
                    //std::cout << "Left-horizontal(" << j << "," << i - 1 << "): " << grid[j][i-1].first << "\n";
                    grid[j][i].first = left_value;
                    grid[j][i].second.first = j;
                    grid[j][i].second.second = i - 1;
                }
            }

            // If the top-vertical value was larger than the left-horizontal value
            else if (top_value >= left_value){
                // DEBUG
                //std::cout << "top-vertical is the largest at (" << j << "," << i << ")\n";
                //std::cout << "top-vertical(" << j - 1 << "," << i << "): " << grid[j - 1][i].first << "\n";
                grid[j][i].first = top_value;
                grid[j][i].second.first = j - 1;
                grid[j][i].second.second = i;
            }
            
            // Finally, if the left-horizontal is the largest
            else {
                // DEBUG
                //std::cout << "left-horizontal is the largest at (" << j << "," << i << ")\n";
                //std::cout << "left-horizontal(" << j << "," << i - 1 << "): " << grid[j][i-1].first << "\n";
                grid[j][i].first = left_value;
                grid[j][i].second.first = j;
                grid[j][i].second.second = i - 1;
            }
        }
    }
}

// We can just destroy the nums and pop from the back since we dont really care about the nums afterwards.
std::vector<int> FindCommonSubstring(std::vector< std::vector< std::pair<int , std::pair<int, int> > > >& grid, std::vector<int>& num_1, std::vector<int>& num_2){
    int i, j;
    std::vector<int> common_substring;
    // If one of the nums shrinks down to zero, then the rest of the remaining num is certainly not in common with the other (since the other would be empty)
    while(num_1.size() > 0 && num_2.size() > 0){
        // Next coordinates on the optimal path
        i = grid[num_1.size()][num_2.size()].second.first;
        j = grid[num_1.size()][num_2.size()].second.second;
        // If it is a match
        if (grid[i][j].first != grid[num_1.size()][num_2.size()].first){
            common_substring.push_back(num_1.back());
            num_1.pop_back();
            num_2.pop_back();
        }
        else {
            if(i < num_1.size()) {num_1.pop_back();}
            if(j < num_2.size()) {num_2.pop_back();}
        }
    }
    
    return common_substring;
}

// Arguments to read in vectors are number of lists, the first mandatory list and the second optional list
void readin(int num_lists, std::vector<int>& list1, std::vector<int>& list2){
    int len, holder;
    for(int i = 0; i < num_lists; ++i){
        std::cin >> len;
        if (i == 0){
            for(int j = 0; j < len; ++j){
                std::cin >> holder;
                list1.push_back(holder);
            }
        }
        else {
            for(int k = 0; k < len; ++k){
                std::cin >> holder;
                list2.push_back(holder);
            }
        }
    }
}

std::vector< std::vector< std::pair<int, std::pair<int, int> > > > grid_creator(int& vertical_len, int& horizontal_len){
    std::vector< std::vector< std::pair<int , std::pair<int, int> > > > grid(vertical_len, std::vector< std::pair<int, std::pair<int , int> > >(horizontal_len));
    return grid;
}

int main() {
    std::vector<int> num_1, num_2, common_substring;
    for(int i = 2; i > 0; --i){
        readin(i, num_1, num_2);
        // Create the zero 2D vector Fill in the foundation of the DP
        // For each pair, the first value will be the # of points at that position and the second the optimal spot before it (another pair)
        std::vector< std::vector< std::pair<int , std::pair<int, int> > > > grid(num_1.size() + 1, std::vector< std::pair<int, std::pair<int , int> > >(num_2.size() + 1));
        assert(grid.size() <= num_1.size() + 1 && grid[0].size() <= num_2.size() + 1);
        
        // DEBUG
        //std::cout << "Here are the rows of the grid: " << grid.size() << " and here are the columns of the grid: " << grid[0].size() << "\n";

        // DEBUG
        //for(int i = 0; i < grid.size(); ++i){
        //    for(int j = 0; j < grid[0].size(); ++j){
        //        std::cout << grid[i][j].first << " ";
        //    }
        //    std::cout << "\n";
        //}

        GridFiller(grid, num_1, num_2);

        // DEBUG
        //std::cout << "\n";

        // DEBUG
        //for(int i = 0; i < grid.size(); ++i){
        //    for(int j = 0; j < grid[0].size(); ++j){
        //        std::cout << grid[i][j].first << " ";
        //    }
        //    std::cout << "\n";
        //}

        // Print out the common substring but backwards
        common_substring = FindCommonSubstring(grid, num_1, num_2);
        std::reverse(common_substring.begin(), common_substring.end());
        // Set the common substring equal to the second string because we will read in the third vector as the new set of numbers
        num_2 = common_substring;
        // DEBUG
        //for(int i = 0; i < common_substring.size(); ++i){
        //    std::cout << common_substring[i] << " ";
        //}
    }
    std::cout << common_substring.size();
    return 0;

}

