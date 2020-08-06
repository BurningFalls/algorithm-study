#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int N;
	int len;
	bool flag = true;
	while (cin >> N) {
		v.push_back(N);
	}
	len = v.size();
	for (int i = 0; i < len - 1; i++) {
		if (v[i] > v[i + 1]) {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "Good";
	else
		cout << "Bad";

	return 0;
}