# util to find whether a given number is perfect or not
def is_perfect(n):
    _sum = 1
    i = 2
    while i * i <= n:
        if n % i == 0:
            _sum = _sum + i
            if n / i != i:
                _sum = _sum + n / i
        i += 1

    return _sum == n and n != 1


if __name__ == '__main__':
    n = int(input("Enter the number to check whether its a Perfect number or not : "))
    print("Perfect" if is_perfect(n) else "Not Perfect")

