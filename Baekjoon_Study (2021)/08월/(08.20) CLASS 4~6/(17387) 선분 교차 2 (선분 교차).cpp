#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	ll x;
	ll y;
	bool operator <= (_NODE& a) {
		if (x == a.x)
			return y <= a.y;
		return x <= a.x;
	}
} NODE;

int CCW(NODE a, NODE b, NODE c) {
	ll t1 = a.x * b.y + b.x * c.y + c.x * a.y;
	ll t2 = b.x * a.y + c.x * b.y + a.x * c.y;
	if (t1 - t2 > 0)
		return 1;
	else if (t1 - t2 == 0)
		return 0;
	else if (t1 - t2 < 0)
		return -1;
}

int main() {
	FASTIO;
	NODE A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y;
	cin >> C.x >> C.y >> D.x >> D.y;
	int ABC = CCW(A, B, C);
	int ABD = CCW(A, B, D);
	int CDA = CCW(C, D, A);
	int CDB = CCW(C, D, B);
	if (ABC * ABD == 0 && CDA * CDB == 0) {
		if (B <= A)
			swap(A, B);
		if (D <= C)
			swap(C, D);
		cout << (C <= B && A <= D);
	}
	else
		cout << (ABC * ABD <= 0 && CDA * CDB <= 0);

	return 0;
}