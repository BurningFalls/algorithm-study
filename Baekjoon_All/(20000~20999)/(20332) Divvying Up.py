n = int(input())
lis = map(int, input().split())
print("yes" if sum(lis)%3==0 else "no")
