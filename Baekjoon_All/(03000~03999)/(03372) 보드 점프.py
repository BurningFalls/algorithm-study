n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for col in range(n)] for row in range(n)]
dp[0][0] = 1
for i in range(0, n):
    for j in range(0, n):
        if dp[i][j] == 0:
            continue
        if (i == n - 1) and (j == n - 1):
            continue
        num = arr[i][j]
        if j + num < n:
            dp[i][j + num] += dp[i][j]
        if i + num < n:
            dp[i + num][j] += dp[i][j]
print(dp[n - 1][n - 1])
