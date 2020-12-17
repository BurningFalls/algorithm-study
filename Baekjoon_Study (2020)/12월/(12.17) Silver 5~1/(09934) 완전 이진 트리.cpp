#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1024];
vector<int> v[11];

void DFS(int left, int right, int index) {
	if (left > right)
		return;
	int mid = (left + right) / 2;
	v[index].push_back(arr[mid]);
	DFS(left, mid - 1, index + 1);
	DFS(mid + 1, right, index + 1);
}

int main() {
	FASTIO;
	int K;
	cin >> K;
	FOR(i, 1, pow(2, K) - 1)
		cin >> arr[i];
	DFS(1, pow(2, K) - 1, 1);
	FOR(i, 1, K) {
		FOR(j, 0, v[i].size() - 1)
			cout << v[i][j] << " ";
		cout << "\n";
	}

	return 0;
}