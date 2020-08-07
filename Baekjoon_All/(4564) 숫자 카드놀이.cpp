#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	int len;
	int T;
	int num = 1;
	while (true) {
		cin >> S;
		if (S == "0")
			break;
		while (true) {
			cout << S << " ";
			len = S.size();
			if (len == 1)
				break;
			num = 1;
			for (int i = 0; i < len; i++)
				num *= (S[i] - '0');
			S = to_string(num);
		}
		cout << "\n";
	}

	return 0;
}