#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[200001];
int ans[200001];
int pos[200001];
vector<int> v;
vector<pii> ans_v;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int len = 1;
	ans[1] = arr[1];
	pos[1] = 1;
	FOR(i, 2, N) {
		int idx = upper_bound(ans + 1, ans + len + 1, arr[i]) - ans;
		ans[idx] = arr[i];
		if (idx > len)
			len++;
		pos[i] = idx;
	}
	int num = len;
	ROF(i, N, 1) {
		if (pos[i] == num) {
			v.push_back(arr[i]);
			num--;
		}
	}
	int vlen = v.size();
	if (N - vlen > 3) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	int idx = vlen - 1;
	FOR(i, 1, N) {
		if (idx < 0) {
			arr[i] = arr[i - 1];
			ans_v.push_back({ i, arr[i - 1] });
			continue;
		}
		if (v[idx] == arr[i]) {
			idx--;
		}
		else {
			if (i == 1) {
				arr[1] = 1;
				ans_v.push_back({ 1, 1 });
			}
			else {
				arr[i] = arr[i - 1];
				ans_v.push_back({ i, arr[i - 1] });
			}
		}
	}
	int ans_len = ans_v.size();
	cout << ans_len << "\n";
	FOR(i, 0, ans_len - 1)
		cout << ans_v[i].first << " " << ans_v[i].second << "\n";

	return 0;
}