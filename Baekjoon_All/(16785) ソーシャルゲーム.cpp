#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int A, B, C;
	cin >> A >> B >> C;
	int temp = C / A + 1;
	while (temp--) {
		if (A * temp + B * (temp / 7) < C)
			break;
	}
	cout << temp + 1;

	return 0;
}