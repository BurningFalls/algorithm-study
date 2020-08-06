#include <iostream>
using namespace std;

bool arr[400][398];
int cur_x, cur_y;

void Right(int n) {
	for (int i = 0; i < n; i++) {
		arr[cur_y][cur_x + i] = 1;
	}
	cur_x += (n - 1);
}

void Left(int n) {
	for (int i = 0; i < n; i++) {
		arr[cur_y][cur_x - i] = 1;
	}
	cur_x -= (n - 1);
}

void Up(int n) {
	for (int i = 0; i < n; i++) {
		arr[cur_y - i][cur_x] = 1;
	}
	cur_y -= (n - 1);
}

void Down(int n) {
	for (int i = 0; i < n; i++) {
		arr[cur_y + i][cur_x] = 1;
	}
	cur_y += (n - 1);
}

void func(int n) {
	if (n == 1) {
		Down(3);
		return;
	}
	Left(4 * n - 1 - 2);
	Down(4 * n - 1);
	Right(4 * n - 3);
	Up(4 * n - 3);
	Left(3);
	func(n - 1);
}

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << '*';
	}
	else {
		cur_y = 0;
		cur_x = 4 * N - 4;

		func(N);

		for (int i = 0; i < 4 * N - 1; i++) {
			if (i == 1) {
				for (int j = 0; j < 2; j++) {
					if (arr[i][j])
						cout << '*';
					else
						cout << ' ';
				}
			}
			else {
				for (int j = 0; j < 4 * N - 3; j++) {
					if (arr[i][j])
						cout << '*';
					else
						cout << ' ';
				}
			}
			cout << endl;
		}
	}

	return 0;
}