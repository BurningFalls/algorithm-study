#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[200001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		int sum = 0;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i];
			sum += arr[i];
		}
		if (sum % N != 0) {
			cout << -1 << "\n";
			continue;
		}
		int tmp = sum / N;
		int cnt = 0;
		FOR(i, 1, N) {
			if (arr[i] > tmp)
				cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}