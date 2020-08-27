#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int matching[1000001];
vector<int> ans;

void Find_Match(string P) {
	int len_p = P.size();
	int start = 1;
	int match = 0;
	while (start + match < len_p) {
		if (P[start + match] == P[match]) {
			match++;
			matching[start + match - 1] = match;
		}
		else {
			if (match == 0)
				start++;
			else {
				start += (match - matching[match - 1]);
				match = matching[match - 1];
			}
		}
	}
}

void KMP(string T, string P) {
	int len_t = T.size();
	int len_p = P.size();
	int match = 0;
	Find_Match(P);
	FOR(i, 0, len_t - 1) {
		while (match > 0 && T[i] != P[match])
			match = matching[match - 1];
		if (T[i] == P[match]) {
			match++;
			if (match == len_p) {
				ans.push_back(i - len_p + 2);
				match = matching[match - 1];
			}
		}
	}
}

int main() {
	string T, P;
	int len_ans;
	getline(cin, T);
	getline(cin, P);
	KMP(T, P);
	len_ans = ans.size();
	cout << len_ans << "\n";
	FOR(i, 0, len_ans - 1)
		cout << ans[i] << "\n";

	return 0;
}