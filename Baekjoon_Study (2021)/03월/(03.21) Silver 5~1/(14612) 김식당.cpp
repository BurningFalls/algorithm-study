#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool cmp(pii a, pii b) {
	if (a.first == b.first)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<pii> v;
	FOR(i, 1, N) {
		string order;
		cin >> order;
		int table, tim;
		if (order == "order") {
			cin >> table >> tim;
			v.push_back({ table, tim });
		}
		else if (order == "sort") {
			sort(v.begin(), v.end(), cmp);
		}
		else if (order == "complete") {
			cin >> table;
			int vlen = v.size();
			FOR(i, 0, vlen - 1) {
				if (v[i].first == table) {
					v.erase(v.begin() + i);
					break;
				}
			}
		}
		if (v.empty())
			cout << "sleep";
		else {
			for (pii x : v)
				cout << x.first << " ";
		}
		cout << "\n";
	}


	return 0;
}