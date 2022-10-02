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
	int N, M;
	string A, B;
	cin >> N >> A >> M >> B;

	vector<int> Acnt(26, 0), Bcnt(26, 0);
	FOR(i, 0, N - 1) {
		Acnt[A[i] - 'a']++;
	}
	FOR(i, 0, M - 1) {
		Bcnt[B[i] - 'a']++;
	}
	bool flag = true;
	FOR(i, 0, 25) {
		if (Bcnt[i] && !Acnt[i]) {
			flag = false;
			break;
		}
	}
	if (!flag) {
		cout << -1;
		return 0;
	}

	int Aidx = N - 1, Bidx = 0;
	int cnt = 0;
	while (Bidx < M) {
		Aidx = (Aidx + 1) % N;
		cnt++;
		while (B[Bidx] != A[Aidx]) {
			Aidx = (Aidx + 1) % N;
			cnt++;
		}
		Bidx++;
	}
	cout << cnt;

	return 0;
}