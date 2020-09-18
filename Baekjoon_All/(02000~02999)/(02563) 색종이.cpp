#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	int x, y;
	int map[100][100] = { 0, };
	int sum = 0;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < N; i++) {
		for (int j = v[i].second; j < v[i].second + 10; j++) {
			for (int k = v[i].first; k < v[i].first + 10; k++) {
				if (map[j][k] == 0) {
					map[j][k] = 1;
				}
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			sum += map[i][j];
		}
	}
	cout << sum;

	return 0;
}