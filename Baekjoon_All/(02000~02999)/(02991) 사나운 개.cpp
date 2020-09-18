#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int A, B, C, D;
	int arr[3];
	cin >> A >> B >> C >> D;
	FOR(i, 0, 2)
		cin >> arr[i];
	FOR(i, 0, 2) {
		int cnt = 0;
		int temp = arr[i] - 1;
		if (temp % (A + B) >= 0 && temp % (A + B) < A)
			cnt++;
		if (temp % (C + D) >= 0 && temp % (C + D) < C)
			cnt++;
		cout << cnt << "\n";
	}

	return 0;
}