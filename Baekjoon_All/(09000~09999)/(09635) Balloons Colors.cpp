#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, X, Y;
		bool flag1, flag2;
		cin >> N >> X >> Y;
		FOR(i, 1, N)
			cin >> arr[i];
		flag1 = (arr[1] == X);
		flag2 = (arr[N] == Y);
		if (flag1 && flag2)
			cout << "BOTH";
		else if (flag1 && !flag2)
			cout << "EASY";
		else if (!flag1 && flag2)
			cout << "HARD";
		else
			cout << "OKAY";
		cout << "\n";
	}

	return 0;
}