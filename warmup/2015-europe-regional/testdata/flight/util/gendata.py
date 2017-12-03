from geom3d import *
import random
import sys

MAXSIZE=30
MAXPOLYS=30
MAXROUTE=30

MIN_MAX_ARC=0.03 # ~1.7 degrees
SHUFFLE_DATA = True

# 0.1/6370 would be 0.1 km, this enforces slightly stricter tolerance
DISTTOLERANCE=0.1/5000

case_no = 1

def print_case(islands, route, casetype='rand'):
    global case_no
    fname = '%02d-%s-%d-continents.in' % (case_no, casetype, len(islands))
    case_no += 1

    if SHUFFLE_DATA:
        random.shuffle(islands)

    with open(fname, 'w') as out:
        out.write('%d\n' % len(islands))
        for I in islands:
            if SHUFFLE_DATA:
                i = random.randint(0, len(islands)-1)
                I = I[i:] + I[:i]
            out.write('%d\n' % len(I))
            for P in I:
                out.write('%d %d\n' % (P[0], P[1]))
        out.write('%d\n' % len(route))
        for P in route:
            out.write('%d %d\n' % (P[0], P[1]))

def rand_pt(min_lng=0, max_lng=359, min_lat=-90, max_lat=90):
    lat = random.randint(min_lat, max_lat)
    lng = random.randint(min_lng, max_lng) % 360
    return (lat, lng)

def gen_poly(N, max_arc_len=None):
    TRIES = 2500
    attempts = 0
    while True:
        attempts += 1
        tries = 0
        pol = rand_pt()
        res = [pol]
        poly = [from_polar(pol)]
        for i in range(1, N):
            poly.append(None)
            for tries in range(tries, TRIES):
                iters = 0
                while True:
                    iters += 1
                    assert iters <= 1000
                    min_lat = max(-90, int(math.floor(res[-1][0] - 180*max_arc_len/math.pi)))
                    max_lat = min(90, int(math.ceil(res[-1][0] + 180*max_arc_len/math.pi)))
                    min_lng = 360*5+int(math.floor(res[-1][1] - 5*180*max_arc_len/math.pi))
                    max_lng = 360*5+int(math.ceil(res[-1][1] + 5*180*max_arc_len/math.pi))
                    pol = rand_pt(min_lng=min_lng, max_lng=max_lng, min_lat=min_lat, max_lat=max_lat)
                    if pol == res[-1]:
                        continue
                    poly[-1] = from_polar(pol)
                    if max_arc_len is None or poly[-1].angle(poly[-2]) <= max_arc_len:
                        break
                if simple_poly(poly, closed=(i==N-1), only_last=True):
                    res.append(pol)
                    break
            else:
                break
        else:
            print '      Genpoly %d %lf took %d attempts' % (N, max_arc_len, attempts)
            return res

def gen_route(N, islands):
    route = []
    # Need two points inside islands
    cart_route = []
    while len(route) < 2:
        pol = rand_pt()
        p = from_polar(pol)
        for I in islands:
            if point_in_poly(I, p, tolerance=DISTTOLERANCE) == 1:
                break
        else:
            continue
        route.append(pol)
        cart_route.append(p)
    while len(route) < N:
        pol = rand_pt()
        p = from_polar(pol)
        ok = True
        for I in islands:
            for q in I:
                if line_point_dist(cart_route[-1], p, q) < DISTTOLERANCE:
                    ok = False
                    break
            if not ok or point_in_poly(I, p, tolerance=DISTTOLERANCE) == 0:
                ok = False
                break
        if ok:
            route.append(pol)
            cart_route.append(p)
    for I in islands:
        for q in I:
            if line_point_dist(cart_route[-1], cart_route[0], q) < DISTTOLERANCE:
                # D'oh! Try again
                return gen_route(N, islands)
    # shift points so that the points inside are first and last
    return route[1:] + [route[0]]


def gen_case(Psizes, Rsize, accept_fails=True):
    print 'GENCASE %d: %d islands' % (case_no, len(Psizes))
    islands = []
    islands_cartesian = []
    failures = 0
    for s in Psizes:
        max_len = math.pi
        if len(s) > 1: max_len = s[1]
        sz = s[0]
        print '   [%d: %d+%d/%d] Add island sz %d max_len %lf' % (case_no, len(islands), failures, len(Psizes), sz, max_len)
        # Now let's try to add a poly with the given parameters

        # Only try a few different polys since they're a bit expensive to generate
        max_poly_tries = 5
        if not accept_fails and len(islands) >= 5: max_poly_tries = 10000
        for poly_tries in range(max_poly_tries): 
            I = gen_poly(sz, max_arc_len=max_len)
            # Try all possible rotations around pole of this poly and see if
            # we can make it fit
            for lng_change in range(360):
                RI = [(lat, (lng+lng_change)%360) for (lat, lng) in I]
                RC = [from_polar(c) for c in RI]
                ok = True
                assert simple_poly(RC)
                for J in islands_cartesian:
                    if polys_isect(RC, J):
                        ok = False
                        break
                if ok:
                    islands.append(RI)
                    islands_cartesian.append(RC)
                    break
            if ok:
                break
            print "      Failed to find rot candidate continent %d (%d %s)" % (poly_tries+1, sz, max_len)
            # Make the next one smaller
            max_len = max(MIN_MAX_ARC, max_len/1.75)
        if not ok:
            print '   Failed to add continent %d (%d %lf)' % (len(islands)+1, sz, max_len)
            failures += 1
            if 2*failures > len(Psizes) or failures >= len(islands) or not accept_fails:
                print 'Too many failures, restarting...'
                return gen_case(Psizes, Rsize)
        sys.stdout.flush()
        
    if 2*len(islands) < len(Psizes):
        print '   Got too few continents, restarting...'
        return gen_case(Psizes, Rsize)

    for i in range(len(islands)):
        for j in range(i):
            assert not polys_isect(islands_cartesian[i], islands_cartesian[j])

#    print 'ISLANDS FOR %d' % case_no
#    print islands

    assert len(islands) > 0
    print '   Adding route with %d checkpoints' % Rsize
    route = gen_route(Rsize, islands_cartesian)
    print_case(islands, route)



random.seed(42)

gen_case([[5, 0.2]], 7)
gen_case([[5, 0.2], [7, 0.2], [9, 0.1]], 7)

# Small cases
for i in range(10):
    C = random.randint(1, MAXPOLYS/3)
    max_arc = random.uniform(MIN_MAX_ARC, 2)
    sizes = [(random.randint(3, 10), random.uniform(MIN_MAX_ARC, max_arc)) for i in range(C)]
    routelen = random.randint(2, MAXROUTE/5)
    gen_case(sizes, routelen)

gen_case([[MAXSIZE]], MAXROUTE)
gen_case(2*[[MAXSIZE,0.2]], MAXROUTE)
gen_case(MAXPOLYS*[[5,0.25]], MAXROUTE, accept_fails=False)

# Big cases
for i in range(10):
    C = random.randint(MAXPOLYS/3, MAXPOLYS)
    max_arc = random.uniform(MIN_MAX_ARC, 2)
    sizes = [(random.randint(5, MAXSIZE), random.uniform(MIN_MAX_ARC, max_arc)) for i in range(C)]
    routelen = random.randint(MAXROUTE/5, MAXROUTE)
    gen_case(sizes, routelen)

gen_case(MAXPOLYS*[[MAXSIZE,0.25]], MAXROUTE, accept_fails=False)


