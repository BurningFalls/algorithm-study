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
	int num;
	int money = 5000;
	while (cin >> num) {
		if (num == 1)
			money -= 500;
		else if (num == 2)
			money -= 800;
		else if (num == 3)
			money -= 1000;
	}
	cout << money;


	return 0;
}