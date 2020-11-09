#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[3001][4];
int Parent[3001];
int cnt[3001] = { 0, };

int Find_Parent(int node) {
	if (Parent[node] == node)
		return node;
	return Parent[node] = Find_Parent(Parent[node]);
}

void Union(int n1, int n2) {
	n1 = Find_Parent(n1);
	n2 = Find_Parent(n2);
	if (n1 != n2)
		Parent[n2] = n1;
}

int ccw(pii a, pii b, pii c) {
	int x = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
	int y = (b.first * a.second) + (c.first * b.second) + (a.first * c.second);
	if (x - y > 0)
		return 1;
	else if (x - y == 0)
		return 0;
	else if (x - y < 0)
		return -1;
}

bool is_cross(pii a, pii b, pii c, pii d) {
	int ccw1 = ccw(a, b, c) * ccw(a, b, d);
	int ccw2 = ccw(c, d, a) * ccw(c, d, b);
	if (ccw1 == 0 && ccw2 == 0) {
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);
		return a <= d && c <= b;
	}
	return ccw1 <= 0 && ccw2 <= 0;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 0, 3) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, N)
		Parent[i] = i;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			if (is_cross({ arr[i][0], arr[i][1] }, { arr[i][2], arr[i][3] },
				{ arr[j][0], arr[j][1] }, { arr[j][2], arr[j][3] })) {
				Union(i, j);
			}
		}
	}
	FOR(i, 1, N) {
		int p = Find_Parent(i);
		cnt[p]++;
	}
	int group_cnt = 0;
	int maximum = 0;
	FOR(i, 1, N) {
		if (cnt[i] == 0) continue;
		group_cnt++;
		maximum = max(maximum, cnt[i]);
	}
	cout << group_cnt << "\n" << maximum;

	return 0;
}