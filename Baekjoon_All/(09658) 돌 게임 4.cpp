#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N % 7 == 1 || N % 7 == 3)
		cout << "CY";
	else
		cout << "SK";

	return 0;
}