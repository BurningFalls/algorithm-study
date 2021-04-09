#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int arr[8][3][3] = { {{4, 9, 2}, {3, 5, 7}, {8, 1 ,6}},
{{2, 9, 4}, {7, 5, 3}, {6, 1 ,8}},
{{8, 3, 4}, {1, 5, 9}, {6, 7 ,2}},
{{4, 3, 8}, {9, 5, 1}, {2, 7 ,6}},
{{6, 1, 8}, {7, 5, 3}, {2, 9 ,4}},
{{8, 1, 6}, {3, 5, 7}, {4, 9 ,2}},
{{2, 7, 6}, {9, 5, 1}, {4, 3 ,8}},
{{6, 7, 2}, {1, 5, 9}, {8, 3 ,4}} };

int main() {
	FASTIO;
	int input[4][4];
	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			cin >> input[i][j];
		}
	}
	int mini = INF;
	FOR(k, 0, 7) {
		int sum = 0;
		FOR(i, 0, 2) {
			FOR(j, 0, 2) {
				sum += abs(arr[k][i][j] - input[i][j]);
			}
		}
		mini = min(mini, sum);
	}
	cout << mini;


	return 0;
}