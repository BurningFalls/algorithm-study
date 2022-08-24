#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<char> v(N);
	int cnt = 0;
	int Lflag = 0;
	int Sflag = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}
	FOR(i, 0, N - 1) {
		if (v[i] == 'L') {
			Lflag++;
		}
		else if (v[i] == 'R') {
			if (Lflag == 0) break;
			cnt++;
			Lflag--;
		}
		else if (v[i] == 'S') {
			Sflag++;
		}
		else if (v[i] == 'K') {
			if (Sflag == 0) break;
			cnt++;
			Sflag--;
		}
		else {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}