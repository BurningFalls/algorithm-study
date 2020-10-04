#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	int idx = 1;
	cin >> T;
	while (T--) {
		int A, B, C;
		cin >> A >> B >> C;
		cout << "Case #" << idx << ": ";
		int arr[3];
		arr[0] = A, arr[1] = B, arr[2] = C;
		sort(arr, arr + 3);
		if (arr[0] + arr[1] <= arr[2])
			cout << "invalid!";
		else if (A == B && B == C && C == A)
			cout << "equilateral";
		else if (A == B || B == C || C == A)
			cout << "isosceles";
		else
			cout << "scalene";
		cout << "\n";
		idx++;
	}

	return 0;
}