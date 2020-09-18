#include <iostream>
#include <string>
using namespace std;

int main() {
	char X;
	string str;
	int len;
	int cnt;
	while (true) {
		cin >> X;
		if (X == '#')
			break;
		cin.ignore();
		getline(cin, str);
		cnt = 0;
		len = str.size();
		for (int i = 0; i < len; i++) {
			if (int(str[i]) == int(X) - 32 || int(str[i]) == int(X))
				cnt++;
		}
		cout << X << " " << cnt << "\n";
	}

	return 0;
}