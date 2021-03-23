#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	queue<int> q;
	cin >> N;
	int cnt = 0;
	while (true) {
		int num;
		cin >> num;
		if (num == -1)
			break;
		if (num > 0 && cnt < N) {
			q.push(num);
			cnt++;
		}
		else if (num == 0) {
			q.pop();
			cnt--;
		}
	}
	if (q.empty())
		cout << "empty";
	else {
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			cout << x << " ";
		}
	}

	return 0;
}