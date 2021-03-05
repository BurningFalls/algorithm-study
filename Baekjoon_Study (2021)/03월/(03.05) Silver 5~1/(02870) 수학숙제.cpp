#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

vector<string> v;

bool cmp(string a, string b) {
	int len1 = a.size();
	int len2 = b.size();
	if (len1 == len2) {
		FOR(i, 0, len1 - 1) {
			if (a[i] < b[i]) return true;
			if (a[i] > b[i]) return false;
		}
	}
	return len1 < len2;
}

string Ch(string x) {
	string ch_s = "";
	int x_len = x.size();
	bool x_flag = false;
	FOR(i, 0, x_len - 1) {
		if (!x_flag && x[i] == '0') continue;
		x_flag = true;
		ch_s += x[i];
	}
	if (ch_s == "")
		return "0";
	return ch_s;
}

int main() {
	FASTIO;
	int N;
	string arr[101];
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, 1, N) {
		string temp = "";
		int len = arr[i].size();
		bool flag = false;
		FOR(j, 0, len - 1) {
			if (arr[i][j] >= '0' && arr[i][j] <= '9') {
				flag = true;
				temp += arr[i][j];
			}
			else {
				if (flag) {
					flag = false;
					v.push_back(Ch(temp));
					temp = "";
				}
			}
		}
		if (flag) {
			flag = false;
			v.push_back(Ch(temp));
			temp = "";
		}
	}
	sort(v.begin(), v.end(), cmp);
	int v_len = v.size();
	for (string x : v) {
		cout << x << "\n";
	}

	return 0;
}