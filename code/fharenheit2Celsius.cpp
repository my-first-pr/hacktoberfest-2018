#include <iostream>

using namespace std;

int main() {
	double temperature;
	double conversion;

	cout << "Insert temperature on Fahrenheit: ";
	cin >> temperature;

	conversion = 5.0 / 9.0 * (temperature - 32.0);
	cout << temperature << " degrees Fharenheit on Celsius  " << conversion << " degrees Celsius";

	return 0;
}