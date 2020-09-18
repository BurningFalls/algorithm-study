#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[10001];

int main() {
	FASTIO;
	int n, p, h;
	cin >> n >> p >> h;
	arr[0] = p;
	FOR(i, 1, n)
		cin >> arr[i];
	FOR(i, 1, n) {
		if (arr[i - 1] > arr[i]) {
			cout << "NTV: Dollar dropped by ";
			cout << arr[i - 1] - arr[i];
			cout << " Oshloobs\n";
		}
		else if (arr[i] > h) {
			cout << "BBTV: Dollar reached ";
			cout << arr[i];
			cout << " Oshloobs, A record!\n";
		}
	}

	return 0;
}