#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, Sx, Sy;
	bool row_visited[101] = { 0, };
	bool col_visited[101] = { 0, };
	int cnt = 1;
	int temp;
	cin >> n >> m >> Sx >> Sy;

	cout << Sx << " " << Sy << "\n";
	temp = Sy;
	for (int i = 1; i <= m; i++) {
		if (i == temp) continue;
		cout << Sx << " " << i << "\n";
		cnt++;
		Sy = i;
	}
	row_visited[Sx] = 1;

	if (cnt != m * n) {
		while (true) {
			for (int i = 1; i <= n; i++) {
				if (row_visited[i]) continue;
				cout << i << " " << Sy << "\n";
				cnt++;
				Sx = i;
			}
			col_visited[Sy] = 1;
			if (cnt == m * n)
				break;
			for (int i = 1; i <= m; i++) {
				if (col_visited[i]) continue;
				cout << Sx << " " << i << "\n";
				cnt++;
				Sy = i;
			}
			row_visited[Sx] = 1;
			if (cnt == m * n)
				break;
		}
	}

	return 0;
}