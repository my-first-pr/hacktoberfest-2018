/*
 Author: Nabil M.
 Purpose: Search for elements in an array
 Content: Implementation of binary search algorithm
 
 Assumptions/Limitations: It is assumed that the input array is sorted.
 Further Steps: Sort input array in order of increasing input value.
*/

#include < iostream >
  using namespace std;
int arraySize, numQueries;

int main() {
  cout << "Enter the array size: " << endl;
  cin >> arraySize;
  int inputArray[arraySize];

  for (int arrCounter = 0; arrCounter < arraySize; arrCounter++) { //user inputs array elements to be queried
    cin >> inputArray[arrCounter];
  }

  cout << "Enter numQueries: " << endl;
  std::cin >> numQueries;

  int qAnswer[numQueries]; //stores binary search results --> index of queried number
  int current = 0;

  while (current < numQueries) { //iterates through every search query
    int low = 0, high = arraySize; //lowest and highest indices of inputArray

    int qInput;
    cout << "what do you want to search: " << endl;
    cin >> qInput; //the user's current query input

    while (low <= high) { //binary search is implemented here
      int mid = (low + high) / 2;
      if (inputArray[mid] == qInput) { //if search is complete
        qAnswer[current] = mid + 1; //update qAnswer w/ answer to latest user query
        cout << "located in rank: " << mid << endl;
        break;
      } else if (inputArray[mid] > qInput) {
        cout << "mid is greater than input" << endl;
        high = mid - 1;
      } else if (inputArray[mid] < qInput) {
        cout << "mid is less than input" << endl;
        low = mid + 1;
      }
    }

    current += 1;
  }

  cout << "The answers are: " << endl;

  for (int ansCounter = 0; ansCounter < numQueries; ansCounter++) {
    cout << qAnswer[ansCounter] << endl;
  }

}
