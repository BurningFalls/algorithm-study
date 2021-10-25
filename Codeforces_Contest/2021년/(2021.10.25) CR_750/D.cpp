#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

bool compare(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pii> v(N);
		FOR(i, 0, N - 1) {
			cin >> v[i].first;
			v[i].second = i;
		}
		sort(ALL(v));
		if (N % 2 == 0) {
			FOR(i, 0, N / 2 - 1) {
				int n1 = v[i].first;
				int n2 = v[N - 1 - i].first;
				v[i].first = n2;
				v[N - 1 - i].first = -n1;
			}
		}
		else if (N % 2 == 1) {
			int n1 = v[0].first;
			int n2 = v[1].first;
			int n3 = v[2].first;
			if (n1 + n2 != 0) {
				v[0].first = n3;
				v[1].first = n3;
				v[2].first = -(n1 + n2);
			}
			else if (n1 + n3 != 0) {
				v[0].first = n2;
				v[1].first = -(n1 + n3);
				v[2].first = n2;
			}
			else if (n2 + n3 != 0) {
				v[0].first = -(n2 + n3);
				v[1].first = n1;
				v[2].first = n1;
			}
			FOR(i, 3, (N - 3) / 2 + 2) {
				n1 = v[i].first;
				n2 = v[N + 2 - i].first;
				v[i].first = n2;
				v[N + 2 - i].first = -n1;
			}
		}
		sort(ALL(v), compare);
		FOR(i, 0, N - 1) {
			cout << v[i].first << " ";
		}
		cout << "\n";
	}


	return 0;
}