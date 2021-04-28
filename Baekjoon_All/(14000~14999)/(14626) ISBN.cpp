#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	char arr[14];
	int pos = 0;
	int sum = 0;
	FOR(i, 1, 13) {
		cin >> arr[i];
		if (arr[i] == '*') {
			pos = i;
			continue;
		}
		if (i % 2 == 1)
			sum += (arr[i] - '0');
		else if (i % 2 == 0)
			sum += 3 * (arr[i] - '0');
	}
	FOR(i, 0, 9) {
		int tmp = sum;
		if (pos % 2 == 1)
			tmp += i;
		else if (pos % 2 == 0)
			tmp += 3 * i;
		if (tmp % 10 == 0) {
			cout << i;
			break;
		}
	}

	return 0;
}