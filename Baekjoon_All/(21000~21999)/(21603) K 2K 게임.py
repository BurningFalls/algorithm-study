N, K = map(int, input().split())
a = K % 10
b = (K * 2) % 10
lis = []
for i in range(1, N + 1):
    if i % 10 != a and i % 10 != b:
        lis.append(i)
print(len(lis))
for x in lis:
    print(x, end=' ')