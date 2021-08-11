#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int idx = 1;
	while (true) {
		int X;
		cin >> X;
		if (X == 0)
			break;
		X = round((double)X / 2);
		X += round((double)X / 2);
		if (X % 1860000 == 0)
			X = X / 1860000;
		else
			X = X / 1860000 + 1;
		cout << "File #" << idx << "\n";
		idx++;
		cout << "John needs ";
		cout << X;
		cout << " floppies.\n\n";
	}


	return 0;
}