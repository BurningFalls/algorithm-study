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
		double arr[7];
		FOR(i, 0, 6)
			cin >> arr[i];
		double ans = 0;
		double A, B, C;
		A = 9.23076, B = 26.7, C = 1.835;
		ans += floor(A * pow(B - arr[0], C));
		A = 1.84523, B = 75, C = 1.348;
		ans += floor(A * pow(arr[1] - B, C));
		A = 56.0211, B = 1.5, C = 1.05;
		ans += floor(A * pow(arr[2] - B, C));
		A = 4.99087, B = 42.5, C = 1.81;
		ans += floor(A * pow(B - arr[3], C));
		A = 0.188807, B = 210, C = 1.41;
		ans += floor(A * pow(arr[4] - B, C));
		A = 15.9803, B = 3.8, C = 1.04;
		ans += floor(A * pow(arr[5] - B, C));
		A = 0.11193, B = 254, C = 1.88;
		ans += floor(A * pow(B - arr[6], C));
		cout << ans << "\n";
	}

	return 0;
}