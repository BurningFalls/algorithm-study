#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<ll, int>
#define LEN(s) int(s.size())

pii arr[200001];
ll sum[200001];

bool cmp(pii a, pii b) {
	return a.first < b.first;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N) {
			ll num;
			cin >> num;
			arr[i] = { num, i };
		}
		sort(arr + 1, arr + N + 1, cmp);
		sum[0] = 0;
		FOR(i, 1, N)
			sum[i] = sum[i - 1] + arr[i].first;
		vector<int> ans_v;
		ans_v.push_back(arr[N].second);
		ROF(i, N - 1, 1) {
			if (sum[i] >= arr[i + 1].first)
				ans_v.push_back(arr[i].second);
			else
				break;
		}
		sort(ans_v.begin(), ans_v.end());
		cout << LEN(ans_v) << "\n";
		for (int n : ans_v)
			cout << n << " ";
		cout << "\n";
	}

	return 0;
}