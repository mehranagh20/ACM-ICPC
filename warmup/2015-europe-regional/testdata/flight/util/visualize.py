# Unfortunately matplotlib is not that great at 3D drawings.
# In particular this script does not yield very nice visualizations
# but they can be useful for inspecting that test data
# looks OK
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
from mpl_toolkits.mplot3d.art3d import Line3DCollection
import matplotlib.pyplot as plt
import numpy as np
import geom3d
import math
import sys

def add_sphere(ax):
    u = np.linspace(0, 2 * np.pi, 100)
    v = np.linspace(-np.pi/2, np.pi/2, 50)
    x = np.outer(np.cos(u), np.cos(v))*0.98
    y = np.outer(np.sin(u), np.cos(v))*0.98
    z = np.outer(np.ones(np.size(u)), np.sin(v))*0.98
    ax.plot_wireframe(x, y, z,  rstride=4, cstride=4, color='b')


def circ_arc(A, B, granularity=200):
    ang_step = 2*np.pi/granularity
    steps = int(1+math.ceil(A.angle(B)/ang_step))
    xr = np.linspace(A.x, B.x, steps)
    yr = np.linspace(A.y, B.y, steps)
    zr = np.linspace(A.z, B.z, steps)
    r = []
    for j in range(steps-1):
        Q = geom3d.point(xr[j], yr[j], zr[j]).normalize()
        r.append((Q.x, Q.y, Q.z))
    return r

def add_poly(ax, P):
    pts = []
    for i in range(len(P)):
        pts.extend(circ_arc(P[i-1], P[i]))
    ax.add_collection3d(Poly3DCollection([pts], edgecolor='k', facecolor='g'))

def add_route(ax, R):
    pts = []
    for i in range(1, len(R)):
        pts.extend(circ_arc(R[i-1], R[i]))
    pts.append((R[-1].x, R[-1].y, R[-1].z))
    pts = [(1.1*x, 1.1*y, 1.1*z) for (x,y,z) in pts]
    ax.add_collection3d(Line3DCollection([pts], color='r'))


def readp():
    toks = map(int, sys.stdin.readline().split())
    N = toks[0]
    return [geom3d.from_polar(c) for c in zip(toks[1::2], toks[2::2])]


def main():
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    add_sphere(ax)

    N = int(sys.stdin.readline())
    PP = []
    for i in range(N):
        P = readp()
        PP.append(P)
        q = geom3d.point_outside(P)
        print q.dist()
        add_poly(ax, P)
        ax.scatter([1.01*q.x], [1.01*q.y], [1.01*q.z], c='w',marker='^')

#    myout2 = geom3d.point_outside(PP[0], seg=9,shift1=0.509792, shift2=0.642889, ax=ax)
#    ax.scatter([myout2.x], [myout2.y], [myout2.z], c='k', marker='o')
#    q = geom3d.point_outside(PP[0])
#    pts = circ_arc(q, PP[1][0])
#    ax.add_collection3d(Line3DCollection([pts], color='c'))


    R = readp()
    add_route(ax, R)

    plt.show()

if __name__=='__main__': main()

