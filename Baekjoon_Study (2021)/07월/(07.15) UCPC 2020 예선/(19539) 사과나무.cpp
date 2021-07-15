#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int odd_cnt = 0;
int sum = 0;

bool Check() {
	if (sum % 3 != 0)
		return false;
	if (odd_cnt > sum / 3)
		return false;
	return true;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (num % 2 == 1)
			odd_cnt++;
		sum += num;
	}
	cout << (Check() ? "YES" : "NO");\

	return 0;
}