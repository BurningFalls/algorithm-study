#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define FAIL 9

const int tr[10][2] = {
	{5, 1}, // 0
	{2, FAIL}, // 1
	{3, FAIL}, // 2
	{3, 4}, // 3
	{5, 7}, // 4
	{FAIL, 6}, // 5
	{5, 1}, // 6
	{8, 7}, // 7
	{3, 6}, // 8
	{FAIL, FAIL} // 9
};


bool chk(string seq) {
	int state = 0;
	for (size_t i = 0; i < seq.size(); i++) {
		char ch = seq[i] - '0';
		state = tr[state][ch];
	}
	return state == 4 or state == 6 or state == 7;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		string seq;
		cin >> seq;
		bool ans = chk(seq);
		cout << (ans ? "YES" : "NO");
		cout << "\n";
	}

	return 0;
}