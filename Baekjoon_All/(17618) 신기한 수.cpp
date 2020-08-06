#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int cnt = 0;
	string str;
	int sum;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			sum += (str[j] - '0');
		}
		if (i % sum == 0)
			cnt++;
	}
	cout << cnt;

	return 0;
}