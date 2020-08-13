#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	int len;
	int sum;
	while (true) {
		cin >> N;
		if (N == "0") {
			break;
		}
		while (true) {
			sum = 0;
			len = N.size();
			if (len == 1) {
				break;
			}
			for (int i = 0; i < len; i++) {
				sum += (N[i] - '0');
			}
			N = to_string(sum);
		}
		cout << N << endl;
	}

	return 0;
}