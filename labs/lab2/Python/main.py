import funcs

text = funcs.getData()

funcs.fileWrite(text, "FirstFile.bin")
funcs.fileOutput("FirstFile.bin")

fileText = funcs.fileRead("FirstFile.bin")
newText = funcs.delMissed(fileText)
funcs.fileWrite(newText, "FirstFile.bin")
funcs.fileOutput("FirstFile.bin")

funcs.sortData(newText, "SecondFile.bin", "ThirdFile.bin")
funcs.fileOutput("SecondFile.bin")
funcs.fileOutput("ThirdFile.bin")
