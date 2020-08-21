#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int arr[4];
	FOR(i, 0, 3)
		cin >> arr[i];
	if ((arr[0] == 8 || arr[0] == 9) && (arr[3] == 8 || arr[3] == 9) && (arr[1] == arr[2]))
		cout << "ignore";
	else
		cout << "answer";

	return 0;
}