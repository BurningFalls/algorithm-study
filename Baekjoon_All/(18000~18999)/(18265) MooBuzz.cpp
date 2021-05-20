#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	int arr[8] = { 1, 2, 4, 7, 8, 11, 13, 14 };
	cin >> N;
	cout << ((N - 1) / 8) * 15 + arr[(N - 1) % 8];

	return 0;
}