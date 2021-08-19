T = int(input())
dp = [0 for i in range(100001)]
dp[0] = 1
for i in range(1, 100001):
    dp[i] = (dp[i - 1] * i) % 1000000007
for i in range(0, T):
    N = int(input())
    print((dp[N] - 1) % 1000000007)
