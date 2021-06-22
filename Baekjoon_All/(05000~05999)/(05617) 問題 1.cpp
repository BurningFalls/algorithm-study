#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int arr[3];
	int a = 0, b = 0, c = 0, d = 0;
	while (true) {
		FOR(i, 0, 2)
			cin >> arr[i];
		sort(arr, arr + 3);
		if (arr[0] + arr[1] <= arr[2])
			break;
		a++;
		int tmp = arr[0] * arr[0] + arr[1] * arr[1];
		int tmp2 = arr[2] * arr[2];
		if (tmp == tmp2)
			b++;
		else if (tmp > tmp2)
			c++;
		else if (tmp < tmp2)
			d++;
	}
	cout << a << " " << b << " " << c << " " << d;


	return 0;
}