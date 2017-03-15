#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
two_int_first_line = re.compile(integer + " " + integer + "\n")
single_integer = re.compile(integer)

line = stdin.readline()
assert two_int_first_line.match(line)
n, m = map(int, line.split())
assert 0 <= n <= 5000 and 0 <= m <= 5000

for i in range(n):
    elements = stdin.readline().strip().split(' ')
    assert len(elements) == m
    for j in range(m):
        assert single_integer.match(elements[j])
        assert 0 <= int(elements[j]) <= 2**31-1
sys.exit(42)
