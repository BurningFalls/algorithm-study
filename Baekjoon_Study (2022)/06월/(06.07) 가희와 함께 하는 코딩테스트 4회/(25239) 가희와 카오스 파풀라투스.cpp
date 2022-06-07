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
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	string tmp;
	cin >> tmp;
	int cur_time = ((tmp[0] - '0') * 10 + (tmp[1] - '0')) * 60 + ((tmp[3] - '0') * 10 + (tmp[4] - '0'));
	vector<int> terri_num(6);
	vector<int> terri_locked(6, 0);
	FOR(i, 0, 5) {
		cin >> terri_num[i];
	}
	int L;
	cin >> L;
	vector<int> query(L);
	FOR(i, 0, L - 1) {
		double ti;
		cin >> ti;
		cin >> tmp;
		if (tmp == "^")
			query[i] = 0;
		else if (tmp == "10MIN")
			query[i] = 10;
		else if (tmp == "30MIN")
			query[i] = 30;
		else if (tmp == "50MIN")
			query[i] = 50;
		else if (tmp == "2HOUR")
			query[i] = 120;
		else if (tmp == "4HOUR")
			query[i] = 240;
		else if (tmp == "9HOUR")
			query[i] = 540;
	}

	FOR(i, 0, L - 1) {
		int item = query[i];
		if (item == 0) {
			terri_locked[cur_time / 120] = 1;
		}
		else {
			cur_time = (cur_time + item) % 720;
		}
	}

	int ans = 0;
	FOR(i, 0, 5) {
		if (terri_locked[i]) continue;
		ans += terri_num[i];
	}
	cout << min(100, ans);

	return 0;
}