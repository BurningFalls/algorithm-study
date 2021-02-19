#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, K;
char arr[26];
int S[101];
char letter[101];

bool Check() {
	bool visited[26] = { 0, };
	FOR(i, 0, N - 1) {
		if (arr[i] == '?') continue;
		if (visited[arr[i] - 'A'])
			return false;
		visited[arr[i] - 'A'] = 1;
	}
	return true;
}

int main() {
	FASTIO;
	cin >> N >> K;
	int pos = 0;
	FOR(i, 0, N - 1)
		arr[i] = '?';
	FOR(i, 1, K) {
		cin >> S[i] >> letter[i];
	}
	bool flag = true;
	FOR(i, 1, K) {
		pos = (pos + S[i]) % N;
		if (arr[pos] == '?') {
			arr[pos] = letter[i];
		}
		else if (arr[pos] == letter[i])
			continue;
		else {
			flag = false;
			break;
		}
	}
	if (!Check())
		flag = false;
	if (!flag)
		cout << "!";
	else {
		FOR(i, 0, N - 1) {
			cout << arr[(pos - i + N) % N];
		}
	}

	return 0;
}