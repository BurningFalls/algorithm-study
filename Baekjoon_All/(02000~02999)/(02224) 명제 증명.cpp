#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool arr[52][52] = { 0, };
vector<pair<char, char>> v;

int main() {
	FASTIO;
	int N;
	cin >> N;
	cin.ignore();
	FOR(i, 1, N) {
		int num1, num2;
		string s;
		getline(cin, s);
		int len = s.size();
		if (s[0] >= 'A' && s[0] <= 'Z')
			num1 = s[0] - 'A';
		else if (s[0] >= 'a' && s[0] <= 'z')
			num1 = s[0] - 'a' + 26;
		if (s[len - 1] >= 'A' && s[len - 1] <= 'Z')
			num2 = s[len - 1] - 'A';
		else if (s[len - 1] >= 'a' && s[len - 1] <= 'z')
			num2 = s[len - 1] - 'a' + 26;
		arr[num1][num2] = 1;
	}
	FOR(k, 0, 51) {
		FOR(i, 0, 51) {
			FOR(j, 0, 51) {
				if (i == j || i == k || k == j) continue;
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;
			}
		}
	}
	FOR(i, 0, 51) {
		char c1, c2;
		if (i >= 0 && i <= 25)
			c1 = i + 'A';
		else if (i >= 26 && i <= 51)
			c1 = i - 26 + 'a';
		FOR(j, 0, 51) {
			if (i == j) continue;
			if (!arr[i][j]) continue;
			if (j >= 0 && j <= 25)
				c2 = j + 'A';
			else if (j >= 26 && j <= 51)
				c2 = j - 26 + 'a';
			v.push_back({ c1, c2 });
		}
	}
	int cnt = v.size();
	cout << cnt << "\n";
	FOR(i, 0, cnt - 1) {
		cout << v[i].first << " => " << v[i].second << "\n";
	}


	return 0;
}