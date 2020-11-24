#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v[10001];
int Cnt[10001];
bool visited[10001];
int cnt;

void Func(int node) {
	int len = v[node].size();
	FOR(i, 0, len - 1) {
		int nn = v[node][i];
		if (visited[nn]) continue;
		visited[nn] = 1;
		cnt++;
		Func(nn);
		visited[nn] = 0;
	}
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, M) {
		int A, B;
		cin >> A >> B;
		v[B].push_back(A);
	}
	int maximum = 0;
	FOR(i, 1, N) {
		cnt = 0;
		visited[i] = 1;
		Func(i);
		visited[i] = 0;
		Cnt[i] = cnt;
		maximum = max(maximum, cnt);
	}
	FOR(i, 1, N) {
		if (maximum == Cnt[i])
			cout << i << " ";
	}

	return 0;
}