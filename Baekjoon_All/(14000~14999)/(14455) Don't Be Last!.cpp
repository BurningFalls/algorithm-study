#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

int main() {
	FASTIO;
	string name[7] = { "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta" };
	int cnt[7] = { 0, };
	int N;
	vector<pair<string, int>> v;
	cin >> N;
	FOR(i, 1, N) {
		string s;
		int num;
		cin >> s >> num;
		FOR(j, 0, 6) {
			if (s == name[j]) {
				cnt[j] += num;
				break;
			}
		}
	}
	FOR(i, 0, 6) {
		v.push_back({ name[i], cnt[i] });
	}
	sort(v.begin(), v.end(), cmp);
	int tmp = v.back().second;
	while (!v.empty() && v.back().second == tmp) {
		v.pop_back();
	}
	if (v.empty())
		cout << "Tie\n";
	else {
		string tmp1 = v.back().first;
		int tmp2 = v.back().second;
		int x = 0;
		while (!v.empty() && v.back().second == tmp2) {
			v.pop_back();
			x++;
		}
		if (x >= 2)
			cout << "Tie";
		else
			cout << tmp1;
		cout << "\n";
	}

	return 0;
}