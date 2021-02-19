#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int a[1001];
int b[1001];

void solve(int i, int left, int right) {
	if (left > right)
		return;
	if (left == right) {
		cout << a[i] << " ";
		return;
	}

	int temp = b[a[i]];
	solve(i + 1, left, temp - 1);
	solve(i + temp - left + 1, temp + 1, right);
	cout << a[i] << " ";
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N)
			cin >> a[i];
		FOR(i, 1, N) {
			int temp;
			cin >> temp;
			b[temp] = i;
		}
		solve(1, 1, N);
		cout << "\n";
	}

	return 0;
}