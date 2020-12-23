#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v, v2;

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	FOR(i, 0, N - 2) {
		v2.push_back(v[i + 1] - v[i]);
	}
	sort(v2.begin(), v2.end());
	int sum = 0;
	FOR(i, 0, N - K - 1)
		sum += v2[i];
	cout << sum;

	return 0;
}