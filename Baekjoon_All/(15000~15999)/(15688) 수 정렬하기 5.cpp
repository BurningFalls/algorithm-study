#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

int N;
int arr[1000001];

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1);
	FOR(i, 1, N) {
		cout << arr[i] << "\n";
	}

	return 0;
}