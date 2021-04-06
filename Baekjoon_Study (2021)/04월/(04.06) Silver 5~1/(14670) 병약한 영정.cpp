#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, R;
	int arr[101];
	bool died[101] = { 0, };
	vector<int> v[101];
	cin >> N;
	memset(arr, -1, sizeof(arr));
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}
	cin >> R;
	FOR(i, 1, R) {
		int cnt;
		cin >> cnt;
		FOR(j, 1, cnt) {
			int t;
			cin >> t;
			v[i].push_back(arr[t]);
			if (arr[t] == -1)
				died[i] = true;
		}
	}
	FOR(i, 1, R) {
		if (died[i])
			cout << "YOU DIED";
		else {
			for (int n : v[i])
				cout << n << " ";
		}
		cout << "\n";
	}

	return 0;
}