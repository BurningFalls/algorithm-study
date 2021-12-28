n = int(input())
check = [0 for i in range(n + 1)]
num_list = list(map(int, input().split()))
for x in num_list:
    check[x] = 1
for i in range(1, n + 1):
    if check[i] == 0:
        print(i)
        break