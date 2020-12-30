#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

char grade[6] = { 'B', 'S', 'G', 'P', 'D' };
int score[6];

int main() {
	FASTIO;
	int N;
	int s, g, p, d;
	string S;
	cin >> N;
	cin >> s >> g >> p >> d;
	cin >> S;
	score[0] = 0;
	score[1] = s;
	score[2] = g;
	score[3] = p;
	score[4] = d;
	int past = 0;
	int sum = 0;
	FOR(i, 0, N - 1) {
		int idx1, idx2;
		FOR(j, 0, 4) {
			if (S[i] == grade[j])
				idx1 = j;
			if (i != N - 1 && S[i + 1] == grade[j])
				idx2 = j;
		}
		int left, right;
		if (idx1 == 4) {
			left = score[4];
		}
		else {
			left = score[idx1 + 1] - 1 - past;
		}
		if (i == N - 1 || idx2 == 4)
			right = INF;
		else
			right = score[idx2 + 1] - 1;
		sum += min(left, right);
		past = min(left, right);
	}
	cout << sum;

	return 0;
}