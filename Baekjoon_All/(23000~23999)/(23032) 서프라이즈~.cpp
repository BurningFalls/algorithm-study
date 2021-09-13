#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int W[2001];
int Sum[2001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	Sum[0] = 0;
	FOR(i, 1, N) {
		cin >> W[i];
		Sum[i] = Sum[i - 1] + W[i];
	}
	int mini = 2100000000;
	int maxi_sum = 0;
	FOR(i, 1, N - 1) {
		int left = i;
		int right = i + 1;
		int Lsum = 0;
		int Rsum = 0;
		int diff = 2100000000;
		int storeL = i, storeR = i + 1;
		while (left >= 1 && right <= N) {
			Lsum += W[left];
			Rsum += W[right];
			int d = abs(Lsum - Rsum);
			if (d <= diff) {
				storeL = left;
				storeR = right;
				diff = d;
			}
			if (Lsum >= Rsum) {
				Lsum -= W[left];
				right++;
			}
			else if (Lsum < Rsum) {
				Rsum -= W[right];
				left--;
			}
		}
		if (mini > diff) {
			mini = diff;
			maxi_sum = Sum[storeR] - Sum[storeL - 1];
		}
		else if (mini == diff) {
			maxi_sum = max(maxi_sum, Sum[storeR] - Sum[storeL - 1]);
		}
	}
	cout << maxi_sum;


	return 0;
}