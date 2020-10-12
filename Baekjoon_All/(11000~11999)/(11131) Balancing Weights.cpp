#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int W[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int num;
		int sum = 0;
		cin >> N;
		FOR(i, 1, N) {
			cin >> num;
			sum += num;
		}
		if (sum < 0)
			cout << "Left";
		else if (sum > 0)
			cout << "Right";
		else if (sum == 0)
			cout << "Equilibrium";
		cout << "\n";
	}

	return 0;
}