#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
int cnt1[53] = { 0, };
int cnt2[53] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		cnt1[num]++;
	}
	string s;
	cin.ignore();
	getline(cin, s);
	int len = s.size();
	FOR(i, 0, len - 1) {
		if (s[i] == ' ')
			cnt2[0]++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			cnt2[s[i] - 'A' + 1]++;
		else if (s[i] >= 'a' && s[i] <= 'z')
			cnt2[s[i] - 'a' + 27]++;
	}
	bool flag = true;
	FOR(i, 0, 52) {
		if (cnt1[i] != cnt2[i]) {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "y";
	else
		cout << "n";


	return 0;
}