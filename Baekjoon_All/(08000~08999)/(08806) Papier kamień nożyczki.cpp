#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		double arr[3];
		double arr2[3];
		FOR(i, 0, 2)
			cin >> arr[i];
		FOR(i, 0, 2)
			cin >> arr2[i];
		double ans1 = arr[0] * arr2[1] + arr[1] * arr2[2] + arr[2] * arr2[0];
		double ans2 = arr[1] * arr2[0] + arr[2] * arr2[1] + arr[0] * arr2[2];
		if (ans1 < ans2)
			cout << "GOSIA";
		else if (ans1 == ans2)
			cout << "=";
		else if (ans1 > ans2)
			cout << "ADAM";
		cout << "\n";
	}

	return 0;
}