#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 987654321

int N;
int Cost[17][17];
int P;
int DP[1 << 17];
int cnt = 0;
int Bit;

int DFS(int bm) {
	int& ret = DP[bm];
	if (ret != -1)
		return ret;
	if (cnt >= P)
		return ret = 0;
	ret = INF;
	cnt++;
	for (int i = 0; i < N; i++) {
		if (!(bm & (1 << i))) continue;
		for (int j = 0; j < N; j++) {
			if (bm & (1 << j)) continue;
			ret = min(ret, DFS(bm | (1 << j)) + Cost[i][j]);
		}
	}
	cnt--;
	return ret;
}

int main() {
	int temp;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char state;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Cost[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> state;
		if (state == 'Y') {
			Bit |= 1 << i;
			cnt++;
		}
	}
	cin >> P;
	memset(DP, -1, sizeof(DP));
	temp = DFS(Bit);
	if (temp == INF)
		cout << -1;
	else
		cout << temp;

	return 0;
}