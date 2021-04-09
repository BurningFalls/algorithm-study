#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int cnt = 0;
int arr[11];
vector<int> v;
bool flag = false;

void DFS(int node, int size) {
	if (node == size) {
		cnt++;
		if (cnt == N) {
			flag = true;
			FOR(i, 0, size - 1)
				v.push_back(arr[i]);
		}
		return;
	}
	FOR(i, 0, 9) {
		if (node != 0 && arr[node - 1] <= i) continue;
		arr[node] = i;
		DFS(node + 1, size);
	}
}

int main() {
	FASTIO;
	cin >> N;
	if (N == 1023)
		cout << 9876543210;
	else if (N > 1023)
		cout << -1;
	else {
		FOR(i, 1, 9) {
			DFS(0, i);
			if (flag)
				break;
		}
		for (int x : v)
			cout << x;
	}

	return 0;
}