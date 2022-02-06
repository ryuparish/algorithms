#include <iostream>
#include <vector>

// Remove, Decrement Index, and possibly swap (I think of it more as Shift Sort)
// We first remove a gap (beginnning at the 1th element), then loop from that gap position to the beginning of the list and swap until you reach a value that is
// less than the current value in the gap.

int main() {
   
   // Read in the values
    std::vector<int> values;
   int a, gap;
   while (std::cin >> a) {
       values.push_back(a);
   }
   std::cout << "\n";

   // Perform the insertion sort from the 1th element to the (n - 1)th because the 0th element has no values to the left of it and the nth element has no value does not exist respectively
   for (int i = 1; i <= values.size()-1; ++i){
       a = values[i];

       // This will be the index where the "removed" element a will be placed when a smaller element is found, the so-called gap
       gap = i;

       // If the gap is at the last possible spot or if the value "removed" is greater than the value to the left of the gap, this while loop will stop
       // Note: the gap will always be one spot the right of values[gap - 1], so the gap cannot be 0 or else the "removed" value would be compared with values[-1] which does not exist
       while (gap > 0 && a < values[gap - 1]) {
           // Be careful to have this order. Flipping the lines below will cause indexing to values[gap - 2]
           values[gap] = values[gap - 1];
           gap = gap -  1;
       }
       values[gap] = a;
   }

   for (int i = 0; i < values.size(); ++i) {
       std::cout << values[i] << " ";
   }
   std::cout << "\n";
}


