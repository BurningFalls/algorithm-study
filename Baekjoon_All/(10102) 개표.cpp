#include <iostream>
#include <string>
using namespace std;

int main() {
	int V;
	string str;
	int A_cnt = 0;
	int B_cnt = 0;
	cin >> V;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'A')
			A_cnt++;
		else if (str[i] == 'B')
			B_cnt++;
	}
	if (A_cnt > B_cnt)
		cout << "A";
	else if (A_cnt < B_cnt)
		cout << "B";
	else if (A_cnt == B_cnt)
		cout << "Tie";

	return 0;
}