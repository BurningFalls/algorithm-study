#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int arr[6];
	while (true) {
		int cnt = 0;
		FOR(i, 0, 5) {
			cin >> arr[i];
			if (arr[i] == 0)
				cnt++;
		}
		if (cnt == 6)
			break;
		sort(arr, arr + 6);
		double temp = arr[1] + arr[2] + arr[3] + arr[4];
		temp /= 4;
		cout << temp << "\n";
	}

	return 0;
}