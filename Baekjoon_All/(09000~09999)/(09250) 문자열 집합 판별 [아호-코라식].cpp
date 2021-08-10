#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct TRIE {
	TRIE* alpha[26];
	TRIE* fail;
	bool ans;
	TRIE() {
		FOR(i, 0, 25)
			alpha[i] = NULL;
		fail = NULL;
		ans = false;
	}
	~TRIE() {
		FOR(i, 0, 25) {
			if (alpha[i])
				delete alpha[i];
		}
	}
	void insert(string s, int idx) {
		if (idx == s.length()) {
			ans = true;
			return;
		}
		int next = s[idx] - 'a';
		if (alpha[next] == NULL)
			alpha[next] = new TRIE;
		alpha[next]->insert(s, idx + 1);
	}
};

queue<TRIE*> q;
TRIE* root = new TRIE;

void BFS() {
	while (!q.empty()) {
		TRIE* curr = q.front();
		q.pop();
		FOR(i, 0, 25) {
			if (!(curr->alpha[i])) continue;
			TRIE* next = curr->alpha[i];
			if (curr == root)
				next->fail = root;
			else {
				TRIE* prev = curr->fail;
				while (prev != root && !prev->alpha[i])
					prev = prev->fail;
				if (prev->alpha[i])
					prev = prev->alpha[i];
				next->fail = prev;
			}
			if (next->fail->ans)
				next->ans = true;
			q.push(next);
		}
	}
}

int main() {
	FASTIO;
	int N, Q;
	bool chk;
	string tmp;
	root->fail = root;

	cin >> N;
	FOR(i, 0, N - 1) {
		cin >> tmp;
		root->insert(tmp, 0);
	}

	q.push(root);
	BFS();

	cin >> Q;
	while (Q--) {
		cin >> tmp;
		chk = 0;
		TRIE* curr = root;
		FOR(i, 0, tmp.length() - 1) {
			int next = tmp[i] - 'a';
			while (curr != root && !curr->alpha[next])
				curr = curr->fail;
			if (curr->alpha[next])
				curr = curr->alpha[next];
			if (curr->ans) {
				chk = 1;
				break;
			}
		}
		cout << (chk ? "YES" : "NO") << "\n";
	}


	return 0;
}