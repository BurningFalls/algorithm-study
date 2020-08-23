#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

string s[100001];
map<string, int> mp;

int main() {
	FASTIO;
	int N, M;
	string str;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> str;
		s[i] = str;
		mp.insert(make_pair(str, i));
	}
	string qr;
	FOR(i, 1, M) {
		cin >> qr;
		if (qr[0] >= int('0') && qr[0] <= int('9')) {
			cout << s[stoi(qr)];
		}
		else {
			cout << mp[qr];
		}
		cout << "\n";
	}

	return 0;
}