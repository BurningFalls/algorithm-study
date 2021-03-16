#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int N;
	string S;
	cin >> N >> S;
	int score = 0;
	int bonus = 0;
	FOR(i, 0, N - 1) {
		if (S[i] == 'X') {
			bonus = 0;
		}
		else if (S[i] == 'O') {
			score += (i + 1);
			score += bonus;
			bonus++;
		}
	}
	cout << score;

	return 0;
}