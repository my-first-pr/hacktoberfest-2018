#include <iostream>

using namespace std;


long int recursiveFatorial(long n) {
	

	if (n >= 1) 
		return n * recursiveFatorial(n - 1);
	else
		return 1;
}


int main(int argc, char **argv) {
	int n = 0;
	
	cout << "Enter a number: ";
	cin >> n;
	
	cout << n << "! = ";
	cout <<  recursiveFatorial(n) << endl;

	return 0;
}
