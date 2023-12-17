import pytest

from day13 import read_file, GameBoard, get_note_value, calculate_part_2

def test_number_of_returned_games():
    res_games = read_file('testdata.txt')
    assert len(res_games) == 2

def test_game1_fitting():
    testLines = []
    testLines.append("#.##..##.")
    testLines.append("..#.##.#.")
    testLines.append("##......#")
    testLines.append("##......#")
    testLines.append("..#.##.#.")
    testLines.append("..##..##.")
    testLines.append("#.#.##.#.")
    game1 = read_file('testdata.txt')[0].lines
    assert game1 == testLines

def test_game_results():
    lines = read_file('testdata.txt')
    assert get_note_value(lines) == 405

def test_game_task_2():
    lines = read_file('testdata.txt')
    assert calculate_part_2(lines) == 400
