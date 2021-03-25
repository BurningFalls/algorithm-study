#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int N, T, P;
vector<pii> v;
int arr[101] = { 0, };
int check[1261][102] = { 0, };

int Calc(string s1) {
	int a = (s1[0] - '0') * 10 + (s1[1] - '0');
	int b = (s1[2] - '0') * 10 + (s1[3] - '0');
	return 60 * a + b;
}

int Find(int s) {
	int maximum = 0;
	int cnt = 0;
	FOR(i, 1, N) {
		if (check[s][i])
			cnt++;
	}
	if (cnt == 0)
		return 1;
	else {
		int maximum = 0;
		int pos = 0;

		check[s][0] = 1;
		check[N + 1][0] = 1;
		FOR(i, 1, N) {
			if (check[s][i]) continue;
			int left = i, right = i;
			while (left > 0) {
				left--;
				if (check[s][left])
					break;
			}
			while (right < N + 1) {
				right++;
				if (check[s][right])
					break;
			}
			int a, b;
			if (left == 0)
				a = INF;
			else
				a = i - left;
			if (right == N + 1)
				b = INF;
			else
				b = right - i;
			if (maximum < min(a, b)) {
				maximum = min(a, b);
				pos = i;
			}
		}
		return pos;
	}
}

int main() {
	FASTIO;
	cin >> N >> T >> P;
	FOR(i, 1, T) {
		string s1, s2;
		cin >> s1 >> s2;
		v.push_back({ Calc(s1), Calc(s2) - 1 });
	}
	int ans = 0;
	sort(v.begin(), v.end());
	FOR(i, 0, T - 1) {
		int pos = Find(v[i].first);
		FOR(j, v[i].first, v[i].second) {
			check[j][pos] = (i + 1);
		}
	}
	int cnt = 0;
	FOR(i, 540, 1259) {
		if (check[i][P] == 0)
			cnt++;
	}
	cout << cnt;


	return 0;
}