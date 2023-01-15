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
	int time = 1;
	bool dir = true;
	FOR(i, 0, N - 1) {
		string s; int x;
		cin >> s >> x;
		cout << time << " ";
		bool flag = true;
		if (s == "HOURGLASS" && x == time) {
			flag = false;
		}
		else if (s == "HOURGLASS") {
			flag = false;
			dir = !dir;
		}
		else if (x == time) {
			flag = true;
		}
		else {
			flag = false;
		}
		cout << (flag ? "YES" : "NO") << "\n";
		if (dir) {
			time = time % 12 + 1;
		}
		else if (!dir) {
			time = (time + 11) % 12;
			if (time == 0) time = 12;
		}
	}

	return 0;
}