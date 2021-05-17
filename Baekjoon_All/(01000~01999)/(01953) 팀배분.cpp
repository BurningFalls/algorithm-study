#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
bool hate[101][101] = { 0, };
int team[101] = { 0, };

void DFS(int node) {
	FOR(i, 1, N) {
		if (team[i]) continue;
		if (!hate[node][i]) continue;
		team[i] = team[node] * (-1);
		DFS(i);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int num;
			cin >> num;
			hate[i][num] = 1;
		}
	}
	FOR(i, 1, N) {
		if (team[i]) continue;
		team[i] = 1;
		DFS(i);
	}
	vector<int> v1, v2;
	FOR(i, 1, N) {
		if (team[i] == 1)
			v1.push_back(i);
		else if (team[i] == -1)
			v2.push_back(i);
	}
	int len1 = v1.size();
	int len2 = v2.size();
	cout << len1 << "\n";
	FOR(i, 0, len1 - 1)
		cout << v1[i] << " ";
	cout << "\n" << len2 << "\n";
	FOR(i, 0, len2 - 1)
		cout << v2[i] << " ";


	return 0;
}