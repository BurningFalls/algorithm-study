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

void FFT(vector<cd> &a, bool invert) {
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

void Multiply(vector<int> &a, vector<int> &b, vector<int> &res) {
	vector<cd> fa(ALL(a)), fb(ALL(b));
	int n = 1;
	while (n < max(LEN(a), LEN(b))) n <<= 1;
	fa.resize(n);
	fb.resize(n);
	FFT(fa, false);
	FFT(fb, false);
	FOR(i, 0, n - 1) fa[i] *= fb[i];
	FFT(fa, true);
	res.resize(n);
	FOR(i, 0, n - 1) res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> X(2 * N), Y(N), S;
	FOR(i, 0, N - 1) {
		cin >> X[i];
		X[i + N] = X[i];
	}
	ROF(i, N - 1, 0) {
		cin >> Y[i];
	}
	Multiply(X, Y, S);
	int maxi = -1;
	FOR(i, N, 2 * N - 1) {
		maxi = max(maxi, S[i]);
	}
	cout << maxi;

	return 0;
}