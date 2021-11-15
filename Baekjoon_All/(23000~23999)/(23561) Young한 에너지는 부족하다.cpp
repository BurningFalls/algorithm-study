#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int arr[300001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, 3 * N) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + 3 * N + 1);
	int left = 1;
	int right = 3 * N;
	int mid = (left + right) / 2;
	left = mid - N / 2;
	right = mid + N / 2;
	if (N % 2 == 0) {
		left++;
	}
	cout << arr[right] - arr[left];

	return 0;
}