#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int sum;
	while (true) {
		vector<int> v;
		sum = 0;
		cin >> n;
		if (n == -1) {
			break;
		}
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				v.push_back(i);
				sum += i;
			}
		}
		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
				if (i != v.size() - 1) {
					cout << " + ";
				}
			}
			cout << endl;
		}
		else {
			cout << n << " is NOT perfect." << endl;
		}
	}

	return 0;
}