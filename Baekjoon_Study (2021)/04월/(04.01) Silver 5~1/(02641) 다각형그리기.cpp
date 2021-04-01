#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
set<string> Set;
string input = "";
vector<string> ans_v;

void Func() {
	for (int start = 0; start < N; start++) {
		int idx = start;
		string tmp = "";
		while (true) {
			tmp += input[idx];
			idx = (idx + 1) % N;
			if (idx == start)
				break;
		}
		Set.insert(tmp);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		char x;
		cin >> x;
		input += x;
	}

	Func();
	reverse(input.begin(), input.end());
	Func();
	FOR(i, 0, N - 1) {
		int tmp = input[i] - '0';
		tmp = (tmp + 1) % 4 + 1;
		input[i] = tmp + '0';
	}
	Func();
	reverse(input.begin(), input.end());
	Func();

	cin >> M;
	FOR(i, 1, M) {
		string tmp = "";
		FOR(j, 1, N) {
			char x;
			cin >> x;
			tmp += x;
		}
		if (Set.count(tmp))
			ans_v.push_back(tmp);
	}
	int len = ans_v.size();
	cout << len << "\n";
	FOR(i, 0, len - 1) {
		int slen = ans_v[i].size();
		FOR(j, 0, slen - 1) {
			cout << ans_v[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}