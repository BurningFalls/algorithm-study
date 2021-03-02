#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int H[1001];

int main() {
	FASTIO;
	int N, L;
	cin >> N >> L;
	FOR(i, 1, N)
		cin >> H[i];
	sort(H + 1, H + N + 1);
	FOR(i, 1, N) {
		if (H[i] <= L)
			L++;
		else
			break;
	}
	cout << L;

	return 0;
}