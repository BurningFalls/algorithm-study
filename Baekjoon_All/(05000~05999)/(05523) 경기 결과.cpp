#include <iostream>
using namespace std;

int arr[1000001][2];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	int Awin = 0;
	int Bwin = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1];
		if (arr[i][0] > arr[i][1])
			Awin++;
		else if (arr[i][0] < arr[i][1])
			Bwin++;
	}
	cout << Awin << " " << Bwin;


	return 0;
}