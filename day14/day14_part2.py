class Board:
    def __init__(self, board: [str]):
        self.board = board
        self.old_weight = self.get_column_weight_north()

    def get_column_weight_north(self) -> int:
        res_value = 0
        for line_nr, line in enumerate(self.board):
            for element_nr, element in enumerate(line):
                if (element) == 'O':
                    res_value += len(self.board) - line_nr + 1
        return res_value
    
    def convert_lines_to_columns(self, input: [str]) -> [str]:
        res_value = []
        for column_nr in range(len(input[0]) -1):
            column = ''
            for line_nr in range(len(input) - 1):
                column += input[line_nr][column_nr]
            res_value.append(column)
        return res_value
    
    def tilt_north(self):
        defined_columns = self.convert_lines_to_columns(self.board)
        new_columns = []
        for column_nr, column in enumerate(defined_columns):
            new_column = create_prototype_line(len(column))
            cache_of_stones = 0
            for inverted_line_nr in range(len(column)):
                line_number = len(column) - inverted_line_nr - 1
                if column[line_number] == '.':
                    continue
                if column[line_number] == 'O':
                    cache_of_stones += 1
                if column[line_number] == '#':
                    new_column = new_column[:line_number] + '#' + new_column[line_number+1:]
                    for stone in range(cache_of_stones):
                        index_nr = line_number + 1 + stone
                        new_column = new_column[:index_nr] + 'O' + new_column[index_nr+1:]
                    cache_of_stones = 0
            if cache_of_stones > 0:
                for stone in range(cache_of_stones):
                        new_column = new_column[:stone] + 'O' + new_column[stone+1:]
            new_columns.append(new_column)
        print(new_columns)
        self.board = self.convert_lines_to_columns(new_columns)

    def tilt_south(self):
        defined_columns = self.convert_lines_to_columns(self.board)
        new_columns = []
        for column_nr, column in enumerate(defined_columns):
            new_column = create_prototype_line(len(column))
            cache_of_stones = 0
            for line_nr in range(len(column)):
                if column[line_nr] == '.':
                    continue
                if column[line_nr] == 'O':
                    cache_of_stones += 1
                if column[line_nr] == '#':
                    new_column = new_column[:line_nr] + '#' + new_column[line_nr+1:]
                    for stone in range(cache_of_stones):
                        index_nr = line_nr - 1 - stone
                        new_column = new_column[:index_nr] + 'O' + new_column[index_nr+1:]
                    cache_of_stones = 0
            if cache_of_stones > 0:
                for stone in range(cache_of_stones):
                        new_column = new_column[:len(column) - stone - 1] + 'O' + new_column[len(column) - stone:]
            new_columns.append(new_column)
        self.board = self.convert_lines_to_columns(new_columns)

    def tilt_east(self):
        new_board = []
        for line in self.board:
            new_line = ''
            cache_of_stones = 0
            for element_nr in range(len(line)):
                if line[element_nr] == '.':
                    continue
                if line[element_nr] == 'O':
                    cache_of_stones += 1
                if line[element_nr] == '#':
                    new_line += '#'
                    for stone in range(cache_of_stones):
                        new_line += 'O'
                    cache_of_stones = 0
            if cache_of_stones > 0:
                for stone in range(cache_of_stones):
                        new_line += 'O'
            new_board.append(new_line)
        self.board = new_board

    def tilt_west(self):
        new_board = []
        for line in self.board:
            new_line = ''
            cache_of_stones = 0
            for element_nr in range(len(line)):
                if line[element_nr] == '.':
                    continue
                if line[element_nr] == 'O':
                    cache_of_stones += 1
                if line[element_nr] == '#':
                    for stone in range(cache_of_stones):
                        new_line += 'O'
                    new_line += '#'
                    cache_of_stones = 0
            if cache_of_stones > 0:
                for stone in range(cache_of_stones):
                        new_line += 'O'
            new_board.append(new_line)
        self.board = new_board
    
    def calculate_after_times(self, times: int) -> int:
        for time in range(times):
            self.tilt_north()
            self.tilt_west()
            self.tilt_south()
            self.tilt_east()
        return self.old_weight
    
def create_prototype_line(size: int) -> str:
    line = ''
    for nr in range(size):
        line += '.'
    return line