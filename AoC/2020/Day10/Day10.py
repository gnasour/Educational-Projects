from itertools import groupby
import math
import operator

def parse_input(raw):
    return sorted(int(n) for n in raw.splitlines())

with open('Day10.txt') as file:
    input10 = parse_input(file.read())

def get_differences(joltages):
    return list(map(
        operator.sub,
        joltages + [joltages[-1] + 3],
        [0] + joltages
    ))

def multiply_diffs(differences):
    return differences.count(1) * differences.count(3)

def count_arrangements(differences):
    return math.prod(
        (2 ** (len(m) - 1)) - (len(m) == 4)
        for k, g in groupby(differences)
        if k == 1 and len((m := list(g))) > 1
    )

differences = get_differences(input10)
answer1 = multiply_diffs(differences)
answer2 = count_arrangements(differences)
x = [ m for k, g in groupby(differences) if k == 1 and len((m := list(g))) > 1]
# for k, g in groupby(differences):
#     print(k)
#     print(len(list(g)))
print(answer2)
print(x)