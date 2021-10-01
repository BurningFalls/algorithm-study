#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

struct NODE {
	int left;
	int right;
};

NODE arr[200001];
vector<int> L, R;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		L.clear();
		R.clear();
		int N;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr[i].left >> arr[i].right;
			L.push_back(arr[i].left);
			R.push_back(arr[i].right);
		}
		sort(L.begin(), L.end());
		sort(R.begin(), R.end());
		int mini = N;
		FOR(i, 1, N) {
			int left = lower_bound(R.begin(), R.end(), arr[i].left) - R.begin();
			int right = N - (upper_bound(L.begin(), L.end(), arr[i].right) - L.begin());
			mini = min(mini, left + right);
		}
		cout << mini << "\n";
	}

	return 0;
}