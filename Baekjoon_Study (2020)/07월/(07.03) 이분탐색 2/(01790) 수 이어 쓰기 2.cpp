#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int N, K;
	int minimum = 0, maximum = 0;
	int arr[10];
	int letters = 1;
	int LEFT;
	int temp;
	int Check = 0;
	int len;
	pair<int, int> left, right, mid;
	int sub_left, sub_right;
	/*
	각 자리수별로 몇개의 숫자가 있는지
	arr[1] = 9, arr[2] = 90*2, arr[3] = 900*3...
	*/
	for (int i = 1; i <= 8; i++) {
		arr[i] = 9 * int(pow(10, i - 1)) * i;
	}
	// N, K 입력받고
	cin >> N >> K;
	// 수의 길이가 k보다 작은지 확인
	len = to_string(N).size();
	for (int i = 1; i < len; i++) {
		Check += arr[i];
	}
	Check += (N - int(pow(10, len - 1)) + 1) * len;
	if (Check < K)
		cout << -1;
	// else
	else {
		// K번째 자리 숫자의 자릿수를 알아내기
		for (int i = 1; i <= 9; i++) {
			/*
			i=1 -> min=1, max=9
			i=2 -> min=10, max=189
			i=3 -> min=190, max=2889
			*/
			if (i == 1)
				minimum = 1;
			else
				minimum += arr[i - 1];
			if (i == 9)
				maximum = minimum + 8;
			else
				maximum = minimum + arr[i] - 1;
			/*
			K가 min과 max 사이일 경우
			letters에 자릿수를 저장
			left와 right -> first:지금 숫자, second:지금까지 숫자의 개수
			(if letters가 2라면)
			left = (10, 10), right = (99, 189)
			*/
			if (minimum <= K && K <= maximum) {
				letters = i;
				left = make_pair(int(pow(10, i - 1)), minimum);
				right = make_pair(int(pow(10, i)) - 1, maximum);
				break;
			}
		}
		LEFT = left.second;
		while (true) {
			// mid 평균 계산
			mid = make_pair((left.first + right.first) / 2, (left.second + right.second) / 2);
			// temp 계산을 통해 한 숫자에서의 위치 파악 (1032에서 0의 위치는 1)
			temp = (mid.second - LEFT) % letters;
			// 그걸 바탕으로 1032에서 1의 위치와 2의 위치를 계산
			sub_left = mid.second - temp;
			sub_right = mid.second + (letters - 1) - temp;
			// K값이 그 사이에 있다면 해당 mid.first에 저장된 숫자가 답
			if (sub_left <= K && K <= sub_right) {
				// 그 숫자에서 위치를 다시 계산해서 하나의 숫자를 찾아냄
				cout << to_string(mid.first)[K - sub_left];
				break;
			}
			// K가 sub_left보다 작을시 right 변경
			if (sub_left > K) {
				right = make_pair(mid.first - 1, sub_left - 1);
			}
			// K가 sub_right보다 클시 left 변경
			else if (K > sub_right) {
				left = make_pair(mid.first + 1, sub_right + 1);
			}
		}
	}

	return 0;
}