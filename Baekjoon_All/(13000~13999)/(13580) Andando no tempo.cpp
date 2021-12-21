#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

bool Check(int a, int b, int c) {
	if (a == b || b == c || c == a) {
		return true;
	}
	if (a + b == c) {
		return true;
	}
	if (b + c == a) {
		return true;
	}
	if (c + a == b) {
		return true;
	}
	return false;
}

int main() {
	FASTIO;
	int a, b, c;
	cin >> a >> b >> c;
	cout << (Check(a, b, c) ? 'S' : 'N');


	return 0;
}