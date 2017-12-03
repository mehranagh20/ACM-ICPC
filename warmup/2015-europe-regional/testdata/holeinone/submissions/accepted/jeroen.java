// O(n! * n^2)

import java.util.*;
import java.io.*;

public class jeroen {
	private static int n;
	private static Point hole;
	private static Point[] w1, w2;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		hole = new Point(sc.nextInt(), sc.nextInt());
		w1 = new Point[n];
		w2 = new Point[n];
		for(int i = 0; i < n; i++) {
			w1[i] = new Point(sc.nextInt(), sc.nextInt());
			w2[i] = new Point(sc.nextInt(), sc.nextInt());
		}
		answer = -1;
		phole = hole.copy();
		rec(0);
		if(answer == -1)
			System.out.println("impossible");
		else
			System.out.println(answer);
	}

	static int answer;
	static Point phole; // projected hole
	
	public static void rec(int done) {
		// check if this direction vector leads to valid answer
		// phole gives the direction vector from origin
		int nextwall;
		int hits = 0;
		int destr = 0;
		double pos = 0;
		Point curhole = hole.copy();
		Point[] curw1 = new Point[n];
		Point[] curw2 = new Point[n];
		for(int i = 0; i < n; i++) {
			curw1[i] = w1[i].copy();
			curw2[i] = w2[i].copy();
		}
		do {
			int dx = phole.x;
			int dy = phole.y;
			if(dx == 0 && dy == 0) break;
			
			// Find next wall we'll hit
			nextwall = -1;
			double walldst = -1;
			for(int i = 0; i < n; i++) {
				if((destr & (1<<i)) != 0) continue;
				if(curw1[i].x == curw2[i].x) {
					// vertical
					double dist = (double)curw1[i].x / dx;
					if(Integer.signum(dx) == Integer.signum(curw1[i].x)
					   && ((curw1[i].y * dx <= dy * curw1[i].x && dy * curw1[i].x <= curw2[i].y * dx) || (curw2[i].y * dx <= dy * curw1[i].x && dy * curw1[i].x <= curw1[i].y * dx))
					   && dist >= pos) {
						if(nextwall == -1 || dist < walldst) {
							nextwall = i;
							walldst = dist;
						}
					}
				} else {
					// horizontal
					double dist = (double)curw1[i].y / dy;
					if(Integer.signum(dy) == Integer.signum(curw1[i].y)
					   && ((curw1[i].x * dy <= dx * curw1[i].y && dx * curw1[i].y <= curw2[i].x * dy) || (curw2[i].x * dy <= dx * curw1[i].y && dx * curw1[i].y <= curw1[i].x * dy))
					   && dist >= pos) {
 						if(nextwall == -1 || dist < walldst) {
							nextwall = i;
							walldst = dist;
						}
					}
				}
			}

			// Check if we'll hit the hole
			double holedst = dx == 0 ? (double)curhole.y / dy : (double)curhole.x / dx;
			if(holedst >= pos && curhole.x * dy == curhole.y * dx) {
				// Check if there isn't a wall in between
				if(nextwall == -1 || holedst >= pos && holedst < walldst)
					answer = Math.max(answer, hits);
			}

			// Update variables
			hits++;
			if(nextwall != -1) {
				pos = walldst;
				destr |= 1 << nextwall;
				curhole = curhole.mirror(curw1[nextwall], curw2[nextwall]);
				for(int i = 0; i < n; i++) {
					curw1[i] = curw1[i].mirror(curw1[nextwall], curw2[nextwall]);
					curw2[i] = curw2[i].mirror(curw1[nextwall], curw2[nextwall]);
				}
			}
		} while(nextwall != -1);

		// Continue via other walls
		for(int i = 0; i < n; i++) {
			if((done & (1<<i)) == 0) {
				// project phole
				Point prevhole = phole;
				phole = phole.mirror(w1[i], w2[i]);
				rec(done | (1<<i));
				phole = prevhole;
			}
		}
	}
}

class Point {
	public int x, y;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public Point copy() {
		return new Point(x, y);
	}

	// Mirror point on given wall
	public Point mirror(Point w1, Point w2) {
		if(w1.x == w2.x) {
			// vertical
			return new Point(2 * w1.x - x, y);
		} else {
			// horizontal
			return new Point(x, 2 * w1.y - y);
		}
	}

	public String toString() {
		return x + " " + y;
	}
}
