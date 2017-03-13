#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
one_int_first_line = re.compile(integer + "\n")
single_integer = re.compile(integer)

line = stdin.readline()
assert one_int_first_line.match(line)
n = int(line)
assert 0 <= n <= 5000

line_two = stdin.readline().strip().split(' ')
assert len(line_two) == n

for i in range(n):
    assert single_integer.match(line_two[i])
    assert 0 <= int(line_two[i]) <= 2**31-1

sys.exit(42)
