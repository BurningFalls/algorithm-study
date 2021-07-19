#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	ll x; 
	ll y;
	ll hp;
} NODE;

int N;
NODE balloon[200001];

bool cmp(NODE a, NODE b) {
	return a.hp < b.hp;
}

int BS(int d) {
	int left = 1, right = N;
	int ans = N + 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (balloon[mid].hp <= d) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	return ans;
}

int decide_dir(int x, int y) {
	if (x > 0 && y == 0)
		return 0;
	if (x > 0 && y > 0)
		return 1;
	if (x == 0 && y > 0)
		return 2;
	if (x < 0 && y > 0)
		return 3;
	if (x < 0 && y == 0)
		return 4;
	if (x < 0 && y < 0)
		return 5;
	if (x == 0 && y < 0)
		return 6;
	if (x > 0 && y < 0)
		return 7;
}

int main() {
	FASTIO;
	int M;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> balloon[i].x >> balloon[i].y >> balloon[i].hp;
	}
	int balloon_dir = decide_dir(balloon[1].x, balloon[1].y);
	sort(balloon + 1, balloon + N + 1, cmp);
	ll damage_sum = 0;
	int n = N;
	FOR(i, 1, M) {
		ll x, y, d;
		cin >> x >> y >> d;
		int gun_dir = decide_dir(x, y);
		if (balloon_dir == gun_dir &&
			balloon[1].x * y == balloon[1].y * x) {
			damage_sum += d;
			int tmp = BS(damage_sum);
			n = N - tmp + 1;
		}
		cout << n << "\n";
	}

	return 0;
}