T = int(input())
for i in range(0, T):
    s = input()
    n = int(input())
    sum = 0
    for j in range(0, n):
        num = int(input())
        sum += num
    if (sum % n == 0):
        print("YES")
    else:
        print("NO")
