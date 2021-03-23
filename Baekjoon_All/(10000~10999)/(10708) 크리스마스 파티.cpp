#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A[101];
int arr[101][101];
int score[101] = { 0, };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, M)
		cin >> A[i];
	FOR(i, 1, M) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, M) {
		int target = A[i];
		int cnt = 0;
		FOR(j, 1, N) {
			if (arr[i][j] == target) {
				score[j]++;
				cnt++;
			}
		}
		score[target] += (N - cnt);
	}
	FOR(i, 1, N)
		cout << score[i] << "\n";


	return 0;
}