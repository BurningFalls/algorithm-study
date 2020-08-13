#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	int d[51][51] = { 0, };
	int x, y;
	int peer[51];
	int maximum, minimum;
	vector<int> ans;
	cin >> N;
	while (true) {
		cin >> x >> y;
		if (x == -1 && y == -1)
			break;
		d[x][y] = 1;
		d[y][x] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (d[i][j] == 0)
				d[i][j] = N;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		maximum = -1;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			maximum = max(maximum, d[i][j]);
		}
		peer[i] = maximum;
	}
	minimum = *min_element(peer + 1, peer + (N + 1));
	for (int i = 1; i <= N; i++) {
		if (minimum == peer[i])
			ans.push_back(i);
	}

	cout << minimum << " " << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}