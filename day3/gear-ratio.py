symbols = open("day3/symbols.txt", "r")
symbolLines = symbols.readlines()

totalRatio = 0

def removeIndex(value, list):
    index = -1
    try:
        index = list.index(value)
        list.pop(index)
    except:
        pass

for lineindex, line in enumerate(symbolLines):
    for position, symbol in enumerate(line):
        if symbol == "*":
            number1 = 0
            number2 = 0
            invalid = False
            numbersToInvestigate = []
            if lineindex != 0:
                if position != 0:
                    numbersToInvestigate.append([lineindex - 1, position - 1])
                numbersToInvestigate.append([lineindex - 1, position])
                if position != len(line) - 2:
                    numbersToInvestigate.append([lineindex - 1, position + 1])
            if position != 0:
                numbersToInvestigate.append([lineindex, position - 1])
            if position != len(line) - 2:
                numbersToInvestigate.append([lineindex, position + 1])
            if lineindex != len(symbolLines) - 1:
                if position != 0:
                    numbersToInvestigate.append([lineindex + 1, position - 1])
                numbersToInvestigate.append([lineindex + 1, position])
                if position != len(line) - 2:
                    numbersToInvestigate.append([lineindex + 1, position + 1])
            while len(numbersToInvestigate) > 0:
                actNumber = numbersToInvestigate.pop()
                if symbolLines[actNumber[0]][actNumber[1]].isnumeric():
                    tempNumber = int(symbolLines[actNumber[0]][actNumber[1]])
                    if actNumber[1] > 0:
                        if symbolLines[actNumber[0]][actNumber[1] - 1].isnumeric():
                            tempNumber += int(symbolLines[actNumber[0]][actNumber[1] - 1]) * 10
                            removeIndex([actNumber[0], actNumber[1] - 1], numbersToInvestigate)
                            if actNumber[1] > 1:
                                if symbolLines[actNumber[0]][actNumber[1] - 2].isnumeric():
                                    tempNumber += int(symbolLines[actNumber[0]][actNumber[1] - 2]) * 100
                                    removeIndex([actNumber[0], actNumber[1] - 2], numbersToInvestigate)
                    if actNumber[1] < len(line) - 2:
                        if symbolLines[actNumber[0]][actNumber[1] + 1].isnumeric():
                            tempNumber = tempNumber * 10 + int(symbolLines[actNumber[0]][actNumber[1] + 1])
                            removeIndex([actNumber[0], actNumber[1] + 1], numbersToInvestigate)
                            if actNumber[1] < len(line) - 3:
                                if symbolLines[actNumber[0]][actNumber[1] + 2].isnumeric():
                                    tempNumber = tempNumber * 10 + int(symbolLines[actNumber[0]][actNumber[1] + 2])
                                    removeIndex([actNumber[0], actNumber[1] + 2], numbersToInvestigate)
                    if number1 == 0:
                        number1 = tempNumber
                    elif number2 == 0:
                        number2 = tempNumber
                    else:
                        invalid = True
                        break
            
            if not invalid:
                totalRatio += number1 * number2
                print("Line: ", lineindex, number1, "*", number2, "=", number1 * number2, "Total: ", totalRatio)
print(totalRatio)