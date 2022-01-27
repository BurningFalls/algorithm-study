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
#define INF 2e9
#define LINF 1e18

vector<int> Split(string s) {
	s += ' ';
	vector<int> ans;
	string tmp = "";
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == ' ') {
			ans.push_back(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += s[i];
		}
	}
	return ans;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<vector<int>> A;
	vector<int> tmp;
	cin.ignore();
	FOR(i, 0, N - 1) {
		string str;
		getline(cin, str);
		tmp = Split(str);
		A.push_back(tmp);
	}
	int pos = 1;
	FOR(i, 0, N - 1) {
		int next = 0;
		if (pos <= 13) {
			int left_sum = 0;
			FOR(j, 0, LEN(A[i]) - 1) {
				if (j % 2 == 0) {
					next += A[i][j];
				}
				else if (j % 2 == 1) {
					if (left_sum + A[i][j] >= pos) {
						next += pos - left_sum;
						break;
					}
					else {
						next += A[i][j];
						left_sum += A[i][j];
					}
				}
			}
		}
		else if (pos >= 14) {
			pos -= 13;
			int right_sum = 0;
			FOR(j, 0, LEN(A[i]) - 1) {
				if (j % 2 == 1) {
					next += A[i][j];
				}
				else if (j % 2 == 0) {
					if (right_sum + A[i][j] >= pos) {
						next += pos - right_sum;
						break;
					}
					else {
						next += A[i][j];
						right_sum += A[i][j];
					}
				}
			}
		}
		pos = next;
	}
	cout << pos;

	return 0;
}