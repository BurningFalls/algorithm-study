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
	int X, Y, N;
	cin >> X >> Y >> N;
	FOR(i, 1, N) {
		if (i % X == 0 && i % Y == 0)
			cout << "FizzBuzz";
		else if (i % X == 0)
			cout << "Fizz";
		else if (i % Y == 0)
			cout << "Buzz";
		else
			cout << i;
		cout << "\n";
	}


	return 0;
}