#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[10001];
	int max_score = 0;
	int maximum;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (max_score < arr[i]) {
			max_score = arr[i];
			maximum = i;
		}
	}
	if (maximum != 1)
		cout << "N";
	else
		cout << "S";

	return 0;
}