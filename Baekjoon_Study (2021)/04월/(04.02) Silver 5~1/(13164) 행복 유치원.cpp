#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[300001];
vector<int> v;

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, 1, N - 1) {
		v.push_back(arr[i + 1] - arr[i]);
	}
	sort(v.begin(), v.end());
	ll sum = 0;
	FOR(i, 0, N - K - 1)
		sum += v[i];
	cout << sum;


	return 0;
}