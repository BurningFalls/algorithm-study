#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M, K;
double maximum[101] = { 0, };
priority_queue<double> pq;
double sum = 0;

int main() {
	FASTIO;
	cin >> N >> M >> K;
	FOR(i, 1, M) {
		FOR(i, 1, N) {
			int player;
			double ability;
			cin >> player >> ability;
			maximum[player] = max(maximum[player], ability);
		}
	}
	FOR(i, 1, N)
		pq.push(maximum[i]);
	FOR(i, 1, K) {
		sum += pq.top();
		pq.pop();
	}
	cout << fixed << setprecision(1);
	cout << sum;

	return 0;
}