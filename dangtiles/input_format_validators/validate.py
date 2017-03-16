#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
four_ints = re.compile('{a} {b} {c} {d}\n'.format(a=integer, b=integer, c=integer, d=integer))
three_ints = re.compile('{a} {b} {c}\n'.format(a=integer, b=integer, c=integer))
two_ints = re.compile('{a} {b}\n'.format(a=integer, b=integer, c=integer))
single_integer = re.compile(integer)

line = stdin.readline()
assert four_ints.match(line)
n, m, e, u = map(int, line.strip().split())
assert 1 <= n <= 20 and 1 <= m <= 20

for i in range(e):
    line = stdin.readline()
    assert three_ints.match(line)

for i in range(u):
    line = stdin.readline()
    assert two_ints.match(line)
sys.exit(42)
