#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1000];
vector<int> v;

int main() {
	FASTIO;
	int N;
	int sum = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum /= 2;
	int sub_sum;
	FOR(i, 1, N) {
		sub_sum = 0;
		for (int j = i % N + 1; j != i; j = (j + 1) % N + 1) {
			sub_sum += arr[j];
		}
		v.push_back(sum - sub_sum);
	}
	for (int x : v)
		cout << x << "\n";

	return 0;
}