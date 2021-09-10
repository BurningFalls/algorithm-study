#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	int A, B;
	cin >> A >> B;
	if (0 < A && B == 0)
		cout << "Gold";
	else if (A == 0 && 0 < B)
		cout << "Silver";
	else if (0 < A && 0 < B)
		cout << "Alloy";



	return 0;
}