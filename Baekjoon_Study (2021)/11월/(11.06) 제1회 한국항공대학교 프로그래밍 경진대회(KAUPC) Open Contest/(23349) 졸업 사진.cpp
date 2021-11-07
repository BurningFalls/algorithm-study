#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

struct NODE {
	int cnt;
	string place;
	int left;
	int right;
};

map<string, vector<int>> mp;
vector<int> tmp(50002, 0);
set<string> student;
vector<NODE> ans;

bool compare(NODE a, NODE b) {
	if (a.cnt == b.cnt)
		return a.place < b.place;
	return a.cnt > b.cnt;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string name, place;
		int time1, time2;
		cin >> name >> place >> time1 >> time2;
		if (student.count(name)) continue;
		student.insert(name);
		if (!mp.count(place)) {
			mp[place] = tmp;
		}
		FOR(j, time1, time2 - 1) {
			mp[place][j] += 1;
		}
	}
	for (auto x : mp) {
		int maxi = 0;
		FOR(i, 0, 50001) {
			maxi = max(maxi, x.second[i]);
		}
		if (maxi == 0) continue;
		bool flag = false;
		int start = 0, end = 0;
		FOR(i, 0, 50001) {
			if (!flag && x.second[i] == maxi) {
				flag = true;
				start = i;
			}
			else if (flag && x.second[i] != maxi) {
				end = i;
				break;
			}
		}
		ans.push_back({ maxi, x.first, start, end });
	}
	sort(ALL(ans), compare);
	cout << ans[0].place << " " << ans[0].left << " " << ans[0].right;

	return 0;
}