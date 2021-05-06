#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
vector<int> v;

int main() {
	FASTIO;
	int num;
	cin >> N;
	FOR(i, 1, N) {
		int ans = 0;
		FOR(j, 1, N) {
			cin >> num;
			ans |= num;
		}
		v.push_back(ans);
	}
	for (int x : v)
		cout << x << " ";

	return 0;
}