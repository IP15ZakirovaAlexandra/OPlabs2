import re
import time
from datetime import datetime, date


def getData():
    text = []
    flag = 'yes'
    while flag == 'yes':
        surname = input("Enter a surname of the client: ")
        surname = checkSurname(surname)

        strtime = input("Enter the time of appointment(USE FORMAT 19:30):")
        t = datetime.strptime(strtime, "%H:%M")
        tm = datetime.time(t)
        fulltime = datetime.combine(date.today(), tm)

        strdate = input("Enter the date of previous appointment(USE FORMAT 22.07.2019):")
        fulldate = datetime.strptime(strdate, '%d.%m.%Y')

        line = surname + ',' + str(fulltime) + ',' + str(fulldate) + ';\n'
        text.append(line)

        flag = input("\nIf you want to add a patient print 'yes':")
    return text


def checkSurname(text):
    digits = re.findall('[0-9]', text)
    while len(text) > 20 or len(text) <= 1 or len(digits) > 0:
        text = input("Enter surname again: ")
        digits = re.findall('[0-9]', text)
    return text


def fileWrite(text, name):
    file = open(name, "wb")
    for i in range(len(text)):
        line = text[i]
        file.write(line.encode())
    file.close()


def fileRead(name):
    text = []
    file = open(name, "rb")
    while True:
        line = file.readline().decode()
        if len(line) < 1:
            break
        text.append(line)
    file.close()
    return text


def delMissed(text):
    now = datetime.now().timetuple()
    for line in text:
        patient = line.split(',')
        buf = datetime.strptime(patient[1], "%Y-%m-%d %H:%M:%S").timetuple()
        tm1 = time.mktime(buf)
        tm2 = time.mktime(now)
        time_diff = tm2 - tm1
        if time_diff > 0:
            text.remove(line)
    return ''.join(text)


def sortData(text, name1, name2):
    data = date.today().timetuple()
    text1 = []
    text2 = []
    lines = text.split(';\n')
    lines = lines[:-1]
    for line in lines:
        patient = line.split(',')
        buf = datetime.strptime(patient[2], "%Y-%m-%d %H:%M:%S").timetuple()
        dt1 = time.mktime(buf)
        dt2 = time.mktime(data)
        date_diff = dt2 - dt1
        if date_diff <= 864000.0:
            text1.append(line + ';\n')
        else:
            text2.append(line + ';\n')
    fileWrite(text1, name1)
    fileWrite(text2, name2)


def fileOutput(name):
    file = open(name, "rb")
    print('\n' + name + ' contains:\n')
    while True:
        line = file.readline().decode()
        if len(line) < 1:
            break
        if len(line) > 2:
            print(line, end='')
    file.close()
