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

string S[6] = { "IN", "NU", "UI", "II", "NN", "UU" };
int Len[6] = { 0, };

void FindN(string s, int len) {
	string revs = s;
	reverse(ALL(revs));
	FOR(i, 0, 5) {
		if (s == S[i] || revs == S[i]) {
			Len[i] += len;
		}
	}
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		int len;
		cin >> s >> len;
		FindN(s, len);
	}
	if (!Len[0] && !Len[1] && !Len[2]) {
		cout << max({ Len[3], Len[4], Len[5] });
	}
	else if (Len[0] && !Len[1] && !Len[2]) {
		cout << max({ Len[5], Len[0] + Len[3] + Len[4] });
	}
	else if (!Len[0] && Len[1] && !Len[2]) {
		cout << max({ Len[3], Len[1] + Len[4] + Len[5] });
	}
	else if (!Len[0] && !Len[1] && Len[2]) {
		cout << max({ Len[4], Len[2] + Len[3] + Len[5] });
	}
	else {
		cout << Len[0] + Len[1] + Len[2] + Len[3] + Len[4] + Len[5];
	}


	return 0;
}