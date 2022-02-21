import sys, math
for line in sys.stdin:
    n, s = map(int, line.split())
    maxi = 0
    lis = map(int, input().split())
    for x in lis:
        maxi = max(maxi, x)
    maxi = math.ceil(maxi * s / 1000)
    print(maxi)