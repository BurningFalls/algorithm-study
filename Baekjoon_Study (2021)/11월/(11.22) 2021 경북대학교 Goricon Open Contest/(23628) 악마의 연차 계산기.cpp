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
	int arr[2][3];
	int day[2];
	FOR(i, 0, 1) {
		FOR(j, 0, 2) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 0, 1) {
		day[i] = 360 * arr[i][0] + 30 * arr[i][1] + arr[i][2];
	}
	int diff = day[1] - day[0];
	int a = diff / 360;
	int b = diff / 30;
	b = min(b, 36);
	if (a % 2 == 1) {
		a = 15 * a + (a / 2) * (a / 2);
	}
	else if (a % 2 == 0) {
		a = 15 * a + (a / 2) * (a / 2) - a / 2;
	}
	cout << a << " " << b << "\n" << diff << "days";

	return 0;
}