symbols = open("day3/symbols.txt", "r")
symbolLines = symbols.readlines()

def validNumber(char):
    return not (char.isnumeric() or char == "." or char == "\n")

resSum = 0

for lineindex, line in enumerate(symbolLines):
    isValid = False
    actNum = 0
    for position, symbol in enumerate(line):
        if symbol.isnumeric():
            actNum = actNum * 10 + int(symbol)
            if lineindex != 0:
                if position != 0:
                    isValid = isValid or validNumber(symbolLines[lineindex - 1][position - 1])
                if position != len(line) - 2:
                    isValid = isValid or validNumber(symbolLines[lineindex - 1][position + 1])
                isValid = isValid or validNumber(symbolLines[lineindex - 1][position])
            if lineindex != len(symbolLines) - 1:
                if position != 0:
                    isValid = isValid or validNumber(symbolLines[lineindex + 1][position - 1])
                if position != len(line) - 2:
                    isValid = isValid or validNumber(symbolLines[lineindex + 1][position + 1])
                isValid = isValid or validNumber(symbolLines[lineindex + 1][position])
            if position != 0:
                isValid = isValid or validNumber(line[position - 1])
            if position != len(line) - 2:
                isValid = isValid or validNumber(line[position + 1])
            # print(lineindex, ": ", position, ": ", symbol, "is Numeric", isValid, actNum)
        elif isValid:
            resSum += actNum
            # print("add ", actNum, " to sum ", resSum)
            actNum = 0
            isValid = False
        else:
            actNum = 0
    if isValid:
        resSum += actNum
        print("add2 ", actNum, " to sum ", resSum)
