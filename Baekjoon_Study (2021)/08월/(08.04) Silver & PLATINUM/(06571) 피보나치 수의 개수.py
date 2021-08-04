dp = [0 for i in range(1001)]
dp[1] = 1
dp[2] = 2
for i in range(3, 1000):
    dp[i] = dp[i - 1] + dp[i - 2]
while True:
    a, b = map(int, input().split())
    if (a == 0) and (b == 0):
        break
    cnt = 0
    for i in range(1, 1000):
        if (a <= dp[i]) and (dp[i] <= b):
            cnt += 1
    print(cnt)
