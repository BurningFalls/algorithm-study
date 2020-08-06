#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int A, B;
long long int sum = 0;

void Find(long long int num) {
	if (num > B)
		return;
	if (num >= A)
		sum++;

	Find(num * 10 + 4);
	Find(num * 10 + 7);
}

int main() {
	cin >> A >> B;
	Find(4);
	Find(7);
	cout << sum;

	return 0;
}