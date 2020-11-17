#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[100002];
vector<int> v;
int ans = 0;

int main() {
	FASTIO;
	cin >> N;
	arr[0] = 0;
	arr[N + 1] = 0;
	FOR(i, 1, N)
		cin >> arr[i];
	v.push_back(0);
	FOR(i, 1, N + 1) {
		while (!v.empty() && arr[v.back()] > arr[i]) {
			int height = arr[v.back()];
			v.pop_back();
			int width = i - v.back() - 1;
			ans = max(ans, height * width);
		}
		v.push_back(i);
	}
	cout << ans;

	return 0;
}