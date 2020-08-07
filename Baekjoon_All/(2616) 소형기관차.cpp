#include <iostream>
#include <algorithm>
using namespace std;

int arr[50001]; // °´Â÷ °¢ Ä­ÀÇ ¼Õ´Ô ¼ö
int dp[50001][4] = { 0, }; // dp (±â°üÂ÷ 1,2,3)

int main() {
	int N; // °´Â÷ÀÇ ¼ö
	int board_max; // ÃÖ´ë ²ø ¼ö ÀÖ´Â °´Â÷ ¼ö (<=N/3)
	int sub_sum;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> board_max;
	/*
	if (board_max == 3)
	dp[1][0~] = 0;
	dp[2][0~] = 0;
	dp[3][1] = arr[1] + arr[2] + arr[3];
	dp[4][1] = max(dp[3][1], dp[4-board_max][0] + (40+50+10));
	dp[5][1] = max(dp[4][1], dp[2][0] + (50+10+30));
	dp[6][1] = max(dp[5][1], dp[3][0] + (10+30+45));
	dp[6][2] = max(dp[5][2], dp[3][1] + (10+30+45));
	*/
	for (int i = board_max; i <= N; i++) {
		sub_sum = 0;
		for (int j = i; j > i - board_max; j--) {
			sub_sum += arr[j];
		}
		for (int j = 1; j <= 3; j++) {
			if (board_max * j > i) continue;
			dp[i][j] = max(dp[i - 1][j], dp[i - board_max][j - 1] + sub_sum);
		}
	}
	cout << dp[N][3];

	return 0;
}