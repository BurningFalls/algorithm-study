#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr1[200003];
char arr2[200003];
bool visited[200003];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		memset(visited, 0, sizeof(visited));
		int N;
		cin >> N;
		arr1[0] = '0';
		arr1[N + 1] = '0';
		FOR(i, 1, N)
			cin >> arr1[i];
		FOR(i, 1, N)
			cin >> arr2[i];
		FOR(i, 1, N) {
			if (arr2[i] == '0') continue;
			if (arr1[i - 1] == '1' && !visited[i - 1])
				visited[i - 1] = 1;
			else if (arr1[i] == '0' && !visited[i])
				visited[i] = 1;
			else if (arr1[i + 1] == '1' && !visited[i + 1])
				visited[i + 1] = 1;
		}
		int cnt = 0;
		FOR(i, 1, N) {
			if (visited[i])
				cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}