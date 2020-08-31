#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N, M;
vector<int> v[1001];
int indegree[1001] = { 0, };
int ans[1001];

bool TP() {
	queue<int> q;
	FOR(i, 1, N) {
		if (indegree[i] == 0)
			q.push(i);
	}
	FOR(i, 1, N) {
		if (q.empty())
			return false;
		int n = q.front();
		q.pop();
		ans[i] = n;
		int len = v[n].size();
		FOR(j, 0, len - 1) {
			int nn = v[n][j];
			indegree[nn]--;
			if (indegree[nn] == 0)
				q.push(nn);
		}
	}
	return true;
}

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, M) {
		int cnt;
		vector<int> temp_v;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int num;
			cin >> num;
			temp_v.push_back(num);
		}
		FOR(j, 0, cnt - 2) {
			v[temp_v[j]].push_back(temp_v[j + 1]);
			indegree[temp_v[j + 1]]++;
		}
	}
	if (TP()) {
		FOR(i, 1, N)
			cout << ans[i] << "\n";
	}
	else
		cout << 0;

	return 0;
}