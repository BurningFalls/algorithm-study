#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int N;
	vector<pair<int, int>> time_v;
	vector<pair<int, int>>::iterator iter;
	int x, y;
	int ans = 1;
	int finish_time;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		time_v.push_back(make_pair(x, y));
	}
	sort(time_v.begin(), time_v.end(), compare);
	iter = time_v.begin();
	finish_time = (*iter).second;
	iter++;
	while (iter != time_v.end()) {
		if ((*iter).first >= finish_time) {
			ans++;
			finish_time = (*iter).second;
		}
		iter++;
	}
	cout << ans;

	return 0;
}