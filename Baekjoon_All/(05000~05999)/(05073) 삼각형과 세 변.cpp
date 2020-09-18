#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int arr[3];
	while (true) {
		FOR(i, 0, 2)
			cin >> arr[i];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;
		sort(arr, arr + 3);
		if (arr[0] + arr[1] <= arr[2])
			cout << "Invalid";
		else if (arr[0] == arr[1] && arr[1] == arr[2])
			cout << "Equilateral";
		else if (arr[0] != arr[1] && arr[1] != arr[2] && arr[2] != arr[0])
			cout << "Scalene";
		else
			cout << "Isosceles";
		cout << "\n";
	}

	return 0;
}