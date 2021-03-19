#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[8] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };

int func(string s) {
	FOR(i, 0, 7) {
		int cnt = 0;
		FOR(j, 0, 5) {
			if (arr[i][j] != s[j])
				cnt++;
		}
		if (cnt == 1)
			return i;
	}
	return -1;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	string s;
	cin >> s;
	int len = s.size();
	vector<char> v;
	FOR(i, 0, N - 1) {
		string sub = "";
		FOR(j, 6 * i, 6 * i + 5)
			sub += s[j];
		int pos = -1;
		FOR(j, 0, 7) {
			if (sub == arr[j])
				pos = j;
		}
		if (pos == -1) {
			int flag = func(sub);
			if (flag == -1) {
				v.clear();
				v.push_back((i + 1) + '0');
				break;
			}
			else
				v.push_back(flag + 'A');
		}
		else
			v.push_back(pos + 'A');
	}
	for (char node : v)
		cout << node;

	return 0;
}