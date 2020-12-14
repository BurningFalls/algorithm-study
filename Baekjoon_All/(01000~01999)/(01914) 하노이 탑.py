def func(cnt, start, end):
    if (cnt == 0):
        return
    func(cnt - 1, start, 6 - start - end)
    print(start, end)
    func(cnt - 1, 6 - start - end, end)

N = int(input())
print(pow(2, N) - 1)
if (N <= 20):
    func(N, 1, 3)
