#include <iostream>
using namespace std;

int main() {
	int N;
	int num = 1;
	int time = 0;
	cin >> N;
	while (N != 0) {
		if (N - num < 0)
			num = 1;
		N -= num;
		num++;
		time++;
	}
	cout << time;

	return 0;
}