while True:
    n = int(input())
    if n == 0:
        break

    top = 1
    north = 2
    west = 3
    east = 4
    south = 5
    bottom = 6
    for i in range(n):
        dir = input().strip()
        if dir == 'north':
            tmp = top
            top = south
            south = bottom
            bottom = north
            north = tmp
        if dir == 'south':
            tmp = top
            top = north
            north = bottom
            bottom = south
            south = tmp
        if dir == 'east':
            tmp = top
            top = west
            west = bottom
            bottom = east
            east = tmp
        if dir == 'west':
            tmp = top
            top = east
            east = bottom
            bottom = west
            west = tmp

    print(top)
