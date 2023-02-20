#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<char> front, back;
	vector<int> kind;
	FOR(i, 1, N) {
		int k;
		char c;
		cin >> k;
		if (k == 2) {
			cin >> c;
			front.push_back(c);
			kind.push_back(2);
		}
		else if (k == 1) {
			cin >> c;
			back.push_back(c);
			kind.push_back(1);
		}
		else if (k == 3) {
			if (kind.empty()) continue;
			if (kind.back() == 2) {
				front.pop_back();
			}
			else if (kind.back() == 1) {
				back.pop_back();
			}
			kind.pop_back();
		}
	}
	
	if (front.empty() && back.empty()) {
		cout << 0;
	}
	else {
		ROF(i, LEN(front) - 1, 0) {
			cout << front[i];
		}
		FOR(i, 0, LEN(back) - 1) {
			cout << back[i];
		}
	}

	return 0;
}