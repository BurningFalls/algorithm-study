#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[4][100001] = { 0, };

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		arr[num][i] = arr[num][i - 1] + 1;
		int a = num % 3 + 1;
		int b = a % 3 + 1;
		arr[a][i] = arr[a][i - 1];
		arr[b][i] = arr[b][i - 1];
	}
	FOR(i, 1, Q) {
		int a, b;
		cin >> a >> b;
		FOR(j, 1, 3) {
			cout << arr[j][b] - arr[j][a - 1] << " ";
		}
		cout << "\n";
	}


	return 0;
}