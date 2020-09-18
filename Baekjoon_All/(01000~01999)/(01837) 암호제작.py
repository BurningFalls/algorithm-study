def check(num):
    for i in range(2, int(num**0.5) + 1):
        if (num % i == 0):
            return 0
    return 1

def check2(p, k):
    if (check(k) and P % k == 0):
        return 0
    return 1

P, K = map(int, input().split())
flag = 1
for i in range(2, min(P, K)):
    if (not check2(P, i)):
        flag = 0
        ans = i
        break
if (flag):
    print("GOOD")
else:
    print("BAD", ans)
