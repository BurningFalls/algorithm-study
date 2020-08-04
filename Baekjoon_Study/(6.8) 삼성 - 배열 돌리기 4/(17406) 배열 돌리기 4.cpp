#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M, K;
int ori_map[51][51];
int map[51][51];
vector<tuple<int, int, int>> rotate_inf_v;
bool visited[7] = { 0, };
int order[7];
int ans = 5100;

void Copy_Map() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = ori_map[i][j];
		}
	}
}

void Rotate() {
	int r, c, s;
	int temp;
	for (int x = 0; x < K; x++) {
		r = get<0>(rotate_inf_v[order[x]]);
		c = get<1>(rotate_inf_v[order[x]]);
		s = get<2>(rotate_inf_v[order[x]]);
		for (int i = 1; i <= s; i++) {
			temp = map[r - i][c - i];
			for (int j = 0; j < 2 * i; j++) {
				map[(r - i) + j][c - i] = map[(r - i) + j + 1][c - i];
			}
			for (int j = 0; j < 2 * i; j++) {
				map[r + i][(c - i) + j] = map[r + i][(c - i) + j + 1];
			}
			for (int j = 0; j < 2 * i; j++) {
				map[(r + i) - j][c + i] = map[(r + i) - j - 1][c + i];
			}
			for (int j = 0; j < 2 * i; j++) {
				if (j == (2 * i - 1))
					map[r - i][(c + i) - j] = temp;
				else
					map[r - i][(c + i) - j] = map[r - i][(c + i) - j - 1];
			}
		}
	}
}

int Calculate() {
	int minimum = 5100;
	int sum;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += map[i][j];
		}
		minimum = min(minimum, sum);
	}
	return minimum;
}

void Set_Order(int cnt) {
	if (cnt == K) {
		Copy_Map();
		Rotate();
		ans = min(ans, Calculate());
		return;
	}

	for (int i = 1; i <= K; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		order[cnt] = i;
		Set_Order(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	int r, c, s;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> ori_map[i][j];
		}
	}
	rotate_inf_v.push_back(make_tuple(0, 0, 0));
	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		rotate_inf_v.push_back(make_tuple(r, c, s));
	}

	Set_Order(0);

	cout << ans;

	return 0;
}