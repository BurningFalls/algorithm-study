#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

double arr[53] = { 0, };
double diff[53];

string Ch(int x) {
	int a = x / 60;
	int b = x % 60;
	string ans = "";
	if (a < 10)
		ans += '0';
	ans += to_string(a);
	ans += ':';
	if (b < 10)
		ans += '0';
	ans += to_string(b);
	return ans;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	int Time;
	int a, b; char c;
	cin >> a >> c >> b;
	Time = a * 60 + b;
	FOR(i, 0, N) {
		string s;
		cin >> s;
		int len = s.size();
		bool flag = false;
		string tmp = "";
		FOR(j, 0, len - 1) {
			if (s[j] == '+' || s[j] == '-')
				flag = true;
			if (flag) {
				tmp += s[j];
			}
		}
		int tmp_len = tmp.size();
		bool poin = false;
		if (tmp_len >= 3 && tmp[tmp_len - 2] == '.' && tmp[tmp_len - 1] == '5') {
			poin = true;
			tmp.pop_back();
			tmp.pop_back();
		}
		arr[i] += stoi(tmp);
		if (poin) {
			if (arr[i] >= 0)
				arr[i] += 0.5;
			else
				arr[i] -= 0.5;
		}
	}
	FOR(i, 0, N - 1) {
		diff[i] = arr[i + 1] - arr[i];
		diff[i] *= 60;
	}
	FOR(i, 0, N - 1) {
		Time += diff[i];
		Time = (Time + 1440) % 1440;
		cout << Ch(Time) << "\n";
	}


	return 0;
}