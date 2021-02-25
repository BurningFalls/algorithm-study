#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
int W[10001];

int main() {
	FASTIO;
	int minimum = 200001;
	cin >> N;
	FOR(i, 1, 2 * N)
		cin >> W[i];
	sort(W + 1, W + 2 * N + 1);
	FOR(i, 1, N) {
		minimum = min(minimum, W[i] + W[2 * N - i + 1]);
	}
	cout << minimum;

	return 0;
}