#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int sum = 0;
		FOR(i, 0, 5) {
			int num;
			cin >> num;
			sum += num;
		}
		int day = 1;
		while (sum <= N) {
			sum *= 4;
			day++;
		}
		cout << day << "\n";
	}

	return 0;
}