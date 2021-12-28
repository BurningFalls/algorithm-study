n = int(input())
for i in range(n):
    num = int(input())
    print(num)
    sn = num
    while len(str(num)) > 2:
        num = num // 10 - num % 10
        print(num)
    print(f"The number {sn} is {'not ' if num % 11 != 0 else ''}divisible by 11.\n")