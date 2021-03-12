#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
int B[300001];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> B[i];
	sort(B + 1, B + N + 1, cmp);
	int maximum = 0;
	int cnt = 0;
	FOR(i, 1, N) {
		if (B[i] + N >= maximum)
			cnt++;
		maximum = max(maximum, B[i] + i);
	}
	cout << cnt;

	return 0;
}