N = int(input())
for i in range(N):
    b, p = map(float, input().split())
    print(f'{60 * (b - 1) / p :.4f} {60 * b / p :.4f} {60 * (b + 1) / p :.4f}')