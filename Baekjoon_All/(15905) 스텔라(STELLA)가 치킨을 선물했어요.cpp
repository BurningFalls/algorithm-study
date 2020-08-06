#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	int N;
	int x, y;
	int cnt = 0;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 5; i < N; i++) {
		if (v[i].first == v[4].first)
			cnt++;
		else
			break;
	}
	cout << cnt;

	return 0;
}