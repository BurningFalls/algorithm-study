#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
int arr[(1 << 20) + 1];

void Func() {
	int cnt = N / K;
	for (int i = 1; i <= N; i += cnt) {
		sort(arr + i, arr + i + cnt);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	cin >> K;
	Func();
	FOR(i, 1, N)
		cout << arr[i] << " ";

	return 0;
}