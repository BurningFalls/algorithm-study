#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
vector<tuple<int, int, int>> v;
bool is_use[101][101] = { 0, };

pair<int, int> Find_Tail() {
	tuple<int, int, int> node = v.back();
	pair<int, int> ans;
	int y, x, d;
	y = get<0>(node);
	x = get<1>(node);
	d = get<2>(node);
	is_use[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		if (d == i) {
			ans = make_pair(y + dy[i], x + dx[i]);
			is_use[ans.first][ans.second] = 1;
			return ans;
		}
	}
}

int main() {
	int x, y, d, g;
	pair<int, int> tail;
	int len;
	int cnt;
	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		v.clear();
		cin >> x >> y >> d >> g;
		v.push_back(make_tuple(y, x, d));
		tail = Find_Tail();
		for (int k = 1; k <= g; k++) {
			len = v.size();
			for (int j = len - 1; j >= 0; j--) {
				v.push_back(make_tuple(tail.first, tail.second, ((get<2>(v[j])) + 1) % 4));
				tail = Find_Tail();
			}
		}
	}

	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			cnt = 0;
			for (int a = 0; a <= 1; a++) {
				for (int b = 0; b <= 1; b++) {
					if (is_use[i + a][j + b])
						cnt++;
				}
			}
			if (cnt == 4)
				answer++;
		}
	}
	cout << answer;

	return 0;
}