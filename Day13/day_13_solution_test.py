from day13 import read_file, GameBoard, get_note_value, calculate_part_2

def test_task_1():
    gameBoards = read_file('realdata.txt')
    assert get_note_value(gameBoards) == 27664

def test_task_2():
    gameBoards = read_file('realdata.txt')
    assert calculate_part_2(gameBoards) == 33991
