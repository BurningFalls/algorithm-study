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
	int N, M;
	cin >> N;
	vector<int> A(N), B(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	queue<int> q;
	FOR(i, 0, N - 1) {
		cin >> B[i];
	}
	ROF(i, N - 1, 0) {
		if (A[i] == 0) {
			q.push(B[i]);
		}
	}
	cin >> M;
	FOR(i, 0, M - 1) {
		int num;
		cin >> num;
		q.push(num);
	}
	FOR(i, 1, M) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}