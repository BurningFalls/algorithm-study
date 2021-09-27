#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	ll K;
	string A, B;
	cin >> K >> A >> B;
	ll a = 0, b = 0;
	FOR(i, 0, LEN(A) - 1)
		a += (A[i] - '0') * pow(K, LEN(A) - i - 1);
	FOR(i, 0, LEN(B) - 1)
		b += (B[i] - '0') * pow(K, LEN(B) - i - 1);
	cout << a * b;

	return 0;
}