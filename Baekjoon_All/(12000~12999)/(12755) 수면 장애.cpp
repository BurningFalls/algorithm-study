#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[10] = { 0, 9, 189, 2889, 38889, 488889,
5888889, 68888889, 788888889 };

int main() {
	FASTIO;
	int N;
	cin >> N;
	int idx = 1;
	while (idx <= 9 && N > arr[idx])
		idx++;
	N = N - arr[idx - 1] - 1;
	int tmp = N / idx;
	int num = pow(10, idx - 1) + tmp;
	tmp = N - tmp * idx;
	string s = to_string(num);
	cout << s[tmp];


	return 0;
}