#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int arr[4];
	int n_arr[4];
	int cnt;
	while (true) {
		cnt = 0;
		for (int i = 0; i < 4; i++)
			cin >> arr[i];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0)
			break;
		while (true) {
			if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
				break;
			n_arr[0] = abs(arr[0] - arr[1]);
			n_arr[1] = abs(arr[1] - arr[2]);
			n_arr[2] = abs(arr[2] - arr[3]);
			n_arr[3] = abs(arr[3] - arr[0]);
			for (int i = 0; i < 4; i++)
				arr[i] = n_arr[i];
			cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}