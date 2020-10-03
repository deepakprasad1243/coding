#friday the 13th

mport datetime
import calendar


def findDay(date):
    day = datetime.datetime.strptime(date, '%d %m %Y').weekday()
    return (calendar.day_name[day])


# Driver program
month = input()
year = input()
date = '13 '+str(month)+' '+str(year)
print(findDay(date) == 'Friday')