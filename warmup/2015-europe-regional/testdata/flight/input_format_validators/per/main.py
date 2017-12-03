import sys
import math
import re
from geom3d import *

MAX_N=30
MAX_SZ=30

### Utility for reading input ###        

INTEGER_RE='0|-?[1-9][0-9]*'

def read_ints(cnt = None):
    line = sys.stdin.readline()
    assert line[-1] == '\n'
    toks = line[:-1].split(' ')
    if cnt is not None:
        assert len(toks) == cnt
    for t in toks:
        assert re.match(INTEGER_RE, line), 'Token "%s" not an int' % t
    return map(int, toks)

def read_pts(min_cnt, max_cnt):
    data = read_ints()
    sz = data[0]
    assert min_cnt <= sz <= max_cnt, sz
    assert len(data) == 2*sz+1
    polar = zip(data[1::2], data[2::2])
    for (lat, lng) in polar:
        assert -90 <= lat <= 90
        assert 0 <= lng <= 359
    return map(from_polar, polar)


(N,) = read_ints(1)
assert 1 <= N <= MAX_N
islands = [read_pts(3, MAX_SZ) for i in range(N)]
route = read_pts(2, MAX_SZ)

# Check for trailing input
assert sys.stdin.readline() == ''

### Now remains to check semantic constraints ###

for I in islands:
    assert simple_poly(I)

for i in range(len(islands)):
    for j in range(i):
        assert not polys_isect(islands[i], islands[j]), 'poly %d and %d isect' % (i, j)

for i in range(1, len(route)):
    assert not route[i-1].eq_or_anti(route[i])

for p in [route[0], route[-1]]:
    for I in islands:
        if point_in_poly(I, p) == 1:
            break
    else:
        assert '%s not in any island' % p

# Check the special guarantees that are not inherent in the problem
# but just there to make it less painful to solve.
MIN_DIST = 0.1 / 6370 # radians of 0.1 km

for p in route:
    for I in islands:
        assert point_in_poly(I, p, tolerance=MIN_DIST) != 0

for I in islands:
    for p in I:
        for i in range(1, len(route)):
            assert line_point_dist(route[i-1], route[i], p) > MIN_DIST, (p.__str__(), i, line_point_dist(route[i-1], route[i], p))


sys.exit(42)
