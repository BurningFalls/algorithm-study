#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> ans;

int main() {
	FASTIO;
	int N, K, L;
	cin >> N >> K >> L;
	FOR(i, 1, N) {
		int x1, x2, x3;
		cin >> x1 >> x2 >> x3;
		int sum = x1 + x2 + x3;
		if (sum >= K && x1 >= L && x2 >= L && x3 >= L) {
			ans.push_back(x1);
			ans.push_back(x2);
			ans.push_back(x3);
		}
	}
	int len = ans.size();
	cout << len / 3 << "\n";
	for (int n : ans)
		cout << n << " ";


	return 0;
}