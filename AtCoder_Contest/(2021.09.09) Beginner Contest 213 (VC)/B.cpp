#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

pii arr[200001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		arr[i] = { num, i };
	}
	sort(arr + 1, arr + N + 1);
	cout << arr[N - 1].second;



	return 0;
}