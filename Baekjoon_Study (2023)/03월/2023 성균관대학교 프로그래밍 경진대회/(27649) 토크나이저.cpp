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
	getline(cin, S);
	vector<string> v;
	vector<char> tmp = { '<', '>', '&', '|', '(', ')', ' ' };
	string subs = "";
	S += " ";
	FOR(i, 0, LEN(S) - 1) {
		bool flag = false;
		int idx = 0;
		while (idx < 7) {
			if (S[i] == tmp[idx]) {
				break;
			}
			idx++;
		}
		if (idx < 7) {
			v.push_back(subs);
			subs = "";
			if (idx == 2) {
				v.push_back("&&");
				i++;
			}
			else if (idx == 3) {
				v.push_back("||");
				i++;
			}
			else if (idx != 6) {
				string t = "";
				t += tmp[idx];
				v.push_back(t);
			}
		}
		else if (idx >= 7) {
			subs += S[i];
		}
	}


	FOR(i, 0, LEN(v) - 1) {
		if (v[i].empty()) continue;
		cout << v[i] << " ";
	}

	return 0;
}