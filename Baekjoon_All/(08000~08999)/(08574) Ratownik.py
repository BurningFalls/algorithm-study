N, K, X, Y = map(int, input().split())
cnt = 0
for i in range(N):
    x, y = map(int, input().split())
    dist = (X - x) ** 2 + (Y - y) ** 2
    if dist > K ** 2:
        cnt += 1
print(cnt)
