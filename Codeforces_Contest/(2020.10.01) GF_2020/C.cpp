#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	cout << fixed << setprecision(6);
	while (T--) {
		int n, l;
		cin >> n >> l;
		FOR(i, 1, n)
			cin >> arr[i];
		double pos1 = 0, pos2 = l;
		int idx1 = 1, idx2 = n;
		double speed1 = 1, speed2 = 1;
		double ans = 0;
		while (idx1 <= idx2) {
			double time1 = (arr[idx1] - pos1) / speed1;
			double time2 = (pos2 - arr[idx2]) / speed2;
			if (time1 < time2) {
				pos1 = arr[idx1];
				idx1++;
				speed1++;
				pos2 -= time1 * speed2;
				ans += time1;
			}
			else if (time1 > time2) {
				pos2 = arr[idx2];
				idx2--;
				speed2++;
				pos1 += time2 * speed1;
				ans += time2;
			}
			else if (time1 == time2) {
				pos1 = arr[idx1];
				idx1++;
				speed1++;
				pos2 = arr[idx2];
				idx2--;
				speed2++;
				ans += time1;
			}
		}
		ans += (pos2 - pos1) / (speed1 + speed2);
		cout << ans << "\n";
	}

	return 0;
}