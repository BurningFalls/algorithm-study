#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool check[3001];
int arr[3001];

int main() {
	FASTIO;
	int N;
	while (cin >> N) {
		memset(check, 0, sizeof(check));
		FOR(i, 1, N)
			cin >> arr[i];
		bool flag = true;
		FOR(i, 1, N - 1) {
			int tmp = abs(arr[i + 1] - arr[i]);
			if (tmp == 0 || tmp > N - 1 || check[tmp]) {
				flag = false;
				break;
			}
			check[tmp] = 1;
		}
		cout << (flag ? "Jolly" : "Not jolly") << "\n";
	}



	return 0;
}