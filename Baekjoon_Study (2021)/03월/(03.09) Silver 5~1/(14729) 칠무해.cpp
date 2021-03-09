#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
int arr[100001] = { 0, };

int main() {
	FASTIO;
	double num;
	cin >> N;
	FOR(i, 1, N) {
		cin >> num;
		int tmp = num * 1000;
		arr[tmp] += 1;
	}
	int cnt = 0;
	int idx = 0;
	cout << fixed << setprecision(3);
	while(idx <= 100000 && cnt < 7) {
		if (arr[idx]) {
			double x = double(idx) / 1000;
			cout << x << "\n";
			arr[idx]--;
			cnt++;
		}
		else
			idx++;
	}

	return 0;
}