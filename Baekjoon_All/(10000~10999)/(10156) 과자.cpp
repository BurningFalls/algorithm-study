#include <iostream>
using namespace std;

int main() {
	int K, N, M;
	int temp;
	cin >> K >> N >> M;
	temp = K * N - M;
	if (temp < 0)
		temp = 0;
	cout << temp;

	return 0;
}