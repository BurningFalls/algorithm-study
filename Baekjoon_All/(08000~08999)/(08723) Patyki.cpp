#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);
	if (arr[0] == arr[1] && arr[1] == arr[2])
		cout << 2;
	else if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
		cout << 1;
	else
		cout << 0;
	return 0;
}