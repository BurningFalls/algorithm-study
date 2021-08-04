#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int two_num[9];

bool is_Prime(int x) {
	if (x == 1)
		return false;
	if (x == 2)
		return true;
	int tmp = sqrt(x);
	FOR(i, 2, tmp) {
		if (x % i == 0)
			return false;
	}
	return true;
}

bool check(int x, int goal) {
	int cnt = 0;
	FOR(i, 0, 8) {
		if (x & (1 << i))
			cnt++;
	}
	return (cnt == goal);
}

int main() {
	FASTIO;
	set<int> s;
	two_num[0] = 1;
	FOR(i, 1, 8)
		two_num[i] = two_num[i - 1] * 2;
	int N, M;
	int H[10];
	cin >> N >> M;
	FOR(i, 0, N - 1)
		cin >> H[i];
	FOR(i, 0, (1 << N) - 1) {
		if (!check(i, M)) continue;
		int sum = 0;
		FOR(j, 0, 8) {
			if (!(i & (1 << j))) continue;
			sum += H[j];
		}
		if (is_Prime(sum))
			s.insert(sum);
	}
	if (s.empty())
		cout << -1;
	else {
		for (auto it = s.begin(); it != s.end(); it++)
			cout << (*it) << " ";
	}

	return 0;
}