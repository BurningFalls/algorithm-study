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
	cout << fixed << setprecision(6);
	while (T--) {
		int N;
		double maxi = -1000000001;
		long double sum = 0;
		cin >> N;
		FOR(i, 1, N) {
			double num;
			cin >> num;
			maxi = max(maxi, num);
			sum += num;
		}
		cout << (sum - maxi) / (N - 1) + maxi << "\n";
	}


	return 0;
}