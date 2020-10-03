import sys

def caesar_cipher(shift, text):
    ### Fill in this piece here - the result must be a Caesar Cipher
    ### that applies the shift to the input per Caesar Cipher algorithm
    result = []
    key = shift % 26
    alphabet = list("abcdefghijklmnopqrstuvwxyz")
    for letter in text:
        result.append(getNewLetter(letter, key, alphabet))
    return "".join(result)


def getNewLetter(letter, key, alphabet):
    if letter.isalpha():
        flag = letter.isupper()
        newLetterCode = alphabet.index(letter.lower()) + key
        temp = alphabet[newLetterCode] if newLetterCode <= 25 else alphabet[-1 + newLetterCode % 25]
        if flag:
            return temp.upper()
        return temp
    else:
        return letter


# def main():
#     for line in sys.stdin:
#         line = line.strip()
#         params = line.split(':')
#         shift = int(params[0])
#         text = str(params[1])
#         print(caesar_cipher(shift, text))

def main():
    for line in sys.stdin:
        line = line.strip()
        #params = line.split(':')
        #shift = int(params[0])
        #text = str(params[1])
        for shift in range(26):
            print(shift,end=':')
            print(caesar_cipher(shift, line))


if __name__ == "__main__":
    main()
