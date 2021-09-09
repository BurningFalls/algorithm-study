#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

struct NODE {
	int y;
	int x;
	int a;
	int b;
	int idx;
};

NODE arr[100001];

bool cmp1(NODE a, NODE b) {
	return a.y < b.y;
}

bool cmp2(NODE a, NODE b) {
	return a.x < b.x;
}

bool cmp3(NODE a, NODE b) {
	return a.idx < b.idx;
}

int main() {
	FASTIO;
	int H, W, N;
	cin >> H >> W >> N;
	FOR(i, 1, N) {
		int A, B;
		cin >> A >> B;
		arr[i] = { A, B, 0, 0, i };
	}
	sort(arr + 1, arr + N + 1, cmp1);
	int idx = 0;
	int prev = 0;
	FOR(i, 1, N) {
		if (prev != arr[i].y) {
			arr[i].a = ++idx;
			prev = arr[i].y;
		}
		else if (prev == arr[i].y) {
			arr[i].a = idx;
		}
	}
	sort(arr + 1, arr + N + 1, cmp2);
	idx = 0;
	prev = 0;
	FOR(i, 1, N) {
		if (prev != arr[i].x) {
			arr[i].b = ++idx;
			prev = arr[i].x;
		}
		else if (prev == arr[i].x) {
			arr[i].b = idx;
		}
	}
	sort(arr + 1, arr + N + 1, cmp3);
	FOR(i, 1, N) {
		cout << arr[i].a << " " << arr[i].b << "\n";
	}


	return 0;
}