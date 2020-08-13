#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << max(C - B, B - A) - 1;

	return 0;
}