# nth root

def findNthRoot(x, n):
    x = float(x)
    n = int(n)
    if (x >= 0 and x <= 1):
        low = x
        high = 1
    else:
        low = 1
        high = x
    epsilon = 0.0000000000001
    guess = (low + high) / 2
    while abs(guess ** n - x) >= epsilon:
        if guess ** n > x:
            high = guess
        else:
            low = guess
        guess = (low + high) / 2
    return guess


# Driver code
n = input()
minimum = input()
maximum = input()
low = findNthRoot(minimum, n)
print(low)
high = findNthRoot(maximum, n)
print(high)
if int(low) == low:
    print(int(high)-int(low) + 1)
else:
    print(int(high) - int(low))

