#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	Date A, B, result;
	int days = 0;
	int UserVariant = -1;
	while (UserVariant != 0) {
		cout << "Enter variant: ";
		cin >> UserVariant;
		switch (UserVariant) {
		case 1:
			cout << "Enter date:\n";
			cin >> A >> B;
			break;
		case 2:
			cout << "Enter days: ";
			cin >> days;
			break;
		case 3:
			result = A - B;
			break;
		case 4:
			result = A + B;
			break;
		case 5:
			A += days;
			break;
		case 6:
			A -= days;
			break;
		case 7:
			cout << result;
			break;
		default:
			break;
		}
	}
}