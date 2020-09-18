#include <iostream>
using namespace std;

int N;
int nums[2001] = { 0, };
//-1000~1000 -> num[num + 1000]

int main() {
	int num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums[num + 1000] = 1;
	}
	for (int i = 0; i <= 2000; i++) {
		if (nums[i] == 1)
			cout << i - 1000 << " ";
	}

	return 0;
}