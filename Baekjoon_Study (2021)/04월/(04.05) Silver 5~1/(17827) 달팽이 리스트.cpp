#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int C[200001];

int main() {
	FASTIO;
	int N, M, V;
	cin >> N >> M >> V;
	FOR(i, 1, N)
		cin >> C[i];
	FOR(i, 1, M) {
		int K;
		cin >> K;
		K += 1;
		if (K < V)
			cout << C[K];
		else
			cout << C[(K - V) % (N - V + 1) + V];
		cout << "\n";
	}


	return 0;
}