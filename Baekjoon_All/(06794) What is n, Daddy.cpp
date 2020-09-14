#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int arr[11] = { 0, 1, 2, 2, 3, 3, 3, 2, 2, 1, 1 };
	int n;
	cin >> n;
	cout << arr[n];
	return 0;
}