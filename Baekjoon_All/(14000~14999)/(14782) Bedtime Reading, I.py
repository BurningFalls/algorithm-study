n = int(input())
sqrtn = int(n ** 0.5)
sum = 0
for i in range(1, sqrtn + 1):
    if n % i != 0: continue
    sum += i
    if i * i == n: continue
    sum += n // i
print(sum)