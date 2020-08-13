#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	string num;
	bool flag;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> num;
		flag = next_permutation(num.begin(), num.end());
		if (!flag)
			cout << "BIGGEST\n";
		else
			cout << num << "\n";
	}

	return 0;
}