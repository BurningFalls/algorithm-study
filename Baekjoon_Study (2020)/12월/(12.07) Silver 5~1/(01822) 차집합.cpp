#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

set<int> s;

int main() {
	FASTIO;
	int NA, NB;
	int num;
	cin >> NA >> NB;
	FOR(i, 1, NA) {
		cin >> num;
		s.insert(num);
	}
	FOR(i, 1, NB) {
		cin >> num;
		if (s.count(num))
			s.erase(num);
	}
	int len = s.size();
	cout << len << "\n";
	for (auto it = s.begin(); it != s.end(); it++)
		cout << (*it) << " ";

	return 0;
}