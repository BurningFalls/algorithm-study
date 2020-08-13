#include <iostream>
using namespace std;

int main() {
	int num;
	int cnt = 1;
	int result;
	while (true) {
		cin >> num;
		result = num;
		if (num == 0)
			break;
		cout << cnt << ". ";
		result = result * 3;
		if (result % 2 == 1) {
			cout << "odd ";
			result = (result + 1) / 2;
		}
		else {
			cout << "even ";
			result = result / 2;
		}
		result = result * 3;
		result = result / 9;
		cout << result << "\n";
		cnt++;
	}

	return 0;
}