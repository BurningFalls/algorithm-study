N = int(input())
lis = input().split()
flag = True
for idx, val in enumerate(lis):
    if val == "mumble":
        continue
    if int(val) != idx + 1:
        flag = False
        break
print("makes sense" if flag else "something is fishy")