#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int C, P;
int height[101];

int Func2(int x, int y) {
	int cnt = 0;
	FOR(i, 1, C - 1) {
		int a = height[i] + x;
		int b = height[i + 1] + y;
		if (a == b)
			cnt++;
	}
	return cnt;
}

int Func3(int x, int y, int z) {
	int cnt = 0;
	FOR(i, 1, C - 2) {
		int a = height[i] + x;
		int b = height[i + 1] + y;
		int c = height[i + 2] + z;
		if (a == b && b == c)
			cnt++;
	}
	return cnt;
}

int Func4(int x, int y, int z, int w) {
	int cnt = 0;
	FOR(i, 1, C - 3) {
		int a = height[i] + x;
		int b = height[i + 1] + y;
		int c = height[i + 2] + z;
		int d = height[i + 3] + w;
		if (a == b && b == c && c == d)
			cnt++;
	}
	return cnt;
}

int DO() {
	if (P == 1)
		return C + Func4(0, 0, 0, 0);
	else if (P == 2)
		return Func2(0, 0);
	else if (P == 3)
		return Func2(0, 1) + Func3(1, 1, 0);
	else if (P == 4)
		return Func2(1, 0) + Func3(0, 1, 1);
	else if (P == 5)
		return Func2(0, 1) + Func2(1, 0) + Func3(0, 0, 0) + Func3(0, 1, 0);
	else if (P == 6)
		return Func2(0, 0) + Func2(0, 2) + Func3(0, 0, 0) + Func3(1, 0, 0);
	else if (P == 7)
		return Func2(0, 0) + Func2(2, 0) + Func3(0, 0, 0) + Func3(0, 0, 1);
}

int main() {
	FASTIO;
	cin >> C >> P;
	FOR(i, 1, C) {
		cin >> height[i];
	}
	cout << DO();

	return 0;
}