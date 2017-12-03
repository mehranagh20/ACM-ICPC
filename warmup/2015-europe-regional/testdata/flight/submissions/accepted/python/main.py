# Not allowed in contest, just written as an additional
# sanity check.
import geom3d
import sys

def readp():
    toks = map(int, sys.stdin.readline().split())
    N = toks[0]
    return [geom3d.from_polar(c) for c in zip(toks[1::2], toks[2::2])]

C = int(sys.stdin.readline())
islands = [readp() for i in range(C)]
route = readp()

tot = 0.0
water = 0.0

inside = True
for (A,B) in zip(route[:-1], route[1:]):
    stops = [0, A.angle(B)]
    tot += stops[-1]
    for I in islands:
        for i in range(len(I)):
            alpha = geom3d.isect(A, B, I[i-1], I[i])
            if alpha is not None and abs(alpha - A.angle(I[i])) > 1e-6:
                stops.append(alpha)
    stops = sorted(stops)
    for i in range(1, len(stops)):
        if not inside: water += stops[i]-stops[i-1]
        if i < len(stops)-1: inside = not inside

print '%.6f %.6f' % (6370*tot, 100.0*water/tot)
