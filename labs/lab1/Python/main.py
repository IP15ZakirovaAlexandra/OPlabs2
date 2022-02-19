import funcs

print('\n', '{:-^100}'.format(' PRESS THE CTRL+D ON A NEW LINE TO COMPLETE INPUT '), '\n\nEnter your text:\n')
text = funcs.readConsole()
funcs.inputInFile(text, 'FirstFile.txt')
text = funcs.readFileContent('FirstFile.txt')
changedText = funcs.changeText(text)
funcs.inputInFile(changedText, 'SecondFile.txt')
funcs.printFileContent('FirstFile.txt')
funcs.printFileContent('SecondFile.txt')
