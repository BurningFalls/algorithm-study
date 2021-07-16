#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	char x;
	char y;
	int is_same;
} NODE;

int N;
string expression;
map<string, pair<string, string>> mp;
vector<NODE> Stack;
int ans = 0;

void Make_Tree(string str) {
	int len = str.size();
	int qm_idx = -1;
	int coln_idx = -1;
	FOR(i, 0, len - 1) {
		if (str[i] == '?')
			qm_idx = i;
		else if (str[i] == ':')
			coln_idx = i;
	}
	string s1, s2, s3;
	s1 = str.substr(0, qm_idx);
	s2 = str.substr(qm_idx + 1, coln_idx - qm_idx - 1);
	s3 = str.substr(coln_idx + 1, len - coln_idx - 1);
	mp[s1] = { s2, s3 };
}

vector<pii> edge[28];
int	val[28];
bool small_flag;
bool visited[28];

void small_DFS(int node) {
	visited[node] = 1;
	int len = edge[node].size();
	FOR(i, 0, len - 1) {
		pii next = edge[node][i];
		if (next.second == 1) {
			if (val[next.first] == -1) {
				val[next.first] = val[node]; 
				if (visited[next.first]) continue;
				small_DFS(next.first);
			}
			else if (val[next.first] != -1) {
				if (val[next.first] != val[node]) {
					small_flag = false;
					return;
				}
			}
		}
		else if (next.second == 0) {
			if (val[next.first] == -1) {
				val[next.first] = 1 - val[node];
				if (visited[next.first]) continue;
				small_DFS(next.first);
			}
			else if (val[next.first] != -1) {
				if (val[next.first] == val[node]) {
					small_flag = false;
					return;
				}
			}
		}
	}
}

void Navigation() {
	memset(val, -1, sizeof(val));
	memset(visited, 0, sizeof(visited));
	small_flag = true;

	int group_cnt = 0;
	FOR(i, 0, N + 1) {
		if (visited[i]) continue;
		group_cnt++;
		small_DFS(i);
	}
	if (small_flag)
		ans += pow(2, group_cnt - 1);
}

void Make_Graph() {
	FOR(i, 0, 27)
		edge[i].clear();
	int stack_len = Stack.size();
	FOR(i, 0, stack_len - 2) {
		NODE n = Stack[i];
		int a = 0, b = 0;
		if (Stack[i].x == '0' || Stack[i].x == '1')
			a = Stack[i].x - '0';
		else if (Stack[i].x >= 'a' && Stack[i].x <= 'z')
			a = Stack[i].x - 'a' + 2;
		if (Stack[i].y == '0' || Stack[i].y == '1')
			b = Stack[i].y - '0';
		else if (Stack[i].y >= 'a' && Stack[i].y <= 'z')
			b = Stack[i].y - 'a' + 2;

		edge[a].push_back({ b, n.is_same });
		edge[b].push_back({ a, n.is_same });
	}
	char leaf = Stack[stack_len - 1].x;
	if (leaf == '1')
		return;
	int leaf_num;
	if (leaf == '0' || leaf == '1')
		leaf_num = leaf - '0';
	else if (leaf >= 'a' && leaf <= 'z')
		leaf_num = leaf - 'a' + 2;
	edge[0].push_back({ leaf_num, 1 });
	edge[leaf_num].push_back({ 0, 1 });
	edge[0].push_back({ 1, 0 });
	edge[1].push_back({ 0, 0 });

	Navigation();
}

void DFS(string node) {
	int len = node.size();
	if (len == 1) {
		Stack.push_back({ node[0], '#', 0 });
		Make_Graph();
	}
	else if (len != 1) {
		Stack.push_back({ node[0], node[3], 1 });
		DFS(mp[node].first);
		Stack.back().is_same = 0;
		DFS(mp[node].second);
	}
	Stack.pop_back();
}

void Seperate_Expression() {
	while (true) {
		int ex_len = expression.size();
		int qm_idx = -1;
		int sep_left_idx = -1;
		int sep_right_idx = ex_len;
		ROF(i, ex_len - 1, 0) {
			if (expression[i] == '?') {
				qm_idx = i;
				break;
			}
		}
		if (qm_idx == -1)
			break;
		ROF(i, qm_idx - 1, 0) {
			if (expression[i] == ':' || expression[i] == '?') {
				sep_left_idx = i;
				break;
			}
		}
		bool flag = false;
		FOR(i, qm_idx + 1, ex_len - 1) {
			if (!flag && expression[i] == ':') {
				flag = true;
			}
			else if (flag && expression[i] == ':') {
				sep_right_idx = i;
				break;
			}
		}
		int left = sep_left_idx + 1;
		int right = sep_right_idx - 1;
		string sub_expression = expression.substr(left, right - left + 1);
		expression.erase(qm_idx, right - qm_idx + 1);

		Make_Tree(sub_expression);
	}
	string root_ex = expression;
	DFS(root_ex);
}

int main() {
	FASTIO;
	cin >> N;
	cin >> expression;
	Seperate_Expression();

	cout << ans;

	return 0;
}