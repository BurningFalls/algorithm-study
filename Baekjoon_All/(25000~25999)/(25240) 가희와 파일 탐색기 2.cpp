#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF int(2e9)
#define LINF ll(1e18)

struct NODE {
	string perm;
	string owner;
	string group;
};

map<string, set<string>> group_mp;
map<string, NODE> file_mp;

int main() {
	FASTIO;
	int U, F;
	cin >> U >> F;
	cin.ignore();
	FOR(u, 1, U) {
		string user_name;
		string input;
		getline(cin, input);
		string tmp = "";
		int idx = 0;
		int len = LEN(input);
		while (idx < len) {
			if (input[idx] == ' ') {
				idx++;
				break;
			}
			tmp += input[idx];
			idx++;
		}
		user_name = tmp;
		string group = "";
		while (idx < len) {
			if (input[idx] == ',') {
				group_mp[group].insert(user_name);
				group = "";
			}
			else {
				group += input[idx];
			}
			idx++;
		}
		group_mp[group].insert(user_name);
	}

	FOR(f, 1, F) {
		string file_name, file_perm, owner, owned_group;
		cin >> file_name >> file_perm >> owner >> owned_group;
		file_mp[file_name] = { file_perm, owner, owned_group };
	}

	vector<vector<int>> perm_v(8, vector<int>(3));
	perm_v[0] = { 0, 0, 0 };
	perm_v[1] = { 0, 0, 1 };
	perm_v[2] = { 1, 1, 0 };
	perm_v[3] = { 1, 1, 1 };
	perm_v[4] = { 1, 0, 0 };
	perm_v[5] = { 1, 0, 1 };
	perm_v[6] = { 1, 1, 0 };
	perm_v[7] = { 1, 1, 1 };

	int Q;
	cin >> Q;
	FOR(q, 1, Q) {
		string user_name, file_name;
		char oper;
		cin >> user_name >> file_name >> oper;
		NODE n = file_mp[file_name];
		vector<int> user_perm(3, 0), group_perm(3, 0), other_perm(3, 0);
		FOR(i, 0, 2) {
			other_perm[i] = perm_v[n.perm[2] - '0'][i];
			group_perm[i] = other_perm[i] | perm_v[n.perm[1] - '0'][i];
			user_perm[i] = group_perm[i] | perm_v[n.perm[0] - '0'][i];
		}
		bool flag = false;
		if (n.owner == user_name) {
			flag = ((oper == 'R' && user_perm[0]) || (oper == 'W' && user_perm[1]) || (oper == 'X' && user_perm[2]));
		}
		else {
			bool is_name_exist = (n.group == user_name || group_mp[n.group].count(user_name));
			if (is_name_exist) {
				flag = ((oper == 'R' && group_perm[0]) || (oper == 'W' && group_perm[1]) || (oper == 'X' && group_perm[2]));
			}
			else if (!is_name_exist) {
				flag = ((oper == 'R' && other_perm[0]) || (oper == 'W' && other_perm[1]) || (oper == 'X' && other_perm[2]));
			}
		}
		cout << flag << "\n";
	}

	return 0;
}