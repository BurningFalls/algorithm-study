#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[200001];

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N)
		cin >> arr[i];
	int idx = 1;
	FOR(i, 1, Q) {
		int kind;
		cin >> kind;
		if (kind == 1) {
			int pos, x;
			cin >> pos >> x;
			arr[(idx + pos - 2) % N + 1] += x;
		}
		else if (kind == 2) {
			int s;
			cin >> s;
			idx = (idx + N - s - 1) % N + 1;
		}
		else if (kind == 3) {
			int s;
			cin >> s;
			idx = (idx + s - 1) % N + 1;
		}
	}
	FOR(i, idx, N)
		cout << arr[i] << " ";
	FOR(i, 1, idx - 1)
		cout << arr[i] << " ";

	return 0;
}