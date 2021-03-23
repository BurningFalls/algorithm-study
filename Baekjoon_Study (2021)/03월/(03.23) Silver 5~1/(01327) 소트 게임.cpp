#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, K;
string arr = "";
map<string, int> mp;

bool is_Increasing(string s) {
	FOR(i, 0, N - 2) {
		if (s[i] > s[i + 1])
			return false;
	}
	return true;
}

string SWAP(string s, int start, int end) {
	while (start < end) {
		swap(s[start], s[end]);
		start++;
		end--;
	}
	return s;
}

int BFS() {
	queue<string> q;
	if (is_Increasing(arr))
		return 0;
	q.push(arr);
	mp.insert({ arr, 1 });
	while (!q.empty()) {
		string node = q.front();
		int vis = mp[node];
		q.pop();
		FOR(i, 0, N - K) {
			string new_node;
			new_node = SWAP(node, i, i + K - 1);
			if (mp.count(new_node)) continue;
			if (is_Increasing(new_node))
				return vis;
			mp.insert({ new_node, vis + 1 });
			q.push(new_node);
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> N >> K;
	FOR(i, 1, N) {
		char x;
		cin >> x;
		arr += x;
	}
	cout << BFS();

	return 0;
}