#include <iostream>
#include <string>
using namespace std;

string str[5];

bool Check(int node) {
	int len = str[node].size();
	for (int i = 0; i < len - 2; i++) {
		if (str[node][i] == 'F' && str[node][i + 1] == 'B' && str[node][i + 2] == 'I')
			return true;
	}
	return false;
}

int main() {
	bool flag = false;
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < 5; i++) {
		if (Check(i)) {
			cout << i + 1 << " ";
			flag = true;
		}
	}
	if (!flag)
		cout << "HE GOT AWAY!";

	return 0;
}