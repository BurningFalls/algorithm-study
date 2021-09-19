#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

map<string, pair<int, vector<string>>> mp;
vector<string> ans_v;

struct compare {
	bool operator() (string& a, string& b) {
		return b < a;
	}
};

bool TS() {
	priority_queue<string, vector<string>, compare> pq[2];
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if ((*it).second.first == 0)
			pq[0].push((*it).first);
	}
	int idx = 0;
	while (true) {
		if (pq[idx].empty()) {
			idx = (idx + 1) % 2;
			if (pq[idx].empty())
				break;
		}
		string node = pq[idx].top();
		pq[idx].pop();
		ans_v.push_back(node);
		for (string next : mp[node].second) {
			if (--mp[next].first == 0) {
				pq[(idx + 1) % 2].push(next);
			}
		}
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if ((*it).second.first != 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		string A, B;
		cin >> A >> B;
		mp[A].second.push_back(B);
		mp[B].first++;
	}
	bool flag = TS();
	if (!flag)
		cout << -1;
	else {
		for (string s : ans_v)
			cout << s << "\n";
	}


	return 0;
}