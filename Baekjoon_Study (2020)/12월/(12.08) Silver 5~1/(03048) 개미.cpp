#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, char>

vector<pii> v;

int main() {
	FASTIO;
	int N1, N2, T;
	string s1, s2;
	cin >> N1 >> N2;
	cin >> s1 >> s2;
	cin >> T;
	ROF(i, s1.size() - 1, 0)
		v.push_back({ 1, s1[i] });
	FOR(i, 0, s2.size() - 1)
		v.push_back({ -1, s2[i] });
	int len = v.size();
	while (T--) {
		FOR(i, 0, len - 2) {
			if (v[i].first == 1 && v[i + 1].first == -1) {
				swap(v[i], v[i + 1]);
				i++;
			}
		}
	}
	FOR(i, 0, len - 1)
		cout << v[i].second;

	return 0;
}