#include <iostream>
using namespace std;

int main() {
	int T;
	int M;
	char which;
	int arr1[501];
	char arr2[502];
	char temp;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cin >> M >> which;
		if (which == 'C') {
			for (int i = 0; i < M; i++) {
				cin >> arr2[i];
			}
			for (int i = 0; i < M; i++) {
				cout << int(arr2[i]) - 64 << " ";
			}
			cout << endl;
		}
		else if (which == 'N') {
			for (int i = 0; i < M; i++) {
				cin >> arr1[i];
			}
			for (int i = 0; i < M; i++) {
				temp = arr1[i] + 64;
				cout << temp << " ";
			}
			cout << endl;
		}
	}

	return 0;
}