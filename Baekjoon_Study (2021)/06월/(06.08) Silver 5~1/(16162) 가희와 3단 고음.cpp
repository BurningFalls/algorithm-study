#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[20001];

int main() {
	FASTIO;
	int N, A, D;
	cin >> N >> A >> D;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int num = A;
	int idx = 1;
	FOR(i, 1, N) {
		if (num == arr[i]) {
			num += D;
			idx++;
		}
	}
	cout << idx - 1;


	return 0;
}