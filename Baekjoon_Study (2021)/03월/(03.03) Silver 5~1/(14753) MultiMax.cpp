#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
vector<int> plus_v, minus_v;

int main() {
	FASTIO;
	int plus_cnt = 0;
	int zero_cnt = 0;
	int minus_cnt = 0;
	int maximum = 1;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (i == 1 || i == 2 || i == 3)
			maximum *= num;
		if (num > 0) {
			plus_cnt++;
			plus_v.push_back(num);
		}
		else if (num == 0)
			zero_cnt++;
		else if (num < 0) {
			minus_cnt++;
			minus_v.push_back(num);
		}
	}
	sort(plus_v.begin(), plus_v.end(), greater<int>());
	sort(minus_v.begin(), minus_v.end());
	if (plus_cnt >= 3)
		maximum = max(maximum, plus_v[0] * plus_v[1] * plus_v[2]);
	if (plus_cnt >= 1 && minus_cnt >= 2)
		maximum = max(maximum, plus_v[0] * minus_v[0] * minus_v[1]);
	if (plus_cnt >= 2)
		maximum = max(maximum, plus_v[0] * plus_v[1]);
	if (minus_cnt >= 2)
		maximum = max(maximum, minus_v[0] * minus_v[1]);
	if (zero_cnt >= 1)
		maximum = max(maximum, 0);
	cout << maximum;

	return 0;
}