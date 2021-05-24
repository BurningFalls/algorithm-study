#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1000001];

int main() {
	FASTIO;
	int N;
	deque<int> dq;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> arr[i];
	}
	ROF(i, N, 1) {
		int num = N - i + 1;
		if (arr[i] == 1) {
			dq.push_front(num);
		}
		else if (arr[i] == 2) {
			int tmp = dq.front();
			dq.pop_front();
			dq.push_front(num);
			dq.push_front(tmp);
		}
		else if (arr[i] == 3) {
			dq.push_back(num);
		}
	}
	for (int x : dq) {
		cout << x << " ";
	}

	return 0;
}