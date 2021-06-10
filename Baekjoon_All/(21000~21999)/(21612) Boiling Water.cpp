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
	int tmp = N * 5 - 400;
	cout << tmp << "\n";
	if (tmp < 100)
		cout << 1;
	else if (tmp == 100)
		cout << 0;
	else if (tmp > 100)
		cout << -1;


	return 0;
}