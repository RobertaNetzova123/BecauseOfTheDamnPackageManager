#include <iostream>
using namespace std;

int main() {
	double hours, rate, pay;

	cout << "How many hours did you worked: ";
	cin >> hours;
	
	cout << "How many money did you make per hour: ";
	cin >> rate;

	pay = hours * rate;
	cout << "You've earned $" << pay << endl;
	return 0;
}
