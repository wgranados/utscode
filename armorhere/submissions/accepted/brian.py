#!/usr/bin/env python3
import math


def findCenter(maze):
    origx = len(maze)
    origy = len(maze[0])
    x = origx / 2
    y = origy / 2
    if origx == origy and (origx % 2 == 1):
        return origx//2, origy//2

    if(origx == 1 and origy == 1):
        return 0, 0
    if(origx == 3 and origy == 3):
        return 1, 1
    if(origx % 2 != 0):
        # If x and y are both odd
        if(origy % 2 != 0):
            return math.ceil(x), math.ceil(y)
        # if x is odd, y is even
        else:
            x = math.floor(x)
            y = int(y) - 1
            if(maze[x][y] > maze[x][y+1]):
                return x, y
            else:
                return x, y+1
    if(origy % 2 != 0):
        # If y and y are both odd
        if(origx % 2 != 0):
            return math.ceil(x), math.ceil(y)
        # if y is odd, y is even
        else:
            y = math.floor(y)
            x = int(x) - 1
            if(maze[x][y] > maze[x+1][y]):
                return x, y
            else:
                return x+1, y
    # If all of it is even, we find max of the four squares    
    else:
        x = int(x) - 1
        y = int(y) - 1
        mazeMax = max(maze[x][y], maze[x][y+1], maze[x+1][y], maze[x+1][y+1])
        if(maze[x][y] == mazeMax):
            return x, y
        elif(maze[x][y+1] == mazeMax):
            return x, y+1
        elif(maze[x+1][y] == mazeMax):
            return x+1, y
        else:
            return x+1, y+1
        
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
    sy, sx = findCenter(maze)
    can_move = True
    totalScrap = 0
    while(can_move):
        #print(sx, sy, maze[sx][sy])
        left = 0
        right = 0
        up = 0
        down = 0
        #print(sy, sx)
        #print(maze[sy][sx])
        if(sx - 1 >= 0):
            left = maze[sy][sx-1]
        if(sx + 1 < len(maze[0])):
            right = maze[sy][sx+1]
        if(sy - 1 >= 0):
            up = maze[sy-1][sx]
        if(sy + 1 < len(maze)):
            down = maze[sy+1][sx]
        mostScrap = max(left, down, up, right)
        totalScrap += maze[sy][sx]
        maze[sy][sx] = 0        
        if mostScrap == 0:
            can_move = False
        else:
            if(mostScrap == left):
                sx -= 1
                #print("moving l")
            elif(mostScrap == right):
                sx += 1
                #print("moving r")
            elif(mostScrap == up):
                sy -= 1
                #print("moving u")
            elif(mostScrap == down):
                sy += 1
                #print("moving d")

    print(totalScrap)