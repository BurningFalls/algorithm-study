#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	int maximum = 0;
	FOR(i, 1, K) {
		int tmp = N * i;
		string s = to_string(tmp);
		reverse(s.begin(), s.end());
		int num = stoi(s);
		maximum = max(maximum, num);
	}
	cout << maximum;

	return 0;
}