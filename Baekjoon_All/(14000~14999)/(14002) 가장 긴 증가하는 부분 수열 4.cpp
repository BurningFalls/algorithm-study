#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];
int ans[1001];
int pos[1001];
vector<int> v;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	arr[0] = 0;
	int len = 1;
	ans[1] = arr[1];
	pos[1] = 1;
	FOR(i, 2, N) {
		int idx = lower_bound(ans + 1, ans + len + 1, arr[i]) - ans;
		ans[idx] = arr[i];
		if (idx > len)
			len++;
		pos[i] = idx;
	}
	cout << len << "\n";
	int num = len;
	ROF(i, N, 1) {
		if (pos[i] == num) {
			v.push_back(arr[i]);
			num--;
		}
	}
	ROF(i, v.size() - 1, 0)
		cout << v[i] << " ";

	return 0;
}