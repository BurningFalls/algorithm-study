#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define MAX 1000000 + 1

int N;
int arr1[MAX];
int arr2[MAX];
int tmp1[MAX];
int tmp2[MAX];

bool Check1() {
	FOR(i, 1, N) {
		if (arr1[i] != tmp1[i])
			return false;
	}
	return true;
}

bool Check2() {
	FOR(i, 1, N) {
		if (arr1[i] != tmp2[i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	string s;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr1[i];
	int pos = 0;
	FOR(i, 1, N) {
		cin >> arr2[i];
		if (arr2[i] == arr1[1])
			pos = i;
	}
	FOR(i, pos, N)
		tmp1[i - pos + 1] = arr2[i];
	FOR(i, 1, pos - 1)
		tmp1[N - pos + 1 + i] = arr2[i];
	ROF(i, pos, 1)
		tmp2[pos + 1 - i] = arr2[i];
	ROF(i, N, pos + 1)
		tmp2[N + pos + 1 - i] = arr2[i];

	if (Check1() || Check2())
		cout << "good puzzle";
	else
		cout << "bad puzzle";


	return 0;
}