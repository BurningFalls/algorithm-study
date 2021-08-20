#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct Trie {
	map<string, Trie*> m;
	Trie() {}
	~Trie() {
		for (auto it = m.begin(); it != m.end(); it++)
			delete (*it).second;
	}
	void Find(int depth) {
		for (auto it = m.begin(); it != m.end(); it++) {
			FOR(i, 0, depth - 1)
				cout << "--";
			cout << (*it).first << "\n";
			(*it).second->Find(depth + 1);
		}
	}
	void Insert(vector<string>& v, int idx) {
		if (v.size() == idx)
			return;
		if (m.find(v[idx]) == m.end())
			m.insert({ v[idx], new Trie() });
		m[v[idx]]->Insert(v, idx + 1);
	}
};

int main() {
	FASTIO;
	int N;
	cin >> N;
	Trie* root = new Trie();
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		vector<string> v;
		FOR(j, 1, cnt) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		root->Insert(v, 0);
	}
	root->Find(0);
	delete root;

	return 0;
}