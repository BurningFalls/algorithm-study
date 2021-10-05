#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int Scnt[26] = { 0, };

bool Check(string S, string T) {
	if (LEN(S) > LEN(T))
		return false;
	int Tcnt[26] = { 0, };
	FOR(i, 0, LEN(S) - 1) {
		Tcnt[T[i] - 'a']++;
	}
	FOR(i, 0, LEN(T) - LEN(S)) {
		int Sbig = 0;
		int Tbig = 0;
		int same = 0;
		FOR(j, 0, 25) {
			if (Scnt[j] + 1 == Tcnt[j])
				Tbig++;
			else if (Scnt[j] == Tcnt[j] + 1)
				Sbig++;
			else if (Scnt[j] == Tcnt[j])
				same++;
		}
		if (LEN(S) != LEN(T) && same == 26)
			return true;
		if (Tbig == 1 && Sbig == 1 && same == 24)
			return true;
		if (i == (LEN(T) - LEN(S))) continue;
		Tcnt[T[i] - 'a']--;
		Tcnt[T[i + LEN(S)] - 'a']++;
	}
	return false;
}

int main() {
	FASTIO;
	string S, T;
	int N;
	cin >> S;
	FOR(i, 0, LEN(S) - 1)
		Scnt[S[i] - 'a']++;
	cin >> N;
	FOR(i, 1, N) {
		cin >> T;
		cout << (Check(S, T) ? "YES" : "NO") << "\n";
	}

	return 0;
}