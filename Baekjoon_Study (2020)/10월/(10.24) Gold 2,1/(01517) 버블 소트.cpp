#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 500000 + 1

int N;
int A[MAX], B[MAX];
ll result = 0;

void Merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int idx = 0;
	while (i <= mid || j <= right) {
		if (i <= mid && (j > right || A[i] <= A[j]))
			B[idx++] = A[i++];
		else {
			B[idx++] = A[j++];
			result += ll(mid - i + 1);
		}
	}
	FOR(i, left, right)
		A[i] = B[i - left];
}

void MergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 0, N - 1)
		cin >> A[i];
	MergeSort(0, N - 1);
	cout << result;

	return 0;
}