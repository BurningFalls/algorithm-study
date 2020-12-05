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
		pii arr[4];
		FOR(i, 0, 3)
			cin >> arr[i].first >> arr[i].second;
		vector<int> v;
		FOR(i, 0, 3) {
			FOR(j, i + 1, 3) {
				v.push_back((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));
			}
		}
		sort(v.begin(), v.end());
		if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5])
			cout << 1;
		else
			cout << 0;
		cout << "\n";
	}

	return 0;
}