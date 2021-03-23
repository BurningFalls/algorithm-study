#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int arr[51];
	FOR(i, 1, 50)
		cin >> arr[i];
	int score;
	cin >> score;
	int pos = 0;
	FOR(i, 1, 50) {
		if (arr[i] == score) {
			pos = i;
			break;
		}
	}
	if (1 <= pos && pos <= 5)
		cout << "A+";
	else if (6 <= pos && pos <= 15)
		cout << "A0";
	else if (16 <= pos && pos <= 30)
		cout << "B+";
	else if (31 <= pos && pos <= 35)
		cout << "B0";
	else if (36 <= pos && pos <= 45)
		cout << "C+";
	else if (46 <= pos && pos <= 48)
		cout << "C0";
	else if (49 <= pos && pos <= 50)
		cout << "F";


	return 0;
}