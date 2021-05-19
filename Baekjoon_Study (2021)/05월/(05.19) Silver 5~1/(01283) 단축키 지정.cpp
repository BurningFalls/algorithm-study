#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool use[26] = { 0, };
string words[31];
int ans[31];

int main() {
	FASTIO;
	int N;
	cin >> N;
	cin.ignore();
	memset(ans, -1, sizeof(ans));
	FOR(t, 1, N) {
		string s;
		getline(cin, s);
		words[t] = s;
		s += ' ';
		int len = s.size();
		vector<pair<string, int>> v;
		string sub = "";
		int start = 0;
		FOR(i, 0, len - 1) {
			if (s[i] == ' ') {
				v.push_back({ sub, start });
				sub = "";
				start = i + 1;
			}
			else
				sub += s[i];
		}
		int vlen = v.size();
		bool flag = false;
		FOR(i, 0, vlen - 1) {
			char x = v[i].first[0];
			int tmp = 0;
			if (x >= 'A' && x <= 'Z')
				tmp = x - 'A';
			else if (x >= 'a' && x <= 'z')
				tmp = x - 'a';
			if (use[tmp]) continue;
			flag = true;
			use[tmp] = 1;
			ans[t] = v[i].second;
			break;
		}
		if (flag) continue;
		FOR(i, 0, len - 1) {
			char x = s[i];
			if (x == ' ') continue;
			int tmp = 0;
			if (x >= 'A' && x <= 'Z')
				tmp = x - 'A';
			else if (x >= 'a' && x <= 'z')
				tmp = x - 'a';
			if (use[tmp]) continue;
			flag = true;
			use[tmp] = 1;
			ans[t] = i;
			break;
		}
	}
	FOR(i, 1, N) {
		string s = words[i];
		int len = s.size();
		FOR(j, 0, len - 1) {
			if (j == ans[i]) {
				cout << "[";
				cout << s[j];
				cout << "]";
			}
			else
				cout << s[j];
		}
		cout << "\n";
	}


	return 0;
}