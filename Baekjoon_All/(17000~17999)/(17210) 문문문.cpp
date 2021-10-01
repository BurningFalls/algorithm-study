#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	ll N;
	int num;
	cin >> N >> num;
	if (N > 5)
		cout << "Love is open door";
	else {
		FOR(i, 2, N) {
			num = 1 - num;
			cout << num << "\n";
		}
	}

	return 0;
}