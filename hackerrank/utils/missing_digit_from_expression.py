def MissingDigit(exp):
    # Split the expression to
    # extract operands, operator
    # and resultant
    exp = list(exp.split())
    print(exp)

    first_operand = exp[0]
    operator = exp[1]
    second_operand = exp[2]
    resultant = exp[-1]

    # If x is present in resultant
    if 'x' in resultant:
        x = resultant
        first_operand = int(first_operand)
        second_operand = int(second_operand)

        if operator == '+':
            res = first_operand + second_operand
        elif operator == '-':
            res = first_operand - second_operand
        elif operator == '*':
            res = first_operand * second_operand
        else:
            res = first_operand // second_operand

    # If x in present in operands
    else:

        resultant = int(resultant)

        # If x in the first operand
        if 'x' in first_operand:

            x = first_operand
            second_operand = int(second_operand)

            if operator == '+':
                res = resultant - second_operand
            elif operator == '-':
                res = resultant + second_operand
            elif operator == '*':
                res = resultant // second_operand
            else:
                res = resultant * second_operand

        # If x is in the second operand
        else:

            x = second_operand
            first_operand = int(first_operand)

            if operator == '+':
                res = resultant - first_operand
            elif operator == '-':
                res = first_operand - resultant
            elif operator == '*':
                res = resultant // first_operand
            else:
                res = first_operand // resultant

    res = str(res)
    k = 0
    for i in x:
        if i == 'x':
            result = res[k]
            break
        else:
            k = k + 1

    return result


# Driver Code
if __name__ == '__main__':
    # input expression
    exp = "3x + 12 = 46"

    print(MissingDigit(exp))
