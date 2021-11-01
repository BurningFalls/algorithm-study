#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int T, N;
int player_pos[100001];
int player_item[100001][54] = { 0, };
set<int> illegal, block;

int main() {
	FASTIO;
	cin >> T >> N;
	FOR(i, 1, N) {
		player_pos[i] = 1;
	}
	FOR(t, 1, T) {
		int log_num;
		int player_num;
		char act_code;
		int act_num1;
		int act_num2;
		cin >> log_num >> player_num >> act_code;
		cin >> act_num1;
		if (act_code == 'M') {
			player_pos[player_num] = act_num1;
		}
		else if (act_code == 'F') {
			player_item[player_num][act_num1]++;
			if (player_pos[player_num] != act_num1) {
				illegal.insert(log_num);
			}
		}
		else if (act_code == 'C') {
			cin >> act_num2;
			if (player_item[player_num][act_num1] == 0 || player_item[player_num][act_num2] == 0) {
				illegal.insert(log_num);
			}
			player_item[player_num][act_num1] = max(0, player_item[player_num][act_num1] - 1);
			player_item[player_num][act_num2] = max(0, player_item[player_num][act_num2] - 1);
		}
		else if (act_code == 'A') {
			if (player_pos[player_num] != player_pos[act_num1]) {
				illegal.insert(log_num);
				block.insert(player_num);
			}
		}
	}
	cout << LEN(illegal) << "\n";
	if (LEN(illegal) != 0) {
		for (int x : illegal) {
			cout << x << " ";
		}
		cout << "\n";
	}
	cout << LEN(block) << "\n";
	if (LEN(block) != 0) {
		for (int x : block) {
			cout << x << " ";
		}
		cout << "\n";
	}


	return 0;
}