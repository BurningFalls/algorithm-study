#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[10001];

void PostOrder(int start, int end) {
	if (start == end)
		return;
	if (start == end - 1) {
		cout << arr[start] << "\n";
		return;
	}
	int idx = start + 1;
	while (true) {
		if (!(idx < end && arr[idx] < arr[start]))
			break;
		idx++;
	}
	PostOrder(start + 1, idx);
	PostOrder(idx, end);
	cout << arr[start] << "\n";
}

int main() {
	FASTIO;
	int num;
	int idx = 0;
	while (cin >> num) {
		idx++;
		arr[idx] = num;
	}
	PostOrder(1, idx + 1);

	return 0;
}