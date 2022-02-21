N = int(input())
cnt = 0
prev = '.'
for i in range(N):
    ch = input()
    if prev != ch:
        cnt += 1
    prev = ch
print(cnt + 1)