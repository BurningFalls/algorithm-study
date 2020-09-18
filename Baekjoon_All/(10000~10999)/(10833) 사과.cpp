#include <iostream>
using namespace std;

int main() {
	int N;
	int student, apple;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> student >> apple;
		sum += apple % student;
	}
	cout << sum;

	return 0;
}