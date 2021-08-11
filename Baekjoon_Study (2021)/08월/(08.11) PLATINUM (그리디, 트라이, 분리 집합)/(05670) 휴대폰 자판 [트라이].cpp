#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int answer;
string arr[100001];

class Trie {
private:
	Trie* childs[26];
	int child_cnt;
	bool isRoot, finish;
public:
	Trie(bool isroot) {
		FOR(i, 0, 25)
			childs[i] = NULL;
		finish = false;
		isRoot = isroot;
		child_cnt = 0;
	}
	~Trie() {
		FOR(i, 0, 25) {
			if (childs[i] != NULL)
				delete childs[i];
		}
	}
	void insert(const char* cur) {
		if (*cur == '\0') {
			finish = true;
			return;
		}
		int pos = *cur - 'a';
		if (childs[pos] == NULL) {
			childs[pos] = new Trie(false);
			child_cnt++;
		}
		childs[pos]->insert(cur + 1);
	}
	void find(const char* cur) {
		if (*cur == '\0')
			return;
		int pos = *cur - 'a';
		if (isRoot)
			answer++;
		else {
			if (child_cnt > 1)
				answer++;
			else if (finish)
				answer++;
		}
		childs[pos]->find(cur + 1);
	}
};

int main() {
	FASTIO;
	cout << fixed << setprecision(2);
	while (cin >> N) {
		FOR(i, 1, N)
			cin >> arr[i];
		Trie root = Trie(true);
		FOR(i, 1, N)
			root.insert(arr[i].c_str());
		int total = 0;
		FOR(i, 1, N) {
			answer = 0;
			root.find(arr[i].c_str());
			total += answer;
		}
		double avg = (double)total / N;
		cout << avg << "\n";
	}

	return 0;
}