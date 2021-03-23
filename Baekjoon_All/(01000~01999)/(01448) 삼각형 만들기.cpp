#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[1000001];

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1, greater<int>());
	int sum = -1;
	FOR(i, 1, N - 2) {
		if (arr[i] < arr[i + 1] + arr[i + 2]) {
			sum = arr[i] + arr[i + 1] + arr[i + 2];
			break;
		}
	}
	cout << sum;

	return 0;
}