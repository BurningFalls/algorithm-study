#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	int N;
	cin >> N;
	if (N == 1)
		cout << "J7";
	else if (N == 2)
		cout << "K8";
	else if (N == 3)
		cout << "L9";
	else {
		N -= 4;
		N %= 60;
		char x = N % 12 + 'A';
		int y = N % 10;
		cout << x << y;
	}

	return 0;
}