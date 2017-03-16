#!/usr/bin/env python3
from sys import stdin
import re
import sys


line = stdin.readline()
try:
    n, m, e, u = map(int, line.strip().split())
except ValueError as e:
    assert False
assert 1 <= n <= 20 and 1 <= m <= 20

for i in range(e):
    line = stdin.readline()
    try:
        a, b, c = map(int, line.strip().split())
    except ValueError as e:
        assert False

for i in range(u):
    line = stdin.readline()
    try:
        a, b = map(int, line.strip().split())
    except ValueError as e:
        assert False
sys.exit(42)
