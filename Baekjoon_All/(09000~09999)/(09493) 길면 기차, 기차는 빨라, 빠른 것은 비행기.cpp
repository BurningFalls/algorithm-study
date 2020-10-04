#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	double M, A, B;
	while (true) {
		cin >> M >> A >> B;
		if (M == 0 && A == 0 && B == 0)
			break;
		int temp = round((M / A - M / B) * 3600);
		double hour, minute, second;
		hour = temp / 3600;
		temp -= hour * 3600;
		minute = temp / 60;
		temp -= minute * 60;
		second = temp;
		cout << hour;
		cout << ":";
		if (minute < 10)
			cout << "0";
		cout << minute;
		cout << ":";
		if (second < 10)
			cout << "0";
		cout << second;
		cout << "\n";
	}

	return 0;
}