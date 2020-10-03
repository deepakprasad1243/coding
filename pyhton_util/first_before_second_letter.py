# First before Second letter
"""
You are given three inputs: a string, one letter, and a second lettter.
check if every instance of the first letter occurs before every instance of the second letter
"""
string = input()
first = input()
second = input()

dict = {}
for i in range(len(string)):
    if string[i] in dict:
        dict[string[i]].append(i)
    else:
        dict[string[i]] = []
        dict[string[i]].append(i)

occSecond = -1
if second in dict:
    occSecond = dict[second][0]

occFirst = -1
if first in dict:
    length = len(dict[first])
    occFirst = dict[first][length-1]

print(occFirst < occSecond)

