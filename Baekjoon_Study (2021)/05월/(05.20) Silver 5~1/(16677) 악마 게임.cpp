#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string input;
	cin >> input;
	int input_cnt[26] = { 0, };
	int len = input.size();
	FOR(i, 0, len - 1)
		input_cnt[input[i] - 'A']++;
	int N;
	string ans = "";
	cin >> N;
	pii maxi = { 0, 0 };
	FOR(i, 1, N) {
		string W;
		double G;
		int cnt[26] = { 0, };
		cin >> W >> G;
		int Wlen = W.size();
		FOR(j, 0, Wlen - 1)
			cnt[W[j] - 'A']++;
		bool flag = true;
		int sum = 0;
		FOR(j, 0, 25) {
			if (input_cnt[j] > cnt[j]) {
				flag = false;
				break;
			}
			sum += cnt[j] - input_cnt[j];
		}
		if (!flag) continue;
		if (maxi.first == 0 && maxi.second == 0) {
			maxi = { G, sum };
			ans = W;
		}
		else if (maxi.first * sum < maxi.second * G) {
			maxi = { G, sum };
			ans = W;
		}
	}
	if (ans == "")
		cout << "No Jam";
	else
		cout << ans;


	return 0;
}