#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[500002];
vector<char> v;

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int cnt = 0;
	FOR(i, 1, N) {
		if (v.empty()) {
			v.push_back(arr[i]);
			continue;
		}
		while (!v.empty() && cnt != K && v.back() < arr[i]) {
			v.pop_back();
			cnt++;
		}
		v.push_back(arr[i]);
	}
	FOR(i, 0, N - K - 1)
		cout << v[i];

	return 0;
}