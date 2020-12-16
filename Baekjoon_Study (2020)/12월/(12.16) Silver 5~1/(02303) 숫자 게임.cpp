#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[5];
bool choose[10][5] = { {1, 1, 1, 0, 0},
{1, 1, 0, 1, 0},
{1, 1, 0, 0, 1},
{1, 0, 1, 1, 0},
{1, 0, 1, 0, 1},
{1, 0, 0, 1, 1},
{0, 1, 1, 1, 0},
{0, 1, 1, 0, 1},
{0, 1, 0, 1 ,1},
{0, 0, 1, 1, 1} };

int main() {
	FASTIO;
	int N;
	int ans = -1;
	int maximum = -1;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 0, 4) {
			cin >> arr[j];
		}
		int sub_max = 0;
		FOR(j, 0, 9) {
			int sum = 0;
			FOR(k, 0, 4) {
				if (choose[j][k])
					sum += arr[k];
			}
			sub_max = max(sub_max, sum % 10);
		}
		if (maximum <= sub_max) {
			maximum = sub_max;
			ans = i;
		}
	}
	cout << ans;

	return 0;
}