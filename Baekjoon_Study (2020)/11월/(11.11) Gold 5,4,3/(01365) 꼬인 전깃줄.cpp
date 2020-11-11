#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
vector<int> v;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	v.push_back(arr[1]);
	FOR(i, 2, N) {
		if (v.back() < arr[i])
			v.push_back(arr[i]);
		else {
			auto it = lower_bound(v.begin(), v.end(), arr[i]);
			*it = arr[i];
		}
	}
	int len = v.size();
	cout << N - len;

	return 0;
}