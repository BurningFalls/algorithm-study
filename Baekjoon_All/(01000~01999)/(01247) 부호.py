import sys

for t in range(0, 3):
    n = int(input())
    sum = 0
    for i in range(0, n):
        x = int(sys.stdin.readline())
        sum += x
    if sum == 0:
        print("0")
    elif sum > 0:
        print("+")
    elif sum < 0:
        print("-")
    
