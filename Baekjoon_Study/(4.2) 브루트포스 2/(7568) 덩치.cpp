#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	int x, y;
	int cnt;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				cnt++;
			}
		}
		cout << cnt + 1 << " ";
	}


	return 0;
}