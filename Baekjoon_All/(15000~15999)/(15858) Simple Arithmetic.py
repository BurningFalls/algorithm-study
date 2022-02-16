a, b, c = map(int, input().split())
print(f'{a * b // c}.', end='')
rest = a * b - (a * b // c) * c
for i in range(7):
    rest *= 10
    print(rest // c, end='')
    rest -= (rest // c) * c