#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
int arr[1000001];

int main() {
	FASTIO;
	while (true) {
		int cnt = 0;
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		FOR(i, 0, N - 1)
			cin >> arr[i];
		FOR(i, 0, M - 1) {
			int num;
			cin >> num;
			bool flag = binary_search(arr, arr + N, num);
			if (flag)
				cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}