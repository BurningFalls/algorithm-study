#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];
vector<int> v;

int main() {
	FASTIO;
	int N, M;
	int ans = 0;
	int left_sum = 0;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> arr[i];
		if (arr[i] == 10)
			ans++;
		else if (arr[i] % 10 == 0) {
			v.push_back(arr[i]);
		}
		else {
			left_sum += arr[i] / 10;
		}
	}
	int vlen = v.size();
	sort(v.begin(), v.end());
	for (int x : v) {
		int cut = x / 10 - 1;
		if (M >= cut) {
			ans += cut + 1;
			M -= cut;
		}
		else if (M < cut) {
			ans += M;
			M = 0;
			break;
		}
	}
	ans += min(M, left_sum);
	cout << ans;

	return 0;
}