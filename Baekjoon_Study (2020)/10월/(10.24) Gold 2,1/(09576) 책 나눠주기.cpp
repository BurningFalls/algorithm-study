#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<pii> v;
bool used[1001];

bool compare(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int imp = 0;
		v.clear();
		memset(used, 0, sizeof(used));
		int N, M;
		cin >> N >> M;
		FOR(i, 1, M) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}
		sort(v.begin(), v.end(), compare);
		FOR(i, 0, M - 1) {
			int a = v[i].first;
			int b = v[i].second;
			bool flag = false;
			FOR(j, a, b) {
				if (used[j] == 0) {
					used[j] = 1;
					flag = true;
					break;
				}
			}
			if (!flag)
				imp++;
		}
		cout << M - imp << "\n";
	}

	return 0;
}