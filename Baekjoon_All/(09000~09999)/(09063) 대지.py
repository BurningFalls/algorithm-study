N = int(input())
minx = 10001; miny = 10001
maxx = -10001; maxy = -10001
for i in range(N):
    x, y = map(int, input().split())
    minx = min(minx, x); miny = min(miny, y)
    maxx = max(maxx, x); maxy = max(maxy, y)
print((maxx - minx) * (maxy - miny))
