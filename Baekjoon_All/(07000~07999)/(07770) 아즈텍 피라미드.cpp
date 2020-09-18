#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N;
	ll i = 2;
	ll sum = 1;
	cin >> N;
	while (true) {
		sum += 2 * i * i - 2 * i + 1;
		if (N < sum) {
			break;
		}
		i++;
	}
	cout << i - 1;

	return 0;
}