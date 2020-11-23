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
	string s1, s2;
	cin >> N;
	FOR(i, 1, N) {
		cin >> s1 >> s2;
		if (s2 == "enter")
			s.insert(s1);
		else if (s2 == "leave")
			s.erase(s1);
	}
	auto it = s.end();
	it--;
	while (it != s.begin()) {
		cout << (*it) << "\n";
		it--;
	}
	cout << (*it);

	return 0;
}