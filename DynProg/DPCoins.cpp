#include <vector>
#include <iostream>

int calculate_num_coins(int& cents, std::vector<int>& coins){
    std::vector<int> grid{cents + 1, 0};
    grid[1] = 1; grid[2] = 2; grid[3] = 1; grid[4] = 1;
    // Starting at 5 coins since we can hard code the first 5 ([0] = 0)
    int minus_1, minus_3, minus_4;
    for (int i = 5; i <= cents; ++i){
        // Obtaining all the possible smallest coin values
        minus_1 = grid[i - coins[0]] + 1;
        minus_3 = grid[i - coins[1]] + 1;
        minus_4 = grid[i - coins[2]] + 1;
        // Choosing the best choice out of the three
        if (minus_1 <= minus_3){
            if (minus_1 <= minus_4){
                grid[i] = minus_1;
            }
            grid[i] = minus_4;
        }
        else if (minus_3 <= minus_4){
            grid[i] = minus_3;
        }
        else{grid[i] = minus_4;}
    }
    return grid[cents];
}
                
        
        
int main() {
    int cents;
    std::vector<int> coins{ 1, 3 ,4 };
    std::cin >> cents;
    int num_coins = calculate_num_coins(cents, coins);
    std::cout << num_coins;
    return 0;
}
