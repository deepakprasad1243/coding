"""
Q: Given two string s ,t
    if s is divisible by t, return the length of smallest divisor of t otherwise return -1

divisible is defines as:
    s is said to be divisible bt t, if t can be concatinated with self any no of times to form s

divisor is defined as :
    a string str is said to be a divisor of another string t, if t is divisible by str

"""




import re
def solve(s, t):
    count1 = len(re.findall(t, s))
    if count1 * len(t) == len(s):
        for i in range(len(t)):
            test = t[:i + 1]
            count2 = len(re.findall(test, t))
            if count2 * len(test) == len(t):
                return len(test)
    else:
        return -1


# Driver code
if __name__ == "__main__":
    txt = "abcabcabcabc"
    pat = "abcabc"
    ans = solve(txt, pat)

    print(ans)


