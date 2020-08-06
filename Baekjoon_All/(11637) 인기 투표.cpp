#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	int T;
	int N;
	vector<pair<int, int>> v;
	int sum;
	int num;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		v.clear();
		sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> num;
			v.push_back(make_pair(i + 1, num));
			sum += num;
		}
		sort(v.begin(), v.end(), compare);
		if (v[0].second != v[1].second) {
			if (v[0].second > sum / 2)
				cout << "majority winner " << v[0].first << "\n";
			else
				cout << "minority winner " << v[0].first << "\n";
		}
		else if (v[0].second == v[1].second) {
			cout << "no winner\n";
		}
	}

	return 0;
}