#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];
string sarr[101];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	FOR(i, 1, N) {
		cin >> sarr[i];
	}
	string tmp[101];
	FOR(t, 1, 3) {
		FOR(i, 1, N) {
			tmp[i] = sarr[arr[i]];
		}
		FOR(i, 1, N) {
			sarr[i] = tmp[i];
		}
	}

	FOR(i, 1, N) {
		cout << sarr[i] << "\n";
	}


	return 0;
}