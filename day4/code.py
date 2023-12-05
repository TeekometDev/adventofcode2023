import re

games = open("day4/data.txt", "r").readlines()

combinedPoints = 0
for game in games:
    cleared = re.sub("Card [0-9]+: ", "", game)
    cleared = re.sub("\n", "", cleared)
    cards = cleared.split(" | ")
    winnings = cards[0].split(" ")
    nums = cards[1].split(" ")
    nums = [num for num in nums if num]
    powNr = 0
    for win in winnings:
        if win in nums:
            powNr += 1
    if powNr > 0:
        combinedPoints += pow(2, powNr - 1)

print(combinedPoints)