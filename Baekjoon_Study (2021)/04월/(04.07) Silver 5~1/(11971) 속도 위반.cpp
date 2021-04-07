#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr1[101];
int arr2[101];

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	int sum = 0;
	FOR(i, 1, N) {
		int length, speed;
		cin >> length >> speed;
		FOR(j, sum, sum + length - 1)
			arr1[j] = speed;
		sum += length;
	}
	sum = 0;
	FOR(i, 1, M) {
		int length, speed;
		cin >> length >> speed;
		FOR(j, sum, sum + length - 1)
			arr2[j] = speed;
		sum += length;
	}
	int maxi = 0;
	FOR(i, 0, 99) {
		if (arr1[i] < arr2[i])
			maxi = max(maxi, arr2[i] - arr1[i]);
	}
	cout << maxi;

	return 0;
}