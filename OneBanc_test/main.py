# formatting transaction csv
# run the script using python 2.7 interpreter
import csv
from re import search

filenames = "ICICI-Input-Case2.csv", "HDFC-Input-Case1.csv", "Axis-Input-Case3.csv"
fieldnames = ['Date', 'Transaction Description', 'Debit', 'Credit', 'Currency', 'CardName', 'Transaction', 'Location']
transactionType = 'Domestic'
CardName = ''
differentCreditDebit = False
credit = 0
debit = 0
amount = 0
currency = 'INR'
location = ''
description = 1
date = 0

with open("StandardFormatMerged-output.csv", "w") as fp:
    writer = csv.writer(fp)
    writer.writerow(fieldnames)
    for filename in filenames:  # iterating over csv's
        print("Reading csv : {}".format(filename))
        print("-" * 40)
        with open(filename, "r") as csvfile:  # opening csv file
            reader = csv.reader(csvfile, delimiter=',')  # reading csv
            for row in reader:  # iterating over rows of csv
                # Check if it is a data column with date in format (xx-xx-xxxx) as 1st entry of column would contain transaction date
                if search('-', row[date]):
                    if transactionType == 'Domestic':
                        location = row[description].strip().split(' ')[-1].strip().lower()
                    elif transactionType == 'International':
                        des = row[description].strip().split(' ')
                        currency = des[-1]
                        transactionDescription = ' '.join(des[:-1])
                        location = ' '.join(des[:-1]).strip().split(' ')[-1].strip().lower()
                    creditAmount = 0
                    debitAmount = 0
                    if differentCreditDebit:
                        creditAmount = row[credit] if row[credit] != '' else 0
                        debitAmount = row[debit] if row[debit] != '' else 0
                    data = [row[date], row[description] if transactionType == 'Domestic' else transactionDescription,
                            debitAmount if differentCreditDebit else 0 if search('cr', row[amount]) else row[amount],
                            creditAmount if differentCreditDebit else row[amount].split(' ')[0] if search('cr', row[
                                amount]) else 0,
                            currency, CardName, transactionType, location]
                    writer.writerow(data)
                # if 1st entry column is not a transaction date then if maybe a blank row or header values or card holder name
                elif any("Date" in s for s in row) or any("date" in s for s in row):  # for headers information Extraction
                    for i in range(len(row)):
                        if search('Date', row[i]) or search('date', row[i]):
                            date = i
                        if search('Transaction', row[i]):
                            description = i
                        if search('Credit', row[i]) or search('Credit', row[i]):  # checking if credit and debit amount are in seperate column
                            differentCreditDebit = True
                            credit = i
                            # print(row, i)
                        elif search('Debit', row[i]) or search('debit', row[i]):
                            differentCreditDebit = True
                            debit = i
                            # print(row, i)
                        elif search('Amount', row[i]) or search('amount', row[i]):
                            differentCreditDebit = False
                            amount = i
                            credit = 0
                            debit = 0
                            break
                # if 1st entry of the column is blank then cheking for 2nd entry for transaction type and card holder name
                else:
                    blankRow = True
                    for i in range(len(row)):  #check if blank row
                        if row[i] != '':
                            blankRow = False
                            break
                    if blankRow:  # skipping blank lines
                        continue
                    elif any("Transactions" in s for s in row) or any("transactions" in s for s in row):  # setting transaction type
                        if any("Domestic" in s for s in row) or any("domestic" in s for s in row):
                            transactionType = 'Domestic'
                            # print('Domestic')
                        elif any("International" in s for s in row) or any("international" in s for s in row):
                            transactionType = 'International'
                            # print('International')
                    else:
                        for i in range(len(row)):
                            if row[i] != '':
                                CardName = row[i]  # Setting card holder name


print("#" * 80)
print("CSV's Merged and formatted in the output csv:- StandardFormatMerged-output.csv")
print("#" * 80)
