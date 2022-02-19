import sys


def readConsole():
    text = sys.stdin.read()  # Ctrl+D для завершения ввода
    return text


def inputInFile(text, name):
    if name == 'FirstFile.txt':
        file = open(name, 'at')  # открытие на дозапись для первого файла
    else:
        file = open(name, 'wt')  # предварительное удаление контента из второго файла
    file.write(text)
    file.close()


def readFileContent(name):
    with open(name) as file:
        text = file.readlines()
    file.close()
    return text


def changeText(text):
    changed = ''
    '\n'.join(text)
    sort = sorted(text, key=len)

    for line in sort:
        line = line[:len(line) - 1]
        line += str(len(line))
        changed += line + '\n'
    changed.join('\n')
    return changed


def printFileContent(name):
    file = open(name, 'rt')
    text = file.read()
    file.close()
    for line in text:
        line.strip()
    message = ' The ' + name + ' contains: '
    print('{:~^100}'.format(message))
    print(text)
