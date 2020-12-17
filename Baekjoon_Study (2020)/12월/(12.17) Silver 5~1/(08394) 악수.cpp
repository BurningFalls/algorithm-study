#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	if (N == 1) {
		cout << 0;
		return 0;
	}
	if (N == 2) {
		cout << 2;
		return 0;
	}
	if (N == 3) {
		cout << 3;
		return 0;
	}
	int a = 2, b = 3;
	N -= 3;
	while (N--) {
		int temp = (a + b) % 10;
		a = b;
		b = temp;
	}
	cout << b;

	return 0;
}