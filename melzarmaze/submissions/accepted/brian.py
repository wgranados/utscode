#!/usr/bin/env python3
import math

# Melzar Maze DP Solution
# UTSCode 2017
# Not for public eyes
# @Author: Brian Chen

def calculateMinimumHP(dungeon):
    n = len(dungeon[0])
    need = [2**31] * (n-1) + [1]
    for row in dungeon[::-1]:
        for j in range(n)[::-1]:
            need[j] = max(min(need[j:j+2]) - row[j], 1)
    return need[0]

if __name__ == '__main__':
    x = input()
    nums = x.split()
    rows = int(nums[0])
    maze = []
    for i in range(0, rows):
        newRow = []
        cr = input()
        curRow = cr.split()
        for i in curRow:
            newRow.append(int(i))
        maze.append(newRow)
    x = calculateMinimumHP(maze)
    print(x)