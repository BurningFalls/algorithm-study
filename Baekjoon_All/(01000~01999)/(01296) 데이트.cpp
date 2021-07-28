#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string oms;
	int N;
	cin >> oms;
	int L = 0, O = 0, V = 0, E = 0;
	int oms_len = oms.size();
	FOR(i, 0, oms_len - 1) {
		if (oms[i] == 'L')
			L++;
		else if (oms[i] == 'O')
			O++;
		else if (oms[i] == 'V')
			V++;
		else if (oms[i] == 'E')
			E++;
	}
	cin >> N;
	int maxi = -1;
	string ans = "";
	FOR(i, 1, N) {
		string name;
		int l = L, o = O, v = V, e = E;
		cin >> name;
		int name_len = name.size();
		FOR(j, 0, name_len - 1) {
			if (name[j] == 'L')
				l++;
			else if (name[j] == 'O')
				o++;
			else if (name[j] == 'V')
				v++;
			else if (name[j] == 'E')
				e++;
		}
		int prob = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
		if (prob > maxi) {
			maxi = prob;
			ans = name;
		}
		if (prob == maxi) {
			if (ans.empty())
				ans = name;
			else
				ans = min(ans, name);
		}
	}
	cout << ans;


	return 0;
}