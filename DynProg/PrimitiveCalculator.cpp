#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <assert.h>


int DPCalculator(int &target, std::vector<int>& operations, std::vector<int>& grid){
    switch(target){
        case 1:
            std::cout << 0 << "\n" << 1;
            exit(0);
        case 2:
            std::cout << 1 << "\n" << 1 << " " << 2;
            exit(0);
        case 3:
            std::cout << 1 << "\n" << 1 << " " << 3;
            exit(0);
    }

    // Either hardcode in the value and print in the edge case that the user calls from 1-3 or
    // put in an if statement for every value. I chose to hard code this part.
    grid[0] = 0; 
    grid[1] = 1; 
    grid[2] = 1;

    // To save the choice made for each intermediate operation
    int choice;
    int candidate;

    for(int i = 4; i <= target; ++i){
        // Rare bug: Setting grid[i] (i is 4 at first) should give you an error, BUT since the vector "solution_trace" is right next to this vector in memory, it will instead change the first value of solution_trace
        grid[i - 1] = 10000000;

        // We will check the operations in this order: {0:add 1, 1:multiply by 2, 2:multiply by 3}
        for(int j = 0; j < operations.size(); ++j){
            candidate = 10000000;
            

            // Checking if it is the addition
            // -2 because the list it self starts at 1 not zero, and then we are also looking at the spot 1 behind the current location + 1
            if(j == 0){
                candidate = grid[(i - 1) - 1] + 1;
            }

            // In the case that division works with no remainder (is accurate ,exists, and is greater than the current value)
            else if(i % operations[j] == 0){
                candidate = grid[(i / operations[j]) - 1] + 1;
            }

            // Checking to see if the candidate is the smallest
            if(candidate < grid[i - 1]){
                grid[i - 1] = candidate;
                choice = j;
                assert(choice >= 0 && choice <= 2);
            }
        }

    }

    // Returning the optimal number of operations to get the target number
    return grid[target - 1];
}

// To calculate the backwards solution for printing
std::vector<int> CalculateSolutions(std::vector<int>& operations, std::vector<int>& grid, int target){
    std::vector<int> solutions_suffix_flipped;

    // Make possible candidate
    int candidate, king, choice;

    // Outer loop to keep making choices until the value is reduced to 1
    while(target != 1){
        king = 10000000;
        solutions_suffix_flipped.push_back(target);
        for(int i = 0; i < operations.size(); ++i){

            candidate = 10000000;

            // For subtracting by 1
            if(i == 0){
                candidate = grid[target - 2];
            }

            // For either dividing by 2 or 3
            if(target % operations[i] == 0){
                candidate = grid[(target / operations[i]) - 1] + 1;
            }

            if(candidate < king){
                king = candidate;
                choice = i;
            }

                    
        }
        assert(choice >= 0 && choice <= 2);

        switch(choice){
            case 0:
                target -= 1;
                break;
            case 1:
                target /= 2;
                break;
            case 2:
                target /= 3;
                break;
        }
    }
    // Solutions are backward so we need to add 1 and flip it
    solutions_suffix_flipped.push_back(1);
    std::reverse(solutions_suffix_flipped.begin(), solutions_suffix_flipped.end());
    
    return solutions_suffix_flipped;
}

                
        


int main() {
    // Since we print out the number of operations, THEN from 1 (do each operation and print the intermediate value) to the target, we need to save the values into a vector
    int target, num_operations;
    std::cin >> target;
    std::vector<int> operations{1, 2, 3};
    std::vector<int> solutions;
    // REMEMBER THIS VVVVVVVVVVVVVVV
    std::vector<int> grid(target, 0);
    num_operations = DPCalculator(target, operations, grid);
    std::cout << num_operations << "\n";
    solutions = CalculateSolutions(operations, grid, target);
    for(int i = 0; i < solutions.size(); ++i){
        std::cout << solutions[i] << " ";
    }
    return 0;
}
