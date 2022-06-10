#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF int(2e9)
#define LINF ll(1e18)

int main() {
	FASTIO;
	int T;
	cin >> T;
	FOR(i, 1, T) {
		double tall, weight;
		cin >> tall >> weight;
		double bmi = weight / (tall * 0.01 * tall * 0.01);
		if (tall < 140.1) {
			cout << 6;
		}
		else if (140.1 <= tall && tall < 146) {
			cout << 5;
		}
		else if (146 <= tall && tall < 159) {
			cout << 4;
		}
		else if (159 <= tall && tall < 161) {
			if (16.0 <= bmi && bmi < 35.0) {
				cout << 3;
			}
			else {
				cout << 4;
			}
		}
		else if (161 <= tall && tall < 204) {
			if (20.0 <= bmi && bmi < 25.0) {
				cout << 1;
			}
			else if ((18.5 <= bmi && bmi < 20.0) || (25.0 <= bmi && bmi < 30.0)) {
				cout << 2;
			}
			else if ((16.0 <= bmi && bmi < 18.5) || (30.0 <= bmi && bmi < 35.0)) {
				cout << 3;
			}
			else {
				cout << 4;
			}
		}
		else if (204 <= tall) {
			cout << 4;
		}
		cout << "\n";
	}

	return 0;
}