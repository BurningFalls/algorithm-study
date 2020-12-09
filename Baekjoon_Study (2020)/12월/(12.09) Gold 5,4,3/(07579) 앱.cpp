#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 2100000000

pii A[101];
int max_byte[10001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> A[i].first;
	FOR(i, 1, N)
		cin >> A[i].second;
	max_byte[0] = 0;
	FOR(i, 1, 10000)
		max_byte[i] = -1;
	int sum = 0;
	FOR(i, 1, N) {
		sum += A[i].second;
		for (int j = sum; j - A[i].second >= 0; j--) {
			max_byte[j] = max(max_byte[j], max_byte[j - A[i].second] + A[i].first);
		}
	}
	FOR(i, 0, sum) {
		if (max_byte[i] >= M) {
			cout << i;
			break;
		}
	}

	return 0;
}