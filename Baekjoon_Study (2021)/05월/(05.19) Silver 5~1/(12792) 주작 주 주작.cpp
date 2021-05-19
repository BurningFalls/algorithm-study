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
	bool flag = true;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (num == i)
			flag = false;
	}
	cout << (flag ? 1000003 : -1);


	return 0;
}