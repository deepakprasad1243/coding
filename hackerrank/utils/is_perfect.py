def is_perfect(n):
    _sum = 1
    i = 2
    while i * i <= n:
        if n % i == 0:
            print(i, n / i)
            _sum = _sum + i
            if n / i != i:
                _sum = _sum + n / i
        i += 1

    if _sum == n and n != 1:
        print("Perfect")
    else:
        print("Not Perfect")


if __name__ == '__main__':
    n = int(input("Enter your number to check whether its a Perfect number or not : "))
    is_perfect(n)

