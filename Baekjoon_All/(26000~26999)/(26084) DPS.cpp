#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	string S;
	cin >> S;
	int N;
	cin >> N;
	ll a = 0, b = 0, c = 0;
	FOR(i, 0, N - 1) {
		string str;
		cin >> str;
		if (str[0] == S[0]) a++;
		if (str[0] == S[1]) b++;
		if (str[0] == S[2]) c++;
	}

	ll ans = 0;
	if (S[0] == S[1] && S[1] == S[2]) {
		ans = a * (b - 1) * (c - 2) / 6;
	}
	else if (S[0] == S[1]) {
		ans = a * (b - 1) * c / 2;
	}
	else if (S[0] == S[2]) {
		ans = a * b * (c - 1) / 2;
	}
	else if (S[1] == S[2]) {
		ans = a * b * (c - 1) / 2;
	}
	else {
		ans = a * b * c;
	}
	cout << max(0LL, ans);

	return 0;
}