#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int start = 1, end = N;
	int x, y;
	int min_abs = 2100000000;
	while (start != end) {
		int temp = arr[start] + arr[end];
		if (abs(temp) <= min_abs) {
			min_abs = abs(temp);
			x = start;
			y = end;
		}
		if (temp == 0)
			break;
		else if (temp > 0)
			end--;
		else if (temp < 0)
			start++;
	}
	cout << arr[x] << " " << arr[y];

	return 0;
}