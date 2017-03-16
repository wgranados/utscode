#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
two_ints = re.compile(integer + " "+ integer+ "\n")
single_integer = re.compile(integer)

line = stdin.readline().split()
assert len(line) == 4
for i in range(4):
    try:
        x = float(line[i])
    except ValueError as e:
        assert False
a, b, t, x = map(float, line)
assert a+b+t == 1.0
line = stdin.readline()
assert two_ints.match(line)

sys.exit(42)
