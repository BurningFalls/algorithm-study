#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> plus_v, minus_v;
int zero_cnt = 0;
int one_cnt = 0;

int main() {
	FASTIO;
	int N;
	int sum = 0;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (num > 1)
			plus_v.push_back(num);
		else if (num < 0)
			minus_v.push_back(num);
		else if (num == 0)
			zero_cnt++;
		else if (num == 1)
			one_cnt++;
	}
	sort(plus_v.begin(), plus_v.end(), greater<int>());
	sort(minus_v.begin(), minus_v.end());
	int lenp, lenm;
	lenp = plus_v.size();
	lenm = minus_v.size();
	for (int i = 0; i < lenp - 1; i += 2)
		sum += (plus_v[i] * plus_v[i + 1]);
	for (int i = 0; i < lenm - 1; i += 2)
		sum += (minus_v[i] * minus_v[i + 1]);
	if (lenp % 2 == 1)
		sum += plus_v[lenp - 1];
	if (lenm % 2 == 1) {
		if (zero_cnt == 0)
			sum += minus_v[lenm - 1];
	}
	cout << sum + one_cnt;

	return 0;
}