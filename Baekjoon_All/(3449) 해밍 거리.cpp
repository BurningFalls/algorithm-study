#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string str1, str2;
	int ans;
	cin >> T;
	for (int a = 0; a < T; a++) {
		ans = 0;
		cin >> str1 >> str2;
		for (int i = 0; i < str1.size(); i++) {
			if ((str1[i] == '1' && str2[i] == '0') || (str1[i] == '0' && str2[i] == '1')) {
				ans++;
			}
		}
		cout << "Hamming distance is " << ans << ".\n";
	}

	return 0;
}