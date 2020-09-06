K, L = map(int, input().split())
flag = True
for i in range(2, L):
    if (K % i == 0):
        flag = False
        ans = i
        break
if (flag):
    print("GOOD")
else:
    print("BAD", ans)
