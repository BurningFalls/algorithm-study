#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define ld long double
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18
#define MAX 200001

int N, Q;
vector<ld> X(MAX), Y(MAX);
vector<ld> A(MAX), B(MAX);
vector<ld> tree1(4 * MAX), tree2(4 * MAX);

ld Init1(int node, int start, int end) {
	if (start == end) {
		return tree1[node] = A[start];
	}
	int mid = (start + end) / 2;
	ld LQ = Init1(node * 2, start, mid);
	ld RQ = Init1(node * 2 + 1, mid + 1, end);
	return tree1[node] = LQ + RQ;
}

ld Init2(int node, int start, int end) {
	if (start == end) {
		return tree2[node] = B[start];
	}
	int mid = (start + end) / 2;
	ld LQ = Init2(node * 2, start, mid);
	ld RQ = Init2(node * 2 + 1, mid + 1, end);
	return tree2[node] = LQ + RQ;
}

ld Query1(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree1[node];
	}
	int mid = (start + end) / 2;
	ld LQ = Query1(node * 2, start, mid, left, right);
	ld RQ = Query1(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
}

ld Query2(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree2[node];
	}
	int mid = (start + end) / 2;
	ld LQ = Query2(node * 2, start, mid, left, right);
	ld RQ = Query2(node * 2 + 1, mid + 1, end, left, right);
	return LQ + RQ;
}

int main() {
	FASTIO;
	cin >> N >> Q;
	FOR(i, 1, N) {
		cin >> X[i];
	}
	FOR(i, 1, N) {
		cin >> Y[i];
	}

	FOR(i, 1, N - 1) {
		ld a = pow(Y[i + 1] - Y[i], 2);
		ld b = pow(X[i + 1] - X[i], 2);
		ld tmp = sqrt(a + b);
		if (Y[i] < Y[i + 1]) {
			A[i] = tmp * 3;
			B[i] = tmp;
		}
		else if (Y[i] == Y[i + 1]) {
			A[i] = tmp * 2;
			B[i] = tmp * 2;
		}
		else if (Y[i] > Y[i + 1]) {
			A[i] = tmp;
			B[i] = tmp * 3;
		}
	}

	Init1(1, 1, N - 1);
	Init2(1, 1, N - 1);

	cout << fixed << setprecision(4);
	FOR(q, 1, Q) {
		int i, j;
		cin >> i >> j;
		if (i < j) {
			cout << Query1(1, 1, N - 1, i, j - 1);
		}
		else if (i > j) {
			cout << Query2(1, 1, N - 1, j, i - 1);
		}
		cout << "\n";
	}

	return 0;
}