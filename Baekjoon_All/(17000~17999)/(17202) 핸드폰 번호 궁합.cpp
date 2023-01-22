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
	string a, b;
	cin >> a >> b;
	queue<int> q;
	int stop = 15;
	int cnt = 0;
	FOR(i, 0, LEN(a) - 1) {
		q.push(a[i] - '0');
		q.push(b[i] - '0');
	}

	while (stop > 1) {
		int x = q.front();
		q.pop();
		q.push((x + q.front()) % 10);
		cnt++;
		if (cnt == stop) {
			stop--;
			cnt = 0;
			q.pop();
		}
	}

	FOR(i, 0, 1) {
		cout << q.front();
		q.pop();
	}

	return 0;
}