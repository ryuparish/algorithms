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

// We cannot destroy the substring and must use copies since we will do a total of 6 comparisons
//
std::vector<int> FindCommonSubstring(std::vector< std::vector< std::pair<int , std::pair<int, int> > > >& grid, std::vector<int> num_1, std::vector<int> num_2){
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
    
    std::reverse(common_substring.begin(), common_substring.end());
    return common_substring;
}

// Arguments to read in vectors are number of lists, the first mandatory list and the second optional list
void readin(std::vector<int>& list){
    int len, holder;
    std::cin >> len;
    for(int i = 0; i < len; ++i){
        std::cin >> holder;
        list.push_back(holder);
    }
}

// Create the grid based on the size of the given words (lengths of words are given)
std::vector< std::vector< std::pair<int, std::pair<int, int> > > > grid_creator(int vertical_len, int horizontal_len){
    std::vector< std::vector< std::pair<int , std::pair<int, int> > > > grid(vertical_len, std::vector< std::pair<int, std::pair<int , int> > >(horizontal_len));
    return grid;
}

// Compare the three strings entered and return the longest length
int compare_3_lens(std::vector<int>& string1, std::vector<int>& string2, std::vector<int>& string3){
    if(string1.size() >= string2.size()){
        if(string1.size() >= string3.size()){return string1.size();}
        else {return string3.size();}
    }
    else if (string2.size() >= string3.size()){return string2.size();}
    else{return string3.size();}
}
            
// We need to compare LCS(1,2) with LCS(1,3), LCS(1,3) with LCS(2,3), and LCS(1,2) with LCS(2,3) to see which combination holds the longest
int main() {
    std::vector<int> num_1, num_2, num_3, substring_1, substring_2, substring_3, finalist_1, finalist_2, finalist_3;
    std::vector< std::vector< std::pair<int , std::pair<int, int> > > > grid;
    // Create the zero 2D vector Fill in the foundation of the DP
    // For each pair, the first value will be the # of points at that position and the second the optimal spot before it (another pair)
    readin(num_1);
    readin(num_2);
    readin(num_3);

    // Getting the substring from num1 and num2 
    grid = grid_creator(num_1.size() + 1, num_2.size() + 1);
    // DEBUG
    //std::cout << "Here are the rows of the grid: " << grid.size() << " and here are the columns of the grid: " << grid[0].size() << "\n";
    // Assert the correct dimensions of the grid
    assert(grid.size() <= num_1.size() + 1 && grid[0].size() <= num_2.size() + 1);
    GridFiller(grid, num_1, num_2);
    // DEBUG
    //for(int i = 0; i < grid.size(); ++i){
    //    for(int j = 0; j < grid[0].size(); ++j){
    //        std::cout << grid[i][j].first << " ";
    //    }
    //    std::cout << "\n";
    //}
    substring_1 = FindCommonSubstring(grid, num_1, num_2);
    
    // Getting the substring from num1 and num3
    grid = grid_creator(num_1.size() + 1, num_3.size() +1);
    // DEBUG
    //std::cout << "Here are the rows of the grid: " << grid.size() << " and here are the columns of the grid: " << grid[0].size() << "\n";
    // Assert the correct dimensions of the grid
    assert(grid.size() <= num_1.size() + 1 && grid[0].size() <= num_3.size() + 1);
    GridFiller(grid, num_1, num_3);
    // DEBUG
    //for(int i = 0; i < grid.size(); ++i){
    //    for(int j = 0; j < grid[0].size(); ++j){
    //        std::cout << grid[i][j].first << " ";
    //    }
    //    std::cout << "\n";
    //}
    substring_2 = FindCommonSubstring(grid, num_1, num_3);

    // Getting the substring from num2 and num3
    grid = grid_creator(num_2.size() + 1, num_3.size() +1);
    // DEBUG
    //std::cout << "Here are the rows of the grid: " << grid.size() << " and here are the columns of the grid: " << grid[0].size() << "\n";
    // Assert the correct dimensions of the grid
    assert(grid.size() <= num_2.size() + 1 && grid[0].size() <= num_3.size() + 1);
    GridFiller(grid, num_2, num_3);
    // DEBUG
    //for(int i = 0; i < grid.size(); ++i){
    //    for(int j = 0; j < grid[0].size(); ++j){
    //        std::cout << grid[i][j].first << " ";
    //    }
    //    std::cout << "\n";
    //}
    substring_3 = FindCommonSubstring(grid, num_2, num_3);

    // Find the longest substring after comparing it with others
    // Comparing substring1 with substring2
    grid = grid_creator(substring_1.size() + 1, substring_2.size() +1);
    assert(grid.size() <= substring_1.size() + 1 && grid[0].size() <= substring_2.size() + 1);
    GridFiller(grid, substring_1, substring_2);
    finalist_1 = FindCommonSubstring(grid, substring_1, substring_2);
    // Comparing substring1 with substring3
    grid = grid_creator(substring_1.size() + 1, substring_3.size() +1);
    assert(grid.size() <= substring_1.size() + 1 && grid[0].size() <= substring_3.size() + 1);
    GridFiller(grid, substring_1, substring_3);
    finalist_2 = FindCommonSubstring(grid, substring_1, substring_3);
    // Comparing substring2 with substring3
    grid = grid_creator(substring_2.size() + 1, substring_3.size() +1);
    assert(grid.size() <= substring_2.size() + 1 && grid[0].size() <= substring_3.size() + 1);
    GridFiller(grid, substring_2, substring_3);
    finalist_3 = FindCommonSubstring(grid, substring_2, substring_3);

    // Finally, we compare the finalist strings for length (all the original substrings will have these strings in common
    compare_3_lens(finalist_1, finalist_2, finalist_3);

    // DEBUG
    //for(int i = 0; i < finalist_1.size(); ++i){
    //    std::cout << finalist_1[i] << " ";
    //}
    std::cout << compare_3_lens(finalist_1, finalist_2, finalist_3);

    return 0;

}

