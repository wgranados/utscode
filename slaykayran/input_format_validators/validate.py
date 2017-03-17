#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
two_int_first_line = re.compile(integer + " " + integer + "\n")
single_integer = re.compile(integer)

line = stdin.readline()
try:
    n, h, r = map(int, line.split())
except ValueError as e:
    assert False
assert (1 <= n, h, r <= 5000)

for i in range(r):
    elements = stdin.readline().strip().split()
    print(i)
    assert len(elements) == 2
    assert 1 <= int(elements[0]), int(elements[1]) <= 5000
sys.exit(42)
