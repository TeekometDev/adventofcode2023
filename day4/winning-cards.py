import re

games = open("day4/data.txt", "r").readlines()

wonCars = [1] * len(games)

combinedCards = 0
for index, game in enumerate(games):
    cleared = re.sub("Card [0-9]+: ", "", game)
    cleared = re.sub("\n", "", cleared)
    cards = cleared.split(" | ")
    winnings = cards[0].split(" ")
    nums = cards[1].split(" ")
    nums = [num for num in nums if num]
    numberOfWins = 0
    for win in winnings:
        if win in nums:
            numberOfWins += 1
    while numberOfWins > 0:
        if len(wonCars) > index + numberOfWins:
            wonCars[index + numberOfWins] += wonCars[index]
        numberOfWins -= 1

print(sum(wonCars))