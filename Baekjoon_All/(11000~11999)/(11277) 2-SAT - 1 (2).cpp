#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
int a[101];
int b[101];

bool func(int x, int y) {
	return x < 0 ? !((y >> -x - 1) % 2) : (y >> x - 1) % 2;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M)
		cin >> a[i] >> b[i];
	bool ans = false;
	FOR(i, 0, (1 << N) - 1) {
		bool flag = true;
		FOR(j, 1, M) {
			flag &= func(a[j], i) | func(b[j], i);
		}
		ans |= flag;
	}
	cout << ans;

	return 0;
}