#include <vector>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <utility>
#include <string>

void GridFiller(std::vector< std::vector<std::pair<int, std::pair<int, int> > > >& grid, std::string& word_1, std::string& word_2){
    int n = word_2.size();
    int m = word_1.size();
    int mismatch;
    // i is down the row and j is down the column
    // Therefore , when indexing treat j as the row and i as the column
    // Outer loop is the second word since we are going left to right on the second word and going down the row for each shift leftward 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            mismatch = 1;

            // DEBUG for checking the correct letter checking
            //std::cout << "Comparing: " << word_2[i-1] << " to " << word_1[j-1] << "\n";
            if(word_1[j - 1] == word_2[i - 1]){mismatch = 0;}

            // Maybe RTW
            // If the diagonal plus the possible penalty is less than top-vertical value
            if((grid[j - 1][i - 1].first + mismatch) <= (grid[j - 1][i].first + 1)){

                // If the diagonal plus the possible penalty is less than the left-horizontal value
                if((grid[j - 1][i - 1].first + mismatch) <= (grid[j][i - 1].first + 1)){
                    // DEBUG
                    //std::cout << "Diagonal is the smallest at (" << j << "," << i << ")\n";
                    //std::cout << "Diagonal(" << j - 1 << "," << i-1 << "): " << grid[j-1][i-1].first << "\n";
                    //std::cout << "Value of mismatch: " << mismatch << "\n";
                    //std::cout << "Value of grid[j-1][i-1].first: " << grid[j-1][i-1].first << "\n";
                    // Setting the value of the edge plus the smallest value
                    grid[j][i].first = grid[j - 1][i - 1].first + mismatch;
                    // Setting the second value to be the coordinate-position of the previous spot
                    grid[j][i].second.first = j - 1;
                    grid[j][i].second.second = i - 1;
                }

                // The left-horizontal value is the smallest compared to the top-vertical value
                else {
                    // DEBUG
                    //std::cout << "Left-horizontal is the smallest at (" << j << "," << i << ")\n";
                    //std::cout << "Left-horizontal(" << j << "," << i - 1 << "): " << grid[j][i-1].first << "\n";
                    grid[j][i].first = grid[j][i - 1].first + 1;
                    grid[j][i].second.first = j;
                    grid[j][i].second.second = i - 1;
                }
            }

            // If the top-vertical value was smaller than the left-horizontal value
            else if (grid[j - 1][i].first <= grid[j][i - 1].first){
                // DEBUG
                //std::cout << "top-vertical is the smallest at (" << j << "," << i << ")\n";
                //std::cout << "top-vertical(" << j - 1 << "," << i << "): " << grid[j - 1][i].first << "\n";
                grid[j][i].first = grid[j - 1][i].first + 1;
                grid[j][i].second.first = j - 1;
                grid[j][i].second.second = i;
            }
            
            // Finally, if the left-horizontal is the smallest
            else {
                // DEBUG
                //std::cout << "left-horizontal is the smallest at (" << j << "," << i << ")\n";
                //std::cout << "left-horizontal(" << j << "," << i - 1 << "): " << grid[j][i-1].first << "\n";
                grid[j][i].first = grid[j][i - 1].first + 1;
                grid[j][i].second.first = j;
                grid[j][i].second.second = i - 1;
            }
        }
    }
}

int main() {
    std::string word_1, word_2;
    std::cin >> word_1 >> word_2;
    // Create the zero 2D vector Fill in the foundation of the DP
    // For each pair, the first value will be the # of points at that position and the second the optimal spot before it (another pair)
    std::vector< std::vector< std::pair<int , std::pair<int, int> > > > grid(word_1.size() + 1, std::vector< std::pair<int, std::pair<int , int> > >(word_2.size() + 1));
    assert(grid.size() <= word_1.size() + 1 && grid[0].size() <= word_2.size() + 1);
    
    // DEBUG
    //std::cout << "Here are the rows of the grid: " << grid.size() << " and here are the columns of the grid: " << grid[0].size() << "\n";
    // Fill in the foundation of the DP grid
    for(int i = 0; i < 2; ++i){
        // Fill in the first column point values
        if (i == 0){
            // Fill in the first row
            for(int j = 0; j < grid[0].size(); ++j){
                grid[0][j].first = j;
            }
        }
        // Fill in the second column point values
        else {
            for(int k = 0; k < grid.size(); ++k){
                grid[k][0].first = k;
            }
        }
    }

    // DEBUG
    //for(int i = 0; i < grid.size(); ++i){
    //    for(int j = 0; j < grid[0].size(); ++j){
    //        std::cout << grid[i][j].first << " ";
    //    }
    //    std::cout << "\n";
    //}

    GridFiller(grid, word_1, word_2);
    // DEBUG
    //std::cout << "\n";

    // DEBUG
    //for(int i = 0; i < grid.size(); ++i){
    //    for(int j = 0; j < grid[0].size(); ++j){
    //        std::cout << grid[i][j].first << " ";
    //    }
    //    std::cout << "\n";
    //}
    std::cout << grid[word_1.size()][word_2.size()].first;
    return 0;

}

