#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001] = { 0, };
bool visited[1 << 21] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int num, train, seat;
		cin >> num;
		if (num == 1) {
			cin >> train >> seat;
			arr[train] |= (1 << seat);
		}
		else if (num == 2) {
			cin >> train >> seat;
			arr[train] &= ~(1 << seat);
		}
		else if (num == 3) {
			cin >> train;
			arr[train] = arr[train] << 1;
			arr[train] &= ((1 << 21) - 1);
		}
		else if (num == 4) {
			cin >> train;
			arr[train] = arr[train] >> 1;
			arr[train] &= ~1;
		}
	}
	int cnt = 0;
	FOR(i, 1, N) {
		if (visited[arr[i]]) continue;
		visited[arr[i]] = 1;
		cnt++;
	}
	cout << cnt;


	return 0;
}