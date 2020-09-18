#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int N;
	string S;
	int L;
	int maximum = 0;
	string max_S;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> S >> L;
			if (maximum <= L) {
				maximum = L;
				max_S = S;
			}
		}
		cout << max_S << "\n";
	}

	return 0;
}