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
	int num = 1;
	int cnt = 0;
	while (num < N) {
		num *= 2;
		cnt++;
	}
	int pos = 0;
	while (true) {
		if ((1 << pos) & N)
			break;
		pos++;
	}
	cout << num << " " << cnt - pos;


	return 0;
}