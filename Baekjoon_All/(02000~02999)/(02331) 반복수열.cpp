#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int visited[9 * 9 * 9 * 9 * 9 * 4 + 1] = { 0, };

int main() {
	FASTIO;
	int A, P;
	cin >> A >> P;
	int idx = 1;
	while (!visited[A]) {
		visited[A] = idx;
		string s = to_string(A);
		int temp = 0;
		FOR(i, 0, s.size() - 1)
			temp += pow((s[i] - '0'), P);
		A = temp;
		idx++;
	}
	cout << visited[A] - 1;

	return 0;
}