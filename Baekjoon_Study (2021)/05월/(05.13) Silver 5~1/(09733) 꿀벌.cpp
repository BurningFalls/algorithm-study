#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[8] = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" };
double cnt[8] = { 0, };

int main() {
	FASTIO;
	string s;
	int total_cnt = 0;
	while (cin >> s) {
		total_cnt++;
		FOR(i, 0, 6) {
			if (s == arr[i])
				cnt[i]++;
		}
	}
	FOR(i, 0, 6) {
		cout << arr[i] << " ";
		cout << cnt[i] << " ";
		cout.setf(ios::fixed);
		cout << setprecision(2) << cnt[i] / total_cnt << "\n";
		cout.unsetf(ios::fixed);
	}
	cout << "Total " << total_cnt << " 1.00";


	return 0;
}