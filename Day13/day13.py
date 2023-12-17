import sys

class GameBoard:
    def __init__(self, lines: [str]):
        self.lines: [str] = []
        self.columns: [str] = []
        self.horizontal_value = 0
        self.vertical_value = 0
        for line in lines:
            self.lines.append(line.strip())
        self.calculate_columns()

    def calculate_columns(self):
        self.columns = []
        for character in range(len(self.lines[0])):
            colLine = ""
            for line in self.lines:
                colLine += line[character]
            self.columns.append(colLine)
    def get_value(self, iteration_list: [str]) -> int:
        resultValue = 0
        for i, line in enumerate(iteration_list):
            if i != 0:
                isValid = False
                checkNum = 1
                while i + checkNum - 1 < len(iteration_list) and i - checkNum >= 0:
                    if iteration_list[i + checkNum - 1] == iteration_list[i - checkNum]:
                        isValid = True
                        checkNum += 1
                    else:
                        isValid = False
                        break
                if isValid == True:
                    linesAbove = i
                    # resultValue += linesAbove
                    return linesAbove
        return resultValue

    def get_horizontal_value(self) -> int:
        horizontal_value = self.get_value(self.lines)
        self.set_horizontal_value(horizontal_value)
        return horizontal_value

    def set_horizontal_value(self, value: int):
        self.horizontal_value = value

    def get_vertical_value(self) -> int:
        vertical_value = self.get_value(self.columns)
        self.set_vertical_value(vertical_value)
        return vertical_value

    def set_vertical_value(self, value: int):
        self.vertical_value = value

def read_file(file_name: str) -> [GameBoard]:
    file = open(file_name, 'r')
    if file.readable():
        setOfLines = file.readlines()
        listOfGames = []
        setOfNextGameLines = []
        for line in setOfLines:
            if line == '\n':
                listOfGames.append(GameBoard(setOfNextGameLines))
                setOfNextGameLines = []
            else:
                setOfNextGameLines.append(line)
        listOfGames.append(GameBoard(setOfNextGameLines))
        return listOfGames
    else:
        sys.exit(1)

def get_note_value(games: [GameBoard]) -> int:
    value = 0
    for game in games:
        hor_value = game.get_horizontal_value()
        vert_value = game.get_vertical_value()
        value += 100 * hor_value
        value += vert_value
    return value

def calculate_part_2(games: [GameBoard]) -> int:
    get_note_value(games)
    return_value = 0
    for game in games:
        game_value = 0
        for i, line in enumerate(game.lines):
            for j, character in enumerate(line):
                if game_value != 0:
                    break
                lineCopies = game.lines.copy()
                gameCopy: GameBoard
                if character == '#':
                    lineCopies[i] = lineCopies[i][:j] + '.' + lineCopies[i][j+1:]
                    gameCopy = GameBoard(lineCopies)
                else:
                    lineCopies[i] = lineCopies[i][:j] + '#' + lineCopies[i][j+1:]
                    gameCopy = GameBoard(lineCopies)
                gameCopy.calculate_columns()
                hor_value = gameCopy.get_horizontal_value()
                if hor_value > 0 and hor_value != game.horizontal_value:
                    game_value += 100 * hor_value
                    break
                else:
                    vert_value = gameCopy.get_vertical_value()
                    if vert_value > 0 and vert_value != game.vertical_value:
                        game_value += vert_value
                        break
        return_value += game_value
    return return_value

def main():
    gameBoards = read_file('realdata.txt')
    print(get_note_value(gameBoards))
    print(calculate_part_2(gameBoards))

if __name__ == '__main__':
    main()
