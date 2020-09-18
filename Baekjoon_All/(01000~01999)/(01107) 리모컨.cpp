#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N, M;
	int num;
	bool visited[11] = { 0, };
	int temp, len;
	int ans1 = INF, ans2 = INF, ans3 = INF;
	cin >> N;
	cin >> M;
	FOR(i, 1, M) {
		cin >> num;
		visited[num] = 1;
	}
	ans3 = abs(N - 100);
	temp = N;
	while (temp >= 0) {
		bool flag = true;
		string s = to_string(temp);
		len = s.size();
		FOR(i, 0, len - 1) {
			if (visited[s[i] - '0'] == 1) {
				flag = false;
				break;
			}
		}
		if (len + N - temp > ans3)
			break;
		if (flag) {
			ans1 = len;
			ans1 += N - temp;
			break;
		}
		temp--;
	}
	temp = N;
	while (true) {
		bool flag = true;
		string s = to_string(temp);
		len = s.size();
		FOR(i, 0, len - 1) {
			if (visited[s[i] - '0'] == 1) {
				flag = false;
				break;
			}
		}
		if (len + temp - N > ans3)
			break;
		if (flag) {
			ans2 = len;
			ans2 += temp - N;
			break;
		}
		temp++;
	}
	cout << min({ ans1, ans2, ans3 });

	return 0;
}