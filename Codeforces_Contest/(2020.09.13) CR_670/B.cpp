#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		int plus_cnt = 0;
		int zero_cnt = 0;
		int minus_cnt = 0;
		int num;
		vector<ll> p_v, m_v;
		cin >> n;
		FOR(i, 1, n) {
			cin >> num;
			if (num > 0) {
				plus_cnt++;
				p_v.push_back(num);
			}
			else if (num == 0)
				zero_cnt++;
			else if (num < 0) {
				minus_cnt++;
				m_v.push_back(num);
			}
		}
		if (!p_v.empty())
			sort(p_v.begin(), p_v.end(), greater<int>());
		if (!m_v.empty())
			sort(m_v.begin(), m_v.end());
		if (plus_cnt + zero_cnt + minus_cnt == 5) {
			if (zero_cnt != 0)
				cout << 0;
			else {
				ll temp = 1;
				FOR(i, 0, plus_cnt - 1)
					temp *= p_v[i];
				FOR(i, 0, minus_cnt - 1)
					temp *= m_v[i];
				cout << temp;
			}
		}
		else {
			if (plus_cnt == 0) {
				if (zero_cnt != 0)
					cout << 0;
				else {
					int len = m_v.size();
					cout << m_v[len - 1] * m_v[len - 2] * m_v[len - 3] * m_v[len - 4] * m_v[len - 5];
				}
			}
			else if (plus_cnt == 1 || plus_cnt == 2) {
				ll a = 0, b = 0;
				if (minus_cnt >= 4)
					a = p_v[0] * m_v[0] * m_v[1] * m_v[2] * m_v[3];
				cout << max(b, a);
			}
			else if (plus_cnt == 3 || plus_cnt == 4) {
				ll a = 0, b = 0;
				if (minus_cnt >= 2)
					a = p_v[0] * p_v[1] * p_v[2] * m_v[0] * m_v[1];
				if (minus_cnt >= 4)
					b = p_v[0] * m_v[0] * m_v[1] * m_v[2] * m_v[3];
				cout << max(a, b);
			}
			else {
				ll a = 0, b = 0, c = 0;
				a = p_v[0] * p_v[1] * p_v[2] * p_v[3] * p_v[4];
				if (minus_cnt >= 2)
					b = p_v[0] * p_v[1] * p_v[2] * m_v[0] * m_v[1];
				if (minus_cnt >= 4)
					c = p_v[0] * m_v[0] * m_v[1] * m_v[2] * m_v[3];
				cout << max({ a, b, c });
			}
		}
		cout << "\n";
	}

	return 0;
}