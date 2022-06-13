#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		string s, t;
		cin >> N;
		cin >> s >> t;
		vector<char> v1, v2;
		vector<int> cnt1(3, 0), cnt2(3, 0);
		bool flag = true;
		FOR(i, 0, N - 1) {
			if (s[i] == 'a')
				cnt1[0]++;
			else if (s[i] == 'b')
				cnt1[1]++;
			else if (s[i] == 'c')
				cnt1[2]++;
			if (t[i] == 'a')
				cnt2[0]++;
			else if (t[i] == 'b')
				cnt2[1]++;
			else if (t[i] == 'c')
				cnt2[2]++;
		}
		FOR(i, 0, 2) {
			if (cnt1[i] != cnt2[i]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
			continue;
		}

		FOR(i, 0, N - 1) {
			if (s[i] == 'a' || s[i] == 'b')
				v1.push_back(s[i]);
			if (t[i] == 'a' || t[i] == 'b')
				v2.push_back(t[i]);
		}
		int bcnt1 = 0, bcnt2 = 0;
		FOR(i, 0, LEN(v1) - 1) {
			if (v1[i] == 'b')
				bcnt1++;
			if (v2[i] == 'b')
				bcnt2++;
			if (bcnt1 > bcnt2) {
				flag = false;
				break;
			}
		}

		v1.clear();
		v2.clear();
		FOR(i, 0, N - 1) {
			if (s[i] == 'b' || s[i] == 'c')
				v1.push_back(s[i]);
			if (t[i] == 'b' || t[i] == 'c')
				v2.push_back(t[i]);
		}
		int ccnt1 = 0, ccnt2 = 0;
		FOR(i, 0, LEN(v1) - 1) {
			if (v1[i] == 'c')
				ccnt1++;
			if (v2[i] == 'c')
				ccnt2++;
			if (ccnt1 > ccnt2) {
				flag = false;
				break;
			}
		}

		v1.clear();
		v2.clear();
		FOR(i, 0, N - 1) {
			if (s[i] == 'a' || s[i] == 'c')
				v1.push_back(s[i]);
			if (t[i] == 'a' || t[i] == 'c')
				v2.push_back(t[i]);
		}
		FOR(i, 0, LEN(v1) - 1) {
			if (v1[i] != v2[i]) {
				flag = false;
				break;
			}
		}

		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}