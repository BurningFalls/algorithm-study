#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int L;
	string s1, s2;
	int x = 1;
	int cnt;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> L;
		cin >> s1;
		cin >> s2;
		cnt = 0;
		cout << "Case " << x << ": ";
		for (int i = 0; i < L; i++) {
			if (s1[i] != s2[i])
				cnt++;
		}
		cout << cnt << "\n";
		x++;
	}

	return 0;
}