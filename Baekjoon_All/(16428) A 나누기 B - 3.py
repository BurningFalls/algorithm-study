a, b = map(int, input().split())
if (a > 0 and b < 0):
    b = -b
    print(a//b*(-1))
    print(a%b)
elif(a < 0 and b < 0):
    b = -b
    print(a//b*(-1))
    print(a%b)
else:
    print(a//b)
    print(a%b)
