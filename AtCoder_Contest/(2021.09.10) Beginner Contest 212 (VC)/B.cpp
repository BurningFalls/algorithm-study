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
	char A, B, C, D;
	cin >> A >> B >> C >> D;
	int a = A - '0';
	int b = B - '0';
	int c = C - '0';
	int d = D - '0';
	if (a == b && b == c && c == d)
		cout << "Weak";
	else {
		if ((a + 1) % 10 == b && (b + 1) % 10 == c && (c + 1) % 10 == d)
			cout << "Weak";
		else
			cout << "Strong";
	}



	return 0;
}