#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
two_int_first_line = re.compile(integer + " " + integer + "\n")
single_integer = re.compile(integer)

line = stdin.readline()
assert two_int_first_line.match(line)
n, m = map(int, line.strip().split())
assert 0 <= n <= 100 and 1 <= m <= 10000

for i in range(n):
    elements = stdin.readline().strip().split(' ')
    assert len(elements) == 4
sys.exit(42)
