#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[300001];

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int idx = N;
	int pos = N;
	int cnt = 0;
	while (idx >= 1) {
		if (arr[idx] == pos) {
			pos--;
			cnt++;
		}
		idx--;
	}
	cout << N - cnt;


	return 0;
}