#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	string str;
	int d;
	int ans = 0;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		count = 0;
		str = to_string(i);
		int len = str.size();
		if (str.size() == 1) {
			ans++;
		}
		else {
			d = str[1] - str[0];
			for (int j = 1; j < len - 1; j++) {
				if (str[j + 1] - str[j] == d) {
					count++;
				}
				else {
					break;
				}
			}
			if (count == len - 2) {
				ans++;
			}
		}
	}
	cout << ans << endl;


	return 0;
}