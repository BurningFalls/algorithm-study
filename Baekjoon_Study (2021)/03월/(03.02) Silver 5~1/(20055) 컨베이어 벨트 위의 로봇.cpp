#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, K;
int A[201];
deque<int> conv;
deque<int> dura;

void Rotate() {
	conv.push_front(conv.back());
	conv.pop_back();
	dura.push_front(dura.back());
	dura.pop_back();
	conv[N - 1] = false;
}

void Move() {
	ROF(i, N - 2, 0) {
		if (!conv[i]) continue;
		if (conv[i + 1]) continue;
		if (dura[i + 1] == 0) continue;
		conv[i] = false;
		conv[i + 1] = true;
		dura[i + 1]--;
	}
	conv[N - 1] = false;
}

void Put() {
	if (conv[0]) return;
	if (dura[0] == 0) return;
	conv[0] = true;
	dura[0]--;
}

int End() {
	int cnt = 0;
	FOR(i, 0, 2 * N - 1) {
		if (dura[i] == 0)
			cnt++;
	}
	return cnt >= K;
}

int main() {
	FASTIO;
	int time = 1;
	cin >> N >> K;
	FOR(i, 0, 2 * N - 1) {
		int num;
		cin >> num;
		dura.push_back(num);
		conv.push_back(false);
	}

	while (true) {
		Rotate();
		Move();
		Put();
		if (End())
			break;
		time++;
	}
	cout << time;

	return 0;
}