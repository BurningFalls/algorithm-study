#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

bool Check(string A, string B) {
	if (LEN(A) != LEN(B)) {
		return false;
	}
	string na = A, nb = B;
	sort(ALL(na));
	sort(ALL(nb));
	if (na != nb) {
		return false;
	}
	if (A[0] != B[0] || A[LEN(A) - 1] != B[LEN(B) - 1]) {
		return false;
	}
	na = "", nb = "";
	FOR(i, 0, LEN(A) - 1) {
		if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') continue;
		na += A[i];
	}
	FOR(i, 0, LEN(B) - 1) {
		if (B[i] == 'a' || B[i] == 'e' || B[i] == 'i' || B[i] == 'o' || B[i] == 'u') continue;
		nb += B[i];
	}
	if (na != nb) {
		return false;
	}
	return true;
}

int main() {
	FASTIO;
	int N;
	string A, B;
	cin >> N;
	cin >> A >> B;

	cout << (Check(A, B) ? "YES" : "NO");

	return 0;
}