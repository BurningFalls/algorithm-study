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

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<double> v(N);
	vector<int> cnt(8001, 0);
	double maxi = -4001, mini = 4001;
	double sum = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i];
		sum += v[i];
		cnt[int(v[i]) + 4000]++;
		maxi = max(maxi, v[i]);
		mini = min(mini, v[i]);
	}
	sort(ALL(v));
	int x = round(sum / N);
	cout << x << "\n";
	cout << int(v[N / 2]) << "\n";
	vector<int> tmp;
	int max_cnt = 0;
	FOR(i, 0, 8000) {
		max_cnt = max(max_cnt, cnt[i]);
	}
	FOR(i, 0, 8000) {
		if (cnt[i] == max_cnt) {
			tmp.push_back(i - 4000);
		}
	}
	if (LEN(tmp) == 1) {
		cout << tmp[0] << "\n";
	}
	else if (LEN(tmp) >= 2) {
		cout << tmp[1] << "\n";
	}
	cout << int(maxi - mini);

	return 0;
}