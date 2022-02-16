K = int(input())
N = int(input())
for i in range(1, N):
    print(i)
print(K - (N - 1) * N // 2)