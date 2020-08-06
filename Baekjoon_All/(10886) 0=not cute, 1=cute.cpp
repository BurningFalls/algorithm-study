#include <iostream>
using namespace std;

int main() {
	int N;
	int z_count = 0;
	int o_count = 0;
	int num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 1) {
			o_count++;
		}
		else if (num == 0) {
			z_count++;
		}
	}
	if (o_count > z_count) {
		cout << "Junhee is cute!";
	}
	else if (o_count < z_count) {
		cout << "Junhee is not cute!";
	}


	return 0;
}