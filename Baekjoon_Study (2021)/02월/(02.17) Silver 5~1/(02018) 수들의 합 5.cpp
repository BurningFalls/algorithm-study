#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int N;
	int pos = 2;
	int sum = 3;
	int cnt = 1;
	cin >> N;
	while (sum <= N) {
		if ((N - sum) % pos == 0) {
			cnt++;
		}
		pos++;
		sum += pos;
	}
	cout << cnt;

	return 0;
}