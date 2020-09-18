#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b, c;
	int temp;
	cin >> a >> b >> c;
	temp = a + 2 * b + 3 * c;
	if (temp >= 10)
		cout << "happy";
	else
		cout << "sad";

	return 0;
}