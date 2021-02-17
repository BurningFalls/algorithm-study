#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int arr[30001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int num = arr[1];
	int cnt = 0;
	int maximum = 0;
	FOR(i, 2, N) {
		if (num > arr[i]) {
			cnt++;
		}
		else {
			maximum = max(maximum, cnt);
			cnt = 0;
			num = arr[i];
		}
	}
	maximum = max(maximum, cnt);
	cout << maximum;

	return 0;
}