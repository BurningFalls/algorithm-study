#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[50001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}
	int t = 0;
	FOR(i, 1, N) {
		int x = arr[i].first;
		int y = arr[i].second;
		if (t % (x + y) < y)
			t += y - t % (x + y);
		t += 1;
	}
	cout << t;

	return 0;
}