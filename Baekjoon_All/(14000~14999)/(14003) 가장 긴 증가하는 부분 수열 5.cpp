#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MAX 1000000+1
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N;
int pt[MAX];
int arr[MAX];
vector<int> v, ans;

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	v.push_back(arr[1]);
	int idx = 0;
	FOR(i, 2, N) {
		if (v[idx] < arr[i]) {
			v.push_back(arr[i]);
			idx++;
			pt[i] = idx;
		}
		else {
			int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			v[pos] = arr[i];
			pt[i] = pos;
		}
	}
	cout << idx + 1 << "\n";
	ROF(i, N, 1) {
		if (idx < 0)
			break;
		if (pt[i] == idx) {
			ans.push_back(arr[i]);
			idx--;
		}
	}
	ROF(i, ans.size() - 1, 0)
		cout << ans[i] << " ";

	return 0;
}