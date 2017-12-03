# Some basic spherical geometry primitives for dealing with arcs and polygons
# Written for specific purpose and not really meant to be reused
# Author: Per Austrin

EPSILON=1e-7

import math
import random

class point:
    def __init__(self, x = 0, y = 0, z = 0):
        (self.x, self.y, self.z) = (x, y, z)

    def add(self, p):
        return point(self.x+p.x, self.y+p.y, self.z+p.z)

    def sub(self, p):
        return point(self.x-p.x, self.y-p.y, self.z-p.z)

    # Check if equal to p
    def eq(self, p):
        return abs(self.x-p.x)+abs(self.y-p.y)+abs(self.z-p.z) < EPSILON

    # Check if equal to p or -p
    def eq_or_anti(self, p):
        return min(abs(self.x-p.x)+abs(self.y-p.y)+abs(self.z-p.z),
                   abs(self.x+p.x)+abs(self.y+p.y)+abs(self.z+p.z)) < EPSILON

    def zero(self):
        return abs(self.x) + abs(self.y) + abs(self.z) < EPSILON

    def dist(self):
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)

    def normalize(self):
        d = self.dist()
        return point(self.x/d, self.y/d, self.z/d)

    def normal(self, p):
        return self.cross(p).normalize()

    def cross(self, p):
        return point(self.y*p.z-self.z*p.y,
                     self.z*p.x-self.x*p.z,
                     self.x*p.y-self.y*p.x)

    def dot(self, p):
        return self.x*p.x + self.y*p.y + self.z*p.z

    def angle(self, p):
        dot = self.dot(p)
        assert -1-1e-10 <= dot <= 1+1e-10, "%.20e" % dot
        return math.acos(min(max(dot, -1), 1))

    # Rotate point p an angle theta around self
    # (PRE: self is unit vector)
    def rotate(self, theta, p):
        # See http://mathworld.wolfram.com/RodriguesRotationFormula.html
        c1 = 2.0*(math.sin(theta/2.0)**2) # 1 - cos(theta)
        c = math.cos(theta)
        s = math.sin(theta)
        (x,y,z) = (self.x, self.y, self.z)
        W = [[c + x*x*c1, x*y*c1 - z*s, y*s + x*z*c1],
             [z*s + x*y*c1, c + y*y*c1, -x*s + y*z*c1],
             [-y*s + x*z*c1, x*s + y*z*c1, c + z*z*c1]]
        return point(W[0][0]*p.x + W[0][1]*p.y + W[0][2]*p.z,
                     W[1][0]*p.x + W[1][1]*p.y + W[1][2]*p.z,
                     W[2][0]*p.x + W[2][1]*p.y + W[2][2]*p.z)

    def __str__(self):
        return '(%.4f,%.4f,%.4f)' % (self.x, self.y, self.z)

def from_polar(c): # takes a pair/list of (latitude, longitude)
    (lat, lng) = c
    lat = lat*math.pi/180
    lng = lng*math.pi/180
    return point(math.cos(lat)*math.cos(lng),
                 math.cos(lat)*math.sin(lng),
                 math.sin(lat))

# Do these two circular arcs define the same great circle?
def parallel(P1, P2, Q1, Q2):
    N1 = P1.normal(P2)
    N2 = Q1.normal(Q2)
    return N1.eq_or_anti(N2)

# Any function below that takes a circular arc P1-P2 assumes that it
# is a valid circular arc, i.e., P1 != P2 and P1 != -P2.


def line_point_dist(P1, P2, Q):
    PN = P1.cross(P2)
    G = PN.cross(Q)
    if G.zero(): # Q perpendicular to the great circle, equidistant to all points
        return math.pi/2
    H = PN.normal(G)
    if P1.angle(H) + H.angle(P2) > P1.angle(P2) + EPSILON:
        (H.x, H.y, H.z) = (-H.x, -H.y, -H.z)
    if P1.angle(H) + H.angle(P2) < P1.angle(P2) + EPSILON:
        return H.angle(Q)
    return min(P1.angle(Q), P2.angle(Q))


# Distance between *edges* of polygon and Q
def poly_point_dist(Pts, Q):
    r = 1e30
    for i in range(len(Pts)):
        r = min(r, line_point_dist(P[i-1], P[i], Q))
    return r
        

# Is Q on the circular arc between P1 and P2?
def between(P1, Q, P2):
    return line_point_dist(P1, P2, Q) < EPSILON

# Does the two circular arcs P1-P2 and Q1-Q2 intersect?
# If yes: returns angle from P1 towards P2 of intersection point
#         (smallest such angle in case of overlapping parallel arcs)
# If no: returns None
def isect(P1, P2, Q1, Q2):
    if parallel(P1, P2, Q1, Q2):
        if between(Q1, P1, Q2): 
            return 0.0
        ang = 1e30
        if between(P1, Q1, P2):
            ang = min(ang, P1.angle(Q1))
        if between(P1, Q2, P2):
            ang = min(ang, P1.angle(Q2))
        return ang if ang < 1e30 else None
    # Two intersection candidates
    I1 = (P1.cross(P2)).normal(Q1.cross(Q2))
    I2 = point(-I1.x, -I1.y, -I1.z)
    if between(P1, I1, P2) and between(Q1, I1, Q2):
        return P1.angle(I1)
    if between(P1, I2, P2) and between(Q1, I2, Q2):
        return P1.angle(I2)
    return None


# Check if P defines a simple polygon
# if closed is false, does not do checks involving the segment from last point to first point
# if only_last is true, does not do any checks not involving the last point
def simple_poly(P, closed=True, only_last=False):
    for i in range(len(P)):
        if ((closed or i >= 1) and 
            P[i-1].eq_or_anti(P[i])):
            return False
    for i in range(len(P)):
        # Check that two adjacent segments not parallel (slightly
        # stricter than necessary, we only want to make sure that we
        # don't double back and make a degenerate part of the polygon)
        if ((closed or i >= 2) and
            parallel(P[i-2], P[i-1], P[i-1], P[i])):
            return False
        if only_last and (i != len(P)-1) and (not closed or i != 0):
            continue
        for j in range(len(P)-3):
            if not closed and (i == 0 or i-3-j == -1 or i-2-j == -1):
                continue
            # Check that non-adjacent line segments do not intersect
            if isect(P[i-1], P[i], P[i-2-j], P[i-3-j]) is not None:
                return False
    return True


# Check if two polys isect
# Does not check that the polys themselves are simple
def polys_isect(P1, P2):
    for i in range(len(P1)):
        for j in range(len(P2)):
            if isect(P1[i-1], P1[i], P2[j-1], P2[j]) is not None:
                return True
    if point_in_poly(P1, P2[0]) >= 0 or point_in_poly(P2, P1[0]) >= 0:
        return True
    return False

# Check if q is inside P by counting parity of crossings
# Assumes P is valid simple poly
# Returns -1 if outside, 0 if on (within "tolerance" radians), +1 if inside
def point_in_poly(P, q, tolerance=5e-6):
    out = point_outside(P, 
                        seg=random.randint(0, len(P)-1),
                        shift1=random.uniform(1.0/3, 2.0/3),
                        shift2=random.uniform(1.0/3, 2.0/3))
    inside = -1
    if out.eq(q): return False
    N = out.normal(q)
    for i in range(len(P)):
        if line_point_dist(P[i-1], P[i], q) < tolerance:
            return 0
        # We were unlucky with the choice of point outside P -- try again
        if abs(N.dot(P[i])) < EPSILON and not P[i].eq_or_anti(q):
            return point_in_poly(P, q)
        if isect(P[i-1], P[i], q, out) is not None:
            inside = -inside
    return inside

# Locate a point *outside* the polygon P
# Assumes P is valid simple poly
#
# Works as follows:
# 1. take any segment (segment "seg" below) of P  1605, 1606, 1608, 1611
# 2. let A be mid point of the segment
# 3. construct B by rotating A outwards from the segment pi/2 degrees    365
#    thus going from A to B we start on border of P, then leave P, and 
#    then may or may not cross P again
# 4. find all intersections of segment A-B with P (except the one we
#    already know about)
# 5. if minimum angle from A of all these intersections is minalpha,
#    then going an angle of minalpha/2 on the segment from A to B gives
#    a point outside P
#
# Allows varying the position of the point B and the rotation angle in
# step 5 in case the default values happen to lead to a "bad" point
# for the purposes of the caller
def point_outside(P, seg=1, shift1=0.5, shift2=0.5):
    N = P[seg-1].normal(P[seg])
    angle = P[seg-1].angle(P[seg])
    A = N.rotate(shift1*angle, P[seg-1])
#    assert between(P[seg-1], A, P[seg]), (P[seg-1].__str__(), P[seg].__str__(), shift1, line_point_dist(P[seg-1], P[seg], A))
    N2 = N.rotate(shift1*angle-math.pi/2.0, P[seg-1])
    B = N2.rotate(-math.pi/2, A)
    minalpha = math.pi/2
    for j in range(len(P)):
        if j == seg: continue
        alpha = isect(A, B, P[j-1], P[j])
        if alpha is not None:
            minalpha = min(minalpha, alpha)
    if minalpha < 1e-6: # This will not stand
        print 'Got a tight edge (slack %lf) on a poly, trying another edge' % (minalpha)
        return point_outside(P, 
                             seg = (seg+1) % len(P),
                             shift1=0.25+(shift1+1.0/12) % 0.5,
                             shift2=0.25+(shift2+3.0/20) % 0.5)
#    print 'minalpha = %lf' % minalpha
    return N2.rotate(-shift2*minalpha, A)

