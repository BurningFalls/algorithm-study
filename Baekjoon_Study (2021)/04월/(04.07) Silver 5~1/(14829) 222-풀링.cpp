#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Map[1025][1025];

int CD(int sy, int sx, int size) {
	if (size == 1)
		return Map[sy][sx];
	int arr[4];
	arr[0] = CD(sy, sx, size / 2);
	arr[1] = CD(sy, sx + size / 2, size / 2);
	arr[2] = CD(sy + size / 2, sx, size / 2);
	arr[3] = CD(sy + size / 2, sx + size / 2, size / 2);
	sort(arr, arr + 4);
	return arr[2];
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	cout << CD(1, 1, N);


	return 0;
}