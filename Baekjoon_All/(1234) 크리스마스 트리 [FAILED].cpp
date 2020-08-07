#include <iostream>
using namespace std;

struct COLOR {
	int red_number;
	int green_number;
	int blue_number;
};

COLOR multiple_by_1[3] = { {1,0,0},{0,1,0},{0,0,1} };
COLOR multiple_by_2[3] = { {1,1,0}, {1,0,1}, {0,1,1} };
COLOR multiple_by_3[3] = { {1,1,1} };
long long number_of_trees = 0;

int factorial(int n) {
	int result = 1;
	if (n == 0)
		return result;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}

long long calculate(int r_num, int g_num, int b_num) {
	return (long long)(factorial(r_num + g_num + b_num) / (factorial(r_num) * factorial(g_num) * factorial(b_num)));
}

bool chtree(int n, int red, int green, int blue, int floor, long long trees) {
	if (floor > n) {
		number_of_trees += trees;
		return 1;
	}
	if (floor % 1 == 0) {
		for (int i = 0; i < 3; i++) {
			if (multiple_by_1[i].red_number == 1 && red >= floor) {
				chtree(n, red - floor, green, blue, floor + 1, trees);
			}
			if (multiple_by_1[i].green_number == 1 && green >= floor) {
				chtree(n, red, green - floor, blue, floor + 1, trees);
			}
			if (multiple_by_1[i].blue_number == 1 && blue >= floor) {
				chtree(n, red, green, blue - floor, floor + 1, trees);
			}
		}
	}
	if (floor % 2 == 0) {
		for (int i = 0; i < 3; i++) {
			if (multiple_by_2[i].blue_number == 0 && red >= floor / 2 && green >= floor / 2) {
				chtree(n, red - floor / 2, green - floor / 2, blue, floor + 1, trees * calculate(floor / 2, floor / 2, 0));
			}
			if (multiple_by_2[i].green_number == 0 && red >= floor / 2 && blue >= floor / 2) {
				chtree(n, red - floor / 2, green, blue - floor / 2, floor + 1, trees * calculate(floor / 2, floor / 2, 0));
			}
			if (multiple_by_2[i].red_number == 0 && green >= floor / 2 && blue >= floor / 2) {
				chtree(n, red, green - floor / 2, blue - floor / 2, floor + 1, trees * calculate(floor / 2, floor / 2, 0));
			}
		}
	}
	if (floor % 3 == 0) {
		if (red >= floor / 3 && green >= floor / 3 && blue >= floor / 3) {
			chtree(n, red - floor / 3, green - floor / 3, blue - floor / 3, floor + 1, trees * calculate(floor / 3, floor / 3, floor / 3));
		}
	}
	return 0;
}


int main() {
	int Floor = 1;
	long long Trees = 1;
	int N, Red, Green, Blue;
	cin >> N >> Red >> Green >> Blue;
	if (Red == 0 && Green == 0 && Blue == 0)
		cout << 0 << endl;
	chtree(N, Red, Green, Blue, Floor, Trees);
	cout << number_of_trees << endl;
	return 0;
}