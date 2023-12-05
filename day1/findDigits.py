def getFirstNumeric(line):
    digit_not_found = True
    digit = 0
    while digit_not_found:
        if(line[digit].isnumeric() and digit < len(line)):
            digit_not_found = False
            return int(line[digit])
        else:
            if digit >= 2:
                concatText = line[digit-2]+line[digit-1]+line[digit]
                if concatText == "one":
                    return 1
                elif concatText == "two":
                    return 2
                elif concatText == "six":
                    return 6
            if digit >= 3:
                concatText = line[digit-3]+line[digit-2]+line[digit-1]+line[digit]
                if concatText == "four":
                    return 4
                elif concatText == "five":
                    return 5
                elif concatText == "nine":
                    return 9
            if digit >= 4:
                concatText = line[digit-4]+line[digit-3]+line[digit-2]+line[digit-1]+line[digit]
                if concatText == "three":
                    return 3
                elif concatText == "seven":
                    return 7
                elif concatText == "eight":
                    return 8
        digit += 1

def getLastNumeric(line):
    digit_not_found = True
    digit = len(line) - 1
    while digit_not_found:
        if(line[digit].isnumeric() and digit >= 0):
            digit_not_found = False
            return int(line[digit])
        else:
            if digit <= len(line) - 3:
                concatText = line[digit]+line[digit+1]+line[digit+2]
                if concatText == "one":
                    return 1
                elif concatText == "two":
                    return 2
                elif concatText == "six":
                    return 6
            if digit <= len(line) - 4:
                concatText = line[digit]+line[digit+1]+line[digit+2]+line[digit+3]
                if concatText == "four":
                    return 4
                elif concatText == "five":
                    return 5
                elif concatText == "nine":
                    return 9
            if digit <= len(line) - 5:
                concatText = line[digit]+line[digit+1]+line[digit+2]+line[digit+3]+line[digit+4]
                if concatText == "three":
                    return 3
                elif concatText == "seven":
                    return 7
                elif concatText == "eight":
                    return 8
        digit -= 1

inputData = open("day1/data.txt", "r")
lines = inputData.readlines()
sumOfNumerics = 0

for line in lines:
    firstNumeric = getFirstNumeric(line)
    lastNumeric = getLastNumeric(line)
    sumOfNumerics += firstNumeric * 10 + lastNumeric

print(sumOfNumerics)