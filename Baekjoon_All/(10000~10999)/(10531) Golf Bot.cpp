#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define cd complex<double>
#define PI 3.14159265358979323846
#define MAX 200001

vector<bool> possible(MAX);

void FFT(vector<cd>& a, bool invert) {
	int n = LEN(a);
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			cd w(1);
			for (int j = 0; j < len / 2; j++) {
				cd u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) {
		FOR(i, 0, n - 1) a[i] /= n;
	}
}

void Multiply(vector<cd>& a, vector<cd>& b, vector<cd>& res) {
	vector<cd> fa(ALL(a)), fb(ALL(b));
	FFT(fa, false);
	FFT(fb, false);
	FOR(i, 0, LEN(a) - 1) {
		res[i] = fa[i] * fb[i];
	}
	FFT(res, true);
}

int main() {
	FASTIO;
	int N, M;
	vector<cd> p(1 << 19);
	vector<cd> res(1 << 19);
	int ans = 0;
	cin >> N;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		possible[num] = 1;
		p[num] = cd(1, 0);
	}

	Multiply(p, p, res);

	cin >> M;
	FOR(i, 0, M - 1) {
		int num;
		cin >> num;
		if (possible[num] || round(res[num].real())) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}