#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int K, N;
char start_res[1001];
char end_res[1001];
char tmp_res[1001];
char Map[1001][27];

bool Check() {
	FOR(i, 1, K - 1) {
		if (tmp_res[i] != end_res[i]) {
			swap(tmp_res[i], tmp_res[i + 1]);
			i++;
		}
	}
	FOR(i, 1, K) {
		if (tmp_res[i] != end_res[i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	cin >> K >> N;
	FOR(i, 1, K)
		start_res[i] = i + 'A' - 1;
	FOR(i, 1, K)
		cin >> end_res[i];
	int q_pos = 0;
	FOR(i, 1, N) {
		FOR(j, 1, K - 1) {
			cin >> Map[i][j];
			if (Map[i][j] == '?')
				q_pos = i;
		}
	}
	FOR(i, 1, q_pos - 1) {
		FOR(j, 1, K - 1) {
			if (Map[i][j] == '-') {
				swap(start_res[j], start_res[j + 1]);
			}
		}
	}
	ROF(i, N, q_pos + 1) {
		FOR(j, 1, K - 1) {
			if (Map[i][j] == '-') {
				swap(end_res[j], end_res[j + 1]);
			}
		}
	}
	
	FOR(i, 1, K)
		tmp_res[i] = start_res[i];
	if (Check()) {
		FOR(i, 1, K - 1) {
			if (start_res[i] == end_res[i + 1] && start_res[i + 1] == end_res[i])
				cout << '-';
			else
				cout << '*';
		}
	}
	else {
		FOR(i, 1, K - 1)
			cout << 'x';
	}


	return 0;
}