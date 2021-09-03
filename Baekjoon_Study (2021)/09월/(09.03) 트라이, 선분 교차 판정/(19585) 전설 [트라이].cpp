#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int C, N, Q;
int check[2001];

struct Trie {
	map<char, Trie*> ch;
	bool end;
	Trie() {
		end = false;
		ch.clear();
	}
	void insert(const char* s) {
		if (!*s) {
			end = true;
			return;
		}
		int now = *s - 'a';
		if (!ch.count(now))
			ch[now] = new Trie;
		ch[now]->insert(s + 1);
	}
	void find(const char* s, int k, bool forward) {
		if (end)
			check[k]++;
		if (!*s)
			return;
		int now = *s - 'a';
		if (!ch.count(now))
			return;
		ch[now]->find(s + 1, (forward ? k + 1 : k - 1), forward);
	}
};

int main() {
	FASTIO;
	cin >> C >> N;
	Trie* root1 = new Trie;
	Trie* root2 = new Trie;
	string s;
	FOR(i, 1, C) {
		cin >> s;
		root1->insert(s.c_str());
	}
	FOR(i, 1, N) {
		cin >> s;
		reverse(s.begin(), s.end());
		root2->insert(s.c_str());
	}
	cin >> Q;
	FOR(q, 1, Q) {
		string s;
		cin >> s;
		MEMSET(check, 0);
		root1->find(s.c_str(), 0, true);
		reverse(s.begin(), s.end());
		root2->find(s.c_str(), LEN(s), false);
		bool ans = false;
		FOR(i, 0, LEN(s) - 1) {
			if (check[i] == 2) {
				ans = true;
				break;
			}
		}
		cout << (ans ? "Yes" : "No") << "\n";
	}


	return 0;
}