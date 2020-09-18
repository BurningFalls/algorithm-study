#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

pair<int, int> v[1001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a] = { b, c };
	}
	bool flag = 0;
	int node = 1;
	while (node != N) {
		int x = v[node].second;
		node = v[node].first;
		if (x == 1)
			flag = !flag;
	}
	cout << flag;

	return 0;
}