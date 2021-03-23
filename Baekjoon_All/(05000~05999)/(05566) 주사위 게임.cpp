#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];
int dice[1001];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, 1, M)
		cin >> dice[i];
	int pos = 1;
	int dice_idx = 1;
	while (true) {
		pos += dice[dice_idx];
		if (pos >= N)
			break;
		pos += arr[pos];
		if (pos >= N)
			break;
		dice_idx++;
	}
	cout << dice_idx;

	return 0;
}