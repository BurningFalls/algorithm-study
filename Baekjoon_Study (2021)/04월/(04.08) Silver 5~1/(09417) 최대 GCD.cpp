#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	cin.ignore();
	while (N--) {
		string s;
		getline(cin, s);
		int len = s.size();
		vector<int> v;
		string tmp = "";
		FOR(i, 0, len - 1) {
			if (s[i] == ' ') {
				v.push_back(stoi(tmp));
				tmp = "";
			}
			else {
				tmp += s[i];
			}
		}
		v.push_back(stoi(tmp));
		int cnt = v.size();
		int maxi = 0;
		FOR(i, 0, cnt - 1) {
			FOR(j, 0, cnt - 1) {
				if (i == j) continue;
				maxi = max(maxi, GCD(v[i], v[j]));
			}
		}
		cout << maxi << "\n";
	}


	return 0;
}