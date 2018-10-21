#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {
  
  srand(time(NULL));
  
  bool win;
  int n, tries = 5, ntry, max = 10;
  n = rand() % max;


  for (int x = tries; x > 0; x--) {
  
    cout << endl << "Insert your try." << endl;
    cin >> ntry;
    
    if (ntry == n) {
    
      x = 0;
      win = true;
    
	} else if (ntry > n) {
		
		cout << endl << "Too high." << endl;
		
	} else if (ntry < n) {
		
		cout << endl << "Too low." << endl;
		
	}
    
  
  }
  
  if (!win) {
  
    cout << endl << "You lose!" << endl;
  
  } else if (win) {
  
    cout << endl << "You won!" << endl;
  
  }
  
}
