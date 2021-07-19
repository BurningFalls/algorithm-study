#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	string filename;
	int is_exist;
	string extension;
} NODE;

NODE arr[200001];
set<string> se;

bool cmp(NODE a, NODE b) {
	if (a.filename == b.filename) {
		if (a.is_exist == b.is_exist) {
			return a.extension < b.extension;
		}
		return a.is_exist > b.is_exist;
	}
	return a.filename < b.filename;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		arr[i] = { s, 0, "" };
	}
	FOR(i, 1, M) {
		string s;
		cin >> s;
		se.insert(s);
	}
	FOR(i, 1, N) {
		string s = arr[i].filename;
		string tmp1 = "";
		string tmp2 = "";
		int len = s.size();
		bool flag = false;
		FOR(j, 0, len - 1) {
			if (s[j] == '.') {
				flag = true;
				continue;
			}
			if (flag)
				tmp2 += s[j];
			else
				tmp1 += s[j];
		}
		arr[i].filename = tmp1;
		arr[i].extension = tmp2;
		if (se.count(tmp2)) {
			arr[i].is_exist = 1;
		}
		else {
			arr[i].is_exist = 0;
		}
	}
	sort(arr + 1, arr + N + 1, cmp);
	FOR(i, 1, N) {
		cout << arr[i].filename << "." << arr[i].extension << "\n";
	}

	return 0;
}