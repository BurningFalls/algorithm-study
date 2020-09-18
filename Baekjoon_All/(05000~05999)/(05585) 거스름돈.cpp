#include <iostream>
using namespace std;

int change(int price) {
	int money = 1000 - price;
	int number = 0;
	int arr[6] = { 500, 100, 50, 10, 5, 1 };
	for (int i = 0; i < 6; i++) {
		while (true) {
			if (money - arr[i] >= 0) {
				number++;
				money -= arr[i];
			}
			else
				break;
		}
		if (money == 0)
			break;
	}
	return number;
}

int main() {
	int p;
	cin >> p;
	cout << change(p) << endl;
	return 0;
}