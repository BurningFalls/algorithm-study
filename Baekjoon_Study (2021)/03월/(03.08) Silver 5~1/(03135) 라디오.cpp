#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int A, B;
	int N;
	int arr[6];
	int minimum;
	cin >> A >> B;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	minimum = abs(A - B);
	FOR(i, 1, N) {
		minimum = min(minimum, abs(B - arr[i]) + 1);
	}
	cout << minimum;

	return 0;
}