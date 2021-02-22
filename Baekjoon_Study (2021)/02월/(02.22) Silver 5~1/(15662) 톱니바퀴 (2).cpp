#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int T;
string arr[1001];
int start;

string Rotate(int node, int dir) {
	string s = arr[node];
	if (dir == 1) {
		int tmp = s[7];
		ROF(i, 7, 1) {
			s[i] = s[i - 1];
		}
		s[0] = tmp;
	}
	else if (dir == -1) {
		int tmp = s[0];
		FOR(i, 0, 6) {
			s[i] = s[i + 1];
		}
		s[7] = tmp;
	}
	return s;
}

void Left_Check(int node, int dir) {
	bool flag = false;
	if (node == 1) {
		if (node != start)
			arr[node] = Rotate(node, dir);
		return;
	}
	if ((arr[node - 1][2] == '0' && arr[node][6] == '1') || 
		(arr[node - 1][2] == '1' && arr[node][6] == '0')) {
		flag = true;
	}
	if (node != start)
		arr[node] = Rotate(node, dir);
	if (flag)
		Left_Check(node - 1, -dir);
}

void Right_Check(int node, int dir) {
	bool flag = false;
	if (node == T) {
		if (node != start)
			arr[node] = Rotate(node, dir);
		return;
	}
	if ((arr[node][2] == '0' && arr[node + 1][6] == '1') ||
		(arr[node][2] == '1' && arr[node + 1][6] == '0')) {
		flag = true;
	}
	if (node != start)
		arr[node] = Rotate(node, dir);
	if (flag)
		Right_Check(node + 1, -dir);
}

int main() {
	FASTIO;
	int K;
	cin >> T;
	FOR(i, 1, T) {
		cin >> arr[i];
	}
	cin >> K;
	FOR(i, 1, K) {
		int num, dir;
		cin >> num >> dir;
		start = num;
		Left_Check(num, dir);
		Right_Check(num, dir);
		arr[num] = Rotate(num, dir);
	}
	int ans = 0;
	FOR(i, 1, T) {
		if (arr[i][0] == '1')
			ans++;
	}
	cout << ans;

	return 0;
}