#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 1000000001

int main() {
	FASTIO;
	int N;
	int mini1 = INF, mini2 = INF;
	cin >> N;
	bool flag = false;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		if (num == -1)
			flag = true;
		else {
			if (!flag)
				mini1 = min(mini1, num);
			else if (flag)
				mini2 = min(mini2, num);
		}
	}
	cout << mini1 + mini2;


	return 0;
}