#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	int arr[101];
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int sum = 0;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			sum += arr[i] * arr[j];
		}
	}
	cout << sum;


	return 0;
}