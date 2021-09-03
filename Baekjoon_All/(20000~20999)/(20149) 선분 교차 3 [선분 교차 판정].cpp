#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

struct NODE {
	ll x;
	ll y;
	bool operator <= (NODE& a) {
		if (x == a.x)
			return y <= a.y;
		return x <= a.x;
	}
	bool operator == (NODE& a) {
		return x == a.x && y == a.y;
	}
};

struct NODE2 {
	ld x;
	ld y;
};

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
	bool flag = false;
	if (ABC * ABD == 0 && CDA * CDB == 0) {
		if (B <= A)
			swap(A, B);
		if (D <= C)
			swap(C, D);
		flag = (C <= B && A <= D);
	}
	else
		flag = (ABC * ABD <= 0 && CDA * CDB <= 0);
	if (flag) {
		cout << 1;
		if (ABC == 0 && ABD == 0 && CDA == 0 && CDB == 0) {
			if (B == C)
				cout << "\n" << B.x << " " << B.y;
			else if (A == D)
				cout << "\n" << A.x << " " << A.y;
			return 0;
		}
		cout << "\n";
		cout << fixed << setprecision(9);
		NODE2 a = { ld(A.x), ld(A.y) };
		NODE2 b = { ld(B.x), ld(B.y) };
		NODE2 c = { ld(C.x), ld(C.y) };
		NODE2 d = { ld(D.x), ld(D.y) };
		ld M, N, X, Y;
		if (a.x == b.x) {
			N = (c.y - d.y) / (c.x - d.x);
			X = a.x;
			Y = N * (X - c.x) + c.y;
		}
		else if (c.x == d.x) {
			M = (a.y - b.y) / (a.x - b.x);
			X = c.x;
			Y = M * (X - a.x) + a.y;
		}
		else {
			M = (a.y - b.y) / (a.x - b.x);
			N = (c.y - d.y) / (c.x - d.x);
			X = (M * a.x - N * c.x + c.y - a.y) / (M - N);
			Y = M * (X - a.x) + a.y;
		}
		cout << X << " " << Y;
	}
	else if (!flag)
		cout << "0";


	return 0;
}