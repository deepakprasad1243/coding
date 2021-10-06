
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


