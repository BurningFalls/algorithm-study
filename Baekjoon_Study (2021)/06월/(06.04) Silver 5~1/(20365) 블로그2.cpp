#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char arr[500001];
bool flag;

int func() {
	int left = 1, right = N;
	int cnt = 0;
	while (left <= right) {
		if (!flag) {
			while (left <= N && arr[left] == 'B')
				left++;
			while (right >= 1 && arr[right] == 'B')
				right--;
		}
		else if (flag) {
			while (left <= N && arr[left] == 'R')
				left++;
			while (right >= 1 && arr[right] == 'R')
				right--;
		}
		flag = !flag;
		cnt++;
	}
	return cnt;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int cnt1, cnt2;
	flag = false;
	cnt1 = func();
	flag = true;
	cnt2 = func();
	cout << min(cnt1, cnt2);

	return 0;
}