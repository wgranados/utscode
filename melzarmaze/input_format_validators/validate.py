#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
two_int_first_line = re.compile(integer + " " + integer + "\n")
single_integer = re.compile(integer)

line = stdin.readline()
try:
    n, m = map(int, line.split())
except ValueError as e:
    assert False

assert 1 <= n, m <= 5000

for i in range(n):
    elements = stdin.readline().strip().split()
    assert len(elements) == m
    for j in range(m):
        try:
            n = int(elements[j])
        except ValueError:
            assert False
sys.exit(42)
