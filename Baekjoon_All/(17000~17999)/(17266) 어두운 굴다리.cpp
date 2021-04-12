#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];

int main() {
	FASTIO;
	int N, M;
	int max_dist = 0;
	cin >> N;
	cin >> M;
	FOR(i, 1, M)
		cin >> arr[i];
	max_dist = max(max_dist, arr[1] - 0);
	FOR(i, 1, M - 1) {
		int tmp = max(max_dist, arr[i + 1] - arr[i]);
		max_dist = max(max_dist, (tmp - 1) / 2 + 1);
	}
	max_dist = max(max_dist, N - arr[M]);
	cout << max_dist;


	return 0;
}