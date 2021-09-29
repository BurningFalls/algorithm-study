#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

vector<pii> v;
vector<pii> ans_v;
int arr[51];

bool cmp(pii a, pii b) {
	return a.second < b.second;
}

void Ch_arr(int left, int right) {
	int tmp = arr[left];
	FOR(i, left, right - 1) {
		arr[i] = arr[i + 1];
	}
	arr[right] = tmp;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		v.clear();
		ans_v.clear();
		int N;
		cin >> N;
		FOR(i, 0, N - 1) {
			int num;
			cin >> num;
			v.push_back({ num, i });
		}
		sort(v.begin(), v.end());
		int num = 0;
		int prev = -2100000000;
		FOR(i, 0, N - 1) {
			if (prev != v[i].first) {
				num++;
				v[i].first = num;
			}
			prev = v[i].first;
		}
		sort(v.begin(), v.end(), cmp);
		FOR(i, 0, N - 1)
			arr[i] = v[i].first;
		FOR(i, 1, num - 1) {
			int idx1 = 0, idx2 = 0;
			while (true) {
				ROF(j, N - 1, 0) {
					if (arr[j] == i) {
						idx1 = j;
						break;
					}
				}
				FOR(j, 0, N - 1) {
					if (arr[j] == i + 1) {
						idx2 = j;
						break;
					}
				}
				if (idx1 < idx2)
					break;
				ans_v.push_back({ idx2 + 1, idx1 + 1 });
				Ch_arr(idx2, idx1);
			}
		}
		cout << LEN(ans_v) << "\n";
		for (pii x : ans_v)
			cout << x.first << " " << x.second << " 1\n";
	}

	return 0;
}