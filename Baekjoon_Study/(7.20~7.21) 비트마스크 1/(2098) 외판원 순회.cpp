#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 987654321

int N;
int W[16][16];
int DP[16][1 << 16];

int DFS(int node, int bit) {
	// 모든 도시를 다 방문한 경우 = 모든 비트가 1인 경우(0~15)
	if (bit == (1 << N) - 1) {
		// 돌아가는 것이 불가능한 경우 return INF
		if (W[node][0] == 0)
			return INF;
		// 외판원 순회가 가능하면 현재 위치에서 0(최종 위치)로 돌아가는 값 return
		else
			return W[node][0];
	}

	// 아직 덜 방문한 경우
	// DP값이 이미 있다면
	if (DP[node][bit] != -1)
		// 그대로 DP값 return
		return DP[node][bit];
	// DP값이 아직 없다면 INF로 초기화
	DP[node][bit] = INF;

	// 현재 node에서 갈 수 있는 곳 탐색
	for (int i = 0; i < N; i++) {
		// 가는 것이 불가능한 곳이면 pass
		if (W[node][i] == 0) continue;
		// bit를 검사하여 이미 방문한 곳이면 pass
		if ((bit & (1 << i))) continue;
		// 방문 가능한 곳인 경우
		// 현재 DP의 값 VS 지금까지 거쳐온 값 + 현재 위치에서 추가된 노드를 포함한 DFS값
		// 메모이제이션
		DP[node][bit] = min(DP[node][bit], W[node][i] + DFS(i, bit | (1 << i)));
	}
	// 메모이제이션 한 값을 return
	return DP[node][bit];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	// DP값이 존재하는지 안하는지를 구분하기 위해 -1로 초기화
	memset(DP, -1, sizeof(DP));
	// 0에서 시작해서 0으로 다시 돌아오기 위함
	// 0번을 방문했으니 0번 비트를 1로 바꿈 -> bit = 1
	cout << DFS(0, 1);

	return 0;
}