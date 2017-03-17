#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
two_int_first_line = re.compile(integer + " " + integer + "\n")
single_integer = re.compile(integer)

line = stdin.readline()
try:
    n, m , h, p = map(int, line.strip().split())
except ValueError as e:
    assert False
assert 2 <= n, h <= 5000 and 1 <= m <= 5000*5000 and 0 <= p <= 10

for i in range(m):
    elements = stdin.readline().strip().split(' ')
    assert len(elements) == 4
    try:
        u, v, t, m = map(int, elements)
    except ValueError:
        assert False
    assert (1 <= u, v <= n) and (1 <= t, m <= 10000)
try:
    u, v = map(int, stdin.readline().strip().split(' ') )
except ValueError:
    assert False
assert 1 <= u, v <= n
sys.exit(42)
