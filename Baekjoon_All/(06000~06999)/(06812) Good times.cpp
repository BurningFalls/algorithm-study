#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int n;
	string s[7] = { "Ottawa", "Victoria", "Edmonton", "Winnipeg", "Toronto", "Halifax", "St. John's" };
	int num[7] = { 0, };
	cin >> n;
	n = (n / 100) * 60 + (n % 100);
	num[0] = n;
	num[1] = n - 180;
	num[2] = n - 120;
	num[3] = n - 60;
	num[4] = n;
	num[5] = n + 60;
	num[6] = n + 90;
	FOR(i, 0, 6) {
		if (num[i] < 0) {
			num[i] += 1440;
		}
		else if (num[i] >= 1440) {
			num[i] -= 1440;
		}
	}
	FOR(i, 0, 6) {
		int a = num[i] / 60;
		int b = num[i] % 60;
		if (a != 0) {
			cout << a;
			if (b < 10) {
				cout << '0';
			}
			cout << b;
		}
		else if (a == 0) {
			cout << b;
		}
		cout << " in " << s[i] << "\n";
	}

	return 0;
}