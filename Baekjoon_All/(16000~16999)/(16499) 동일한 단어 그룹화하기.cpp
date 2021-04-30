#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

set<string> s;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		s.insert(str);
	}
	int len = s.size();
	cout << len;


	return 0;
}