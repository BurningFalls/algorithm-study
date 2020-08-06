#include <iostream>
using namespace std;

int main() {
	int arr[4] = { 0,1,2,3 };
	int M;
	int X, Y;
	int temp;
	int loc1, loc2;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		for (int j = 1; j <= 3; j++) {
			if (arr[j] == X)
				loc1 = j;
			if (arr[j] == Y)
				loc2 = j;
		}
		temp = arr[loc1];
		arr[loc1] = arr[loc2];
		arr[loc2] = temp;
	}
	cout << arr[1];

	return 0;
}