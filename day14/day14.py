def read_file(fileName):
    file = open(fileName, "r")
    lines = file.readlines()
    return lines

def calculate_weight_north(input_data: [str]) -> int:
    nr_of_columns = len(input_data[0])
    nr_of_lines = len(input_data)
    weight = 0
    for column_nr in range(nr_of_columns - 1):
        column = create_prototype_line(nr_of_lines)
        cache_of_stones = 0
        for inverted_line_nr in range(nr_of_lines):
            line_number = nr_of_lines - inverted_line_nr - 1
            if input_data[line_number][column_nr] == '.':
                continue
            if input_data[line_number][column_nr] == 'O':
                cache_of_stones += 1
            if input_data[line_number][column_nr] == '#':
                column = column[:line_number] + '#' + column[line_number+1:]
                for stone in range(cache_of_stones):
                    index_nr = line_number + 1 + stone
                    column = column[:index_nr] + 'O' + column[index_nr+1:]
                cache_of_stones = 0
        if cache_of_stones > 0:
            for stone in range(cache_of_stones):
                    column = column[:stone] + 'O' + column[stone+1:]
        weight += get_column_weight_north(column)
    return weight

def get_column_weight_north(input_data: str) -> int:
    res_value = 0
    for element_nr, element in enumerate(input_data):
        if (element) == 'O':
            res_value += len(input_data) - element_nr
    return res_value

def create_prototype_line(size: int) -> str:
    line = ''
    for nr in range(size):
        line += '.'
    return line

def main():
    file_data = read_file('data.txt')
    print(calculate_weight_north(file_data))

if __name__ == '__main__':
    main()