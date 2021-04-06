#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int sum[26][200001] = { 0, };

int main() {
	FASTIO;
	string S;
	cin >> S;
	int len = S.size();
	FOR(i, 0, len - 1) {
		FOR(j, 0, 25) {
			int tmp = S[i] - 'a';
			sum[j][i + 1] = sum[j][i];
			if (j == tmp)
				sum[tmp][i + 1] += 1;
		}
	}
	int Q;
	cin >> Q;
	FOR(i, 1, Q) {
		char x;
		int s, e;
		cin >> x >> s >> e;
		s += 1;
		e += 1;
		cout << sum[x - 'a'][e] - sum[x - 'a'][s - 1] << "\n";
	}


	return 0;
}