N = int(input())
x = 5**N
l = len(str(x))
print("0.", end = "")
for i in range(0, N - l):
    print("0", end = "")
print(x)
    
