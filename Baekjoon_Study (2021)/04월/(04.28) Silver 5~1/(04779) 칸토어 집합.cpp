#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[550000] = { 0, };

void Func(int n, int start) {
	if (n == 1)
		return;
	FOR(i, start + n / 3, start + (n / 3) * 2 - 1)
		arr[i] = 0;
	Func(n / 3, start);
	Func(n / 3, start + (n / 3) * 2);
}

int main() {
	FASTIO;
	int N;
	while (cin >> N) {
		FOR(i, 1, pow(3, N))
			arr[i] = 1;
		Func(pow(3, N), 1);
		FOR(i, 1, pow(3, N)) {
			if (arr[i] == 1)
				cout << '-';
			else
				cout << ' ';
		}
		cout << "\n";
	}

	return 0;
}