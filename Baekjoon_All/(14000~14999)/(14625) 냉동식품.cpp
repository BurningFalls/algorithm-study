#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	pii s, e;
	cin >> s.first >> s.second;
	cin >> e.first >> e.second;
	int N;
	cin >> N;;
	int cnt = 0;
	if (s.first / 10 == N || s.first % 10 == N ||
		s.second / 10 == N || s.second % 10 == N)
		cnt++;
	while (!(s.first == e.first && s.second == e.second)) {
		s.second += 1;
		if (s.second == 60) {
			s.second = 0;
			s.first += 1;
		}
		if (s.first / 10 == N || s.first % 10 == N ||
			s.second / 10 == N || s.second % 10 == N)
			cnt++;
	}
	cout << cnt;

	return 0;
}