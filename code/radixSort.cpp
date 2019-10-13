/* Radix function example 
 * @Ruxandra Avram
 * C++11 (use the -std=c++11 for compilation)
*/

#include <iostream>
#include <vector>
#include <algorithm>

void sortByNthDigit(std::vector<int> &v, int n) 
{
  std::vector<int> digitCount(10, 0);
  std::vector<int> helper(v.size());

  for (auto elem : v) {
    digitCount[(elem / n) % 10]++;
  }

  for (int i = 1; i < 10; ++i) {
    digitCount[i] += digitCount[i - 1];
  }
  
  for (int i = v.size() - 1; i >= 0; --i) {
    helper[digitCount[(v[i] / n) % 10] - 1] = v[i];
    digitCount[(v[i] / n) % 10]--;
  }

  for (int i = 0; i < v.size(); ++i) {
    v[i] = helper[i];
  }
}

/* Sorting function */
void radixSort(std::vector<int> &v) 
{
  int max = *std::max_element(v.begin(), v.end());

  for (int currDigit = 1; max / currDigit > 0; currDigit *= 10) {
    sortByNthDigit(v, currDigit);
  }
}


int main() {
    std::vector<int> v = {7, 243, 43, 254535, 21, 434, 44444};
    std::cout << "Before sorting:\n";
    
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    radixSort(v);
    std::cout << "\nAfter sorting:\n";
    
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    return 0;
}