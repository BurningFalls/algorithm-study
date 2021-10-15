#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<int> v(N);
	int left = 0, right = 0;
	FOR(i, 0, N - 1) {
		cin >> v[i];
		left = max(left, v[i]);
		right += v[i];
	}
	int ans = INF;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int sum = 0;
		FOR(i, 0, N - 1) {
			if (sum + v[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += v[i];
		}
		if (cnt > M) {
			left = mid + 1;
		}
		else if (cnt <= M) {
			ans = min(ans, mid);
			right = mid - 1;
		}
	}
	P1(ans);
	int sum = 0;
	int cnt = 0;
	vector<int> num;
	FOR(i, 0, N - 1) {
		if (sum + v[i] > ans) {
			num.push_back(cnt);
			cnt = 0;
			sum = 0;
		}
		sum += v[i];
		cnt++;
	}
	num.push_back(cnt);
	int need = max(0, M - LEN(num));
	FOR(i, 0, LEN(num) - 1) {
		if (need != 0 && num[i] != 1) {
			cout << 1 << " ";
			num[i]--;
			need--;
			i--;
		}
		else {
			cout << num[i] << " ";
		}
	}


	return 0;
}