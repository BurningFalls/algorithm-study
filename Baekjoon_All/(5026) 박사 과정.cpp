#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	int len;
	int plus_pos;
	int num1, num2;
	cin >> N;
	for (int a = 0; a < N; a++) {
		plus_pos = -1;
		cin >> str;
		len = str.size();
		for (int i = 0; i < len; i++) {
			if (str[i] == '+')
				plus_pos = i;
		}
		if (plus_pos == -1)
			cout << "skipped\n";
		else {
			num1 = stoi(str.substr(0, plus_pos));
			num2 = stoi(str.substr(plus_pos + 1, len - plus_pos - 1));
			cout << num1 + num2 << "\n";
		}
	}


	return 0;
}