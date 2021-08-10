#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[100001];

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			arr[i] = { num, i };
		}
		sort(arr + 1, arr + N + 1);
		FOR(i, 1, N) {
			arr[i].first = i;
		}
		sort(arr + 1, arr + N + 1, cmp);
		int cnt = 1;
		FOR(i, 1, N - 1) {
			if (arr[i].first + 1 != arr[i + 1].first) {
				cnt++;
			}
		}
		if (cnt <= K)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}


	return 0;
}