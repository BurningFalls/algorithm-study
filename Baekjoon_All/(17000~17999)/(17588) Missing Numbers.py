n = int(input())
lis = []
for i in range(n):
    x = int(input())
    lis.append(x)
flag = False
for i in range(1, lis[-1] + 1):
    if i not in lis:
        flag = True
        print(i)
if not flag:
    print("good job")
