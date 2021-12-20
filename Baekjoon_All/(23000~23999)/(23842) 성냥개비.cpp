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

int N;
int choice[6];
int num_cnt[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

void DFS(int cnt, int sum) {
	if (cnt == 6) {
		if (sum + 4 == N) {
			int n1 = choice[0] * 10 + choice[1];
			int n2 = choice[2] * 10 + choice[3];
			int n3 = choice[4] * 10 + choice[5];
			if (n1 + n2 == n3) {
				cout << choice[0] << choice[1];
				cout << "+";
				cout << choice[2] << choice[3];
				cout << "=";
				cout << choice[4] << choice[5];
				exit(0);
			}
		}
		return;
	}
	FOR(i, 0, 9) {
		choice[cnt] = i;
		DFS(cnt + 1, sum + num_cnt[i]);
	}
}

int main() {
	FASTIO;
	cin >> N;
	DFS(0, 0);
	cout << "impossible";

	return 0;
}