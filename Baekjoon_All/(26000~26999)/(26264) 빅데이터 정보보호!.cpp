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
	int N;
	string s;
	cin >> N;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	int idx = 0;
	while (idx < LEN(s)) {
		if (s[idx] == 's') {
			idx += 8;
			cnt1++;
		}
		else if (s[idx] == 'b') {
			idx += 7;
			cnt2++;
		}
	}
	if (cnt1 > cnt2) {
		cout << "security!";
	}
	else if (cnt1 < cnt2) {
		cout << "bigdata?";
	}
	else if (cnt1 == cnt2) {
		cout << "bigdata? security!";
	}

	return 0;
}