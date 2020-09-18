#include <iostream>
using namespace std;

int main() {
	int num; // 원래 숫자
	int N;
	int count = 0;
	cin >> num;
	N = num;
	while (num != N || count == 0) {
		N = (int(N / 10) + N % 10) % 10 + N % 10 * 10;
		count++;
	}
	cout << count << endl;
	return 0;
}