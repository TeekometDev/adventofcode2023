import re

games = open("day2/data.txt", "r")
lines = games.readlines()
sumOfValidGames = 0
maxRedBalls = 12
maxGreenBalls = 13
maxBlueBalls = 14

def checkConstraints(redBalls, greenBalls, blueBalls):
    defaultReturn = True
    if redBalls > maxRedBalls:
        defaultReturn = False
    if greenBalls > maxGreenBalls:
        defaultReturn = False
    if blueBalls > maxBlueBalls:
        defaultReturn = False
    return defaultReturn

for index, line in enumerate(lines):
    resLine = re.sub('Game [0-9]+: ', '', line)
    games = resLine.split("; ")
    gameIsValid = True
    for game in games:
        balls = game.split(", ")
        redBalls = 0
        greenBalls = 0
        blueBalls = 0
        for color in balls:
            if "red" in color:
                redBalls = int(color.split(" ")[0])
            if "green" in color:
                greenBalls = int(color.split(" ")[0])
            if "blue" in color:
                blueBalls = int(color.split(" ")[0])
        gameIsValid = gameIsValid and checkConstraints(redBalls, greenBalls, blueBalls)
    if gameIsValid:
        sumOfValidGames += (index + 1)
print(sumOfValidGames)

power = 0

for index, line in enumerate(lines):
    resLine = re.sub('Game [0-9]+: ', '', line)
    games = resLine.split("; ")
    redBalls = 0
    greenBalls = 0
    blueBalls = 0
    for game in games:
        balls = game.split(", ")
        for color in balls:
            if ("red" in color) and (int(color.split(" ")[0]) > redBalls):
                redBalls = int(color.split(" ")[0])
            if ("green" in color) and (int(color.split(" ")[0]) > greenBalls):
                greenBalls = int(color.split(" ")[0])
            if ("blue" in color) and (int(color.split(" ")[0]) > blueBalls):
                blueBalls = int(color.split(" ")[0])
    power += redBalls * greenBalls * blueBalls
print(power)
