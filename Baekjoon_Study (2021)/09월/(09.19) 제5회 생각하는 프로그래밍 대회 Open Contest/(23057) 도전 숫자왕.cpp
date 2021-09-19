#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

set<int> s;

int main() {
	FASTIO;
	int N;
	int arr[21] = { 0, };
	cin >> N;
	int total_sum = 0;
	FOR(i, 0, N - 1) {
		cin >> arr[i];
		total_sum += arr[i];
	}
	FOR(i, 1, (1 << N) - 1) {
		int sum = 0;
		FOR(j, 0, N - 1) {
			if (i & (1 << j))
				sum += arr[j];
		}
		s.insert(sum);
	}
	cout << total_sum - LEN(s);

	return 0;
}