#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, score, P;
	int arr[52];
	cin >> N >> score >> P;
	FOR(i, 1, N)
		cin >> arr[i];
	arr[N + 1] = -1;
	int rank = 1;
	int ans_rank = 1;
	int pos = 1;
	FOR(i, 1, N + 1) {
		if (arr[i] > score)
			rank += 1;
		else if (arr[i] == score) {
			ans_rank = rank;
		}
		else if (arr[i] < score) {
			ans_rank = rank;
			pos = i;
			break;
		}
	}
	if (pos > P)
		cout << -1;
	else
		cout << ans_rank;

	return 0;
}