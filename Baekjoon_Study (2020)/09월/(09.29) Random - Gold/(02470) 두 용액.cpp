#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int s = 1;
	int e = N;
	int ans = 2000000001;
	int idx1 = 1, idx2 = N;
	while (s != e) {
		int temp = abs(arr[s] + arr[e]);
		if (ans > temp) {
			ans = temp;
			idx1 = s;
			idx2 = e;
		}
		if (arr[s] + arr[e] < 0)
			s++;
		else if (arr[s] + arr[e] > 0)
			e--;
		else if (arr[s] + arr[e] == 0)
			break;
	}
	cout << arr[idx1] << " " << arr[idx2];

	return 0;
}