#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N % 7 == 2 || N % 7 == 0)
		cout << "CY";
	else
		cout << "SK";

	return 0;
}