from day14 import read_file, calculate_weight_north

def test_part_1():
    testdata = read_file('testdata.txt')
    assert calculate_weight_north(testdata) == 136