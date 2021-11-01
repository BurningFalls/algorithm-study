#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, M;
int Prev[1000001];
int Next[1000001];
int arr[500001];

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	FOR(i, 1, N) {
		if (i == 1) {
			Prev[arr[1]] = arr[N];
		}
		else {
			Prev[arr[i]] = arr[i - 1];
		}
		if (i == N) {
			Next[arr[N]] = arr[1];
		}
		else {
			Next[arr[i]] = arr[i + 1];
		}
	}
	FOR(m, 1, M) {
		string order;
		int i, j;
		cin >> order;
		if (order == "BN") {
			cin >> i >> j;
			cout << Next[i] << "\n";
			int a = i;
			int b = j;
			int c = Next[i];
			Next[a] = b;
			Next[b] = c;
			Prev[c] = b;
			Prev[b] = a;
		}
		else if (order == "BP") {
			cin >> i >> j;
			cout << Prev[i] << "\n";
			int a = Prev[i];
			int b = j;
			int c = i;
			Next[a] = b;
			Next[b] = c;
			Prev[c] = b;
			Prev[b] = a;
		}
		else if (order == "CN") {
			cin >> i;
			cout << Next[i] << "\n";
			int a = i;
			int b = Next[Next[i]];
			Next[a] = b;
			Prev[b] = a;
		}
		else if (order == "CP") {
			cin >> i;
			cout << Prev[i] << "\n";
			int a = Prev[Prev[i]];
			int b = i;
			Next[a] = b;
			Prev[b] = a;
		}
	}

	return 0;
}