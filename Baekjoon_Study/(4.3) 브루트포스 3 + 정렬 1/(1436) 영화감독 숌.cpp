#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int num = 666;
	string s_num;
	int cnt = 0;
	cin >> N;
	while (true) {
		s_num = to_string(num);
		if (s_num.find("666") != string::npos) {
			cnt++;
		}
		if (cnt == N) {
			cout << s_num;
			break;
		}
		num++;
	}

	return 0;
}