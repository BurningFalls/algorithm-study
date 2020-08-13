#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int pack_min = -1;
	int one_min = -1;
	int pack, one;
	int price;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> pack >> one;
		if (pack_min == -1)
			pack_min = pack;
		else
			pack_min = min(pack_min, pack);
		if (one_min == -1)
			one_min = one;
		else
			one_min = min(one_min, one);
	}

	if (pack_min < one_min * 6) {
		price = pack_min * (N / 6);
		if (pack_min >= one_min * (N % 6)) {
			price += one_min * (N % 6);
		}
		else {
			price += pack_min;
		}
	}
	else {
		price = one_min * N;
	}

	cout << price;

	return 0;
}