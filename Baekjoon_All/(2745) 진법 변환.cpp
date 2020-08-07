#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string N;
	int len;
	int B;
	int sum = 0;
	cin >> N >> B;
	len = N.size();
	for (int i = 0; i < len; i++) {
		if (N[i] >= 'A' && N[i] <= 'Z')
			sum += (N[i] - 'A' + 10) * int(pow(B, len - i - 1));
		else
			sum += (N[i] - '0') * int(pow(B, len - i - 1));
	}
	cout << sum;

	return 0;
}