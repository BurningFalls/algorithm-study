#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	string S;
	int arr[26] = { 0, };
	cin >> S;
	FOR(i, 0, LEN(S) - 1) {
		arr[S[i] - 'A']++;
	}
	if (arr[0] >= 1) {
		FOR(i, 0, LEN(S) - 1) {
			if (S[i] == 'B' || S[i] == 'C' || S[i] == 'D' || S[i] == 'F')
				S[i] = 'A';
		}
	}
	else if (arr[1] >= 1) {
		FOR(i, 0, LEN(S) - 1) {
			if (S[i] == 'C' || S[i] == 'D' || S[i] == 'F')
				S[i] = 'B';
		}
	}
	else if (arr[2] >= 1) {
		FOR(i, 0, LEN(S) - 1) {
			if (S[i] == 'D' || S[i] == 'F')
				S[i] = 'C';
		}
	}
	else {
		FOR(i, 0, LEN(S) - 1) {
			S[i] = 'A';
		}
	}
	cout << S;

	return 0;
}