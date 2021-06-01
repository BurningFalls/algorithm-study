#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int arr[9] = { 100, 100, 200, 200, 300, 300, 400, 400, 500 };
	int input[9];
	int sum = 0;
	bool flag = true;
	FOR(i, 0, 8) {
		cin >> input[i];
		if (input[i] > arr[i])
			flag = false;
		sum += input[i];
	}
	if (!flag) {
		cout << "hacker";
	}
	else {
		if (sum < 100)
			cout << "none";
		else
			cout << "draw";
	}


	return 0;
}