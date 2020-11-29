#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
bool arr[101];

void Func1(int x) {
	for (int i = 1; x * i <= N; i++) {
		arr[x * i] = !arr[x * i];
	}
}

void Func2(int x) {
	int left = x, right = x;
	while (left >= 1 && right <= N) {
		if ((arr[left] ^ arr[right]) == 0) {
			arr[left] = !arr[left];
			if (left != right)
				arr[right] = !arr[right];
			left--;
			right++;
		}
		else
			break;
	}
}

int main() {
	FASTIO;
	int M;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	cin >> M;
	FOR(i, 1, M) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			Func1(b);
		}
		else if (a == 2) {
			Func2(b);
		}
	}
	FOR(i, 1, N) {
		cout << arr[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}

	return 0;
}