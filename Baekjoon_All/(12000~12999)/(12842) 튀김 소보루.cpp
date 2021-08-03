#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
int n, s, m;

int Func() {
	int eat = n - s;
	int second = 0;
	int cnt = 0;
	while (true) {
		FOR(i, 1, m) {
			if (second % arr[i] == 0) {
				cnt++;
				if (cnt >= eat) {
					return i;
				}
			}
		}
		second++;
	}
}

int main() {
	FASTIO;
	cin >> n >> s;
	cin >> m;
	FOR(i, 1, m)
		cin >> arr[i];
	cout << Func();

	return 0;
}