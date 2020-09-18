#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	int cnt;
	while (true) {
		cnt = 0;
		vector<int> v;
		while (true) {
			cin >> num;
			if (num == 0 || num == -1)
				break;
			v.push_back(num);
		}
		if (num == -1)
			break;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				if (i == j) continue;
				if (v[i] * 2 == v[j]) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}