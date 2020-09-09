#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N;
int t[10001];
int T[10001] = { 0, };
vector<int> v[10001];
int indegree[10001] = { 0, };

void DT() {
	queue<int> q;
	FOR(i, 1, N) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		int len = v[n].size();
		FOR(i, 0, len - 1) {
			int nn = v[n][i];
			T[nn] = max(T[nn], T[n] + t[nn]);
			indegree[nn]--;
			if (indegree[nn] == 0)
				q.push(nn);
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> t[i];
		T[i] = t[i];
		int num;
		cin >> num;
		FOR(j, 1, num) {
			int x;
			cin >> x;
			v[x].push_back(i);
		}
		indegree[i] += num;
	}
	DT();
	cout << *max_element(T + 1, T + N + 1);

	return 0;
}