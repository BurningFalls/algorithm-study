#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1000001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i];
		}
		sort(arr + 1, arr + N + 1);
		cin >> M;
		FOR(i, 1, M) {
			int quest;
			cin >> quest;
			if (binary_search(arr + 1, arr + N + 1, quest))
				cout << 1;
			else
				cout << 0;
			cout << "\n";
		}
	}

	return 0;
}