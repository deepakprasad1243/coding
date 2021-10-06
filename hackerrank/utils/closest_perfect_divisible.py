n = int(input())
m = int(input())

remainder = n % m

if remainder < m / 2:
    print(n - remainder)
else:
    print(n + m - remainder)

