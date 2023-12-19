from day14 import read_file, calculate_weight_north
from day14_part2 import Board

def test_part_1():
    testdata = read_file('testdata.txt')
    assert calculate_weight_north(testdata) == 136

def test_board_class_pretest():
    testdata = read_file('testdata.txt')
    board = Board(testdata)
    board.tilt_north()
    north_weight = board.get_column_weight_north()
    assert north_weight == 136

def test_board_class_pretest_2():
    testdata = read_file('testdata.txt')
    board = Board(testdata)
    board.calculate_after_times(1)
    res_text = ['.....#....', '....#...O#', '...OO##...', '.OO#......', '.....OOO#.', '.O#...O#.#', '....O#....', '......OOOO', '#...O###..', '#..OO#....']
    print(board.board)
    assert board.board == res_text

def _test_part_2():
    testdata = read_file('testdata.txt')
    board = Board(testdata)
    assert board.calculate_after_times(1000000000) == 64