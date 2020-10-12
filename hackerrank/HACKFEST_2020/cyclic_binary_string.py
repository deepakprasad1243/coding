"""
problem:
https://www.hackerrank.com/contests/hackerrank-hackfest-2020/challenges/cyclic-binary-string/problem
"""
# Solution

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maximumPower' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def maximumPower(s):
    # Write your code here
    z = re.findall(r"0+", s)
    if(len(z) == 0): return 0
    if(len(max(z, key=len)) == len(s)): return -1
    if s[0] == '0' and s[-1] == '0':
        if len(z[0]) + len(z[-1]) > len(max(z, key=len)):
            return len(z[0]) + len(z[-1])
        else:
            return len(max(z, key=len))
    else:
        return len(max(z, key=len))
        
# boilerplate
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = maximumPower(s)

    fptr.write(str(result) + '\n')

    fptr.close()
