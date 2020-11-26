#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A, B, C;
int temp[3];
int visited[201][201][201] = { 0, };
bool ans[201] = { 0, };

void DFS(int a, int b, int c) {
	int arr[3] = { a, b, c };
	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			if (i == j) continue;
			if (arr[i] == 0) continue;
			if (arr[j] == temp[j]) continue;
			int move = min(arr[i], temp[j] - arr[j]);
			arr[i] -= move;
			arr[j] += move;
			if (!visited[arr[0]][arr[1]][arr[2]]) {
				visited[arr[0]][arr[1]][arr[2]] = 1;
				if (arr[0] == 0)
					ans[arr[2]] = 1;
				DFS(arr[0], arr[1], arr[2]);
			}
			arr[i] += move;
			arr[j] -= move;
		}
	}
}

int main() {
	FASTIO;
	cin >> A >> B >> C;
	temp[0] = A, temp[1] = B, temp[2] = C;
	visited[0][0][C] = 0;
	ans[C] = 1;
	DFS(0, 0, C);
	FOR(i, 0, 200) {
		if (ans[i])
			cout << i << " ";
	}

	return 0;
}