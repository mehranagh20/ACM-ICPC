import java.util.*;
import java.math.*;

public class Paul {
	
	static class Point {
		int x, y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public Point(Point p) {
			this.x = p.x;
			this.y = p.y;
		}
	}

	static int n;
	static int[] p;
	static boolean[] used;
	static Point s, t;
	static Point[] w1, w2;

	static double dist(Point p, Point q) {
		double dx = p.x - q.x, dy = p.y - q.y;
		return Math.sqrt(dx*dx + dy*dy);
	}

	static void reflect(Point p, int k) {
		if (w1[k].x == w2[k].x) p.x += 2*(w1[k].x - p.x);
		if (w1[k].y == w2[k].y) p.y += 2*(w1[k].y - p.y);
	}

	static double intersection_time(Point a, Point v, int k) {
		boolean goX = (w1[k].x == w2[k].x && v.x != 0), goY = (w1[k].y == w2[k].y && v.y != 0);
		if (!goX && !goY) return -1;
		if (goX) {
			double t = (double)(w1[k].x - a.x) / v.x;
			double y = a.y + t*v.y;
			if (y < w1[k].y - 1e-9 || y > w2[k].y + 1e-9) return -1;
			return t;
		} else {
			double t = (double)(w1[k].y - a.y) / v.y;
			double x = a.x + t*v.x;
			if (x < w1[k].x - 1e-9 || x > w2[k].x + 1e-9) return -1;
			return t;
		}
	}

	static boolean cast_ray(int k) {

		Point vs = new Point(s), vt = new Point(t);
		for (int i = k-1; i >= 0; i--) reflect(vt,p[i]);
		if (vt.x == 0 && vt.y == 0) return false;

		double cur_time = 0;
		for (int i = 0; i <= k; i++) {
			Point dir = new Point(vt.x-vs.x,vt.y-vs.y);
			double next_time = intersection_time(vs,dir,p[i]);
			if (next_time < cur_time) return false;
			for (int j = i+1; j < n; j++) {
				double other_time = intersection_time(vs,dir,p[j]);
				if (other_time >= cur_time && other_time < next_time && p[j] != n-1) return false;
			}
			cur_time = next_time;
			reflect(vs,p[i]);
			reflect(vt,p[i]);
		}
		return true;
	}

	static int rec(int i) {
		if (i > 0 && p[i-1] == n-1) {
			int ii = 0;
			for (int j = i; j < n; j++) {
				while (used[ii]) ii++;
				p[j] = ii++;
			}
			if (cast_ray(i-1)) return i-1;
			else return -1;
		}
		int res = -1;
		for (p[i] = 0; p[i] < n; p[i]++) if (!used[p[i]]) {
			used[p[i]] = true;
			res = Math.max(res,rec(i+1));
			used[p[i]] = false;
		}
		return res;
	}


	public static void main(String[] args) {
	
		Locale.setDefault(new Locale("en", "US"));

		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		w1 = new Point[n+1];
		w2 = new Point[n+1];
		
		s = new Point(0,0);
		t = new Point(sc.nextInt(),sc.nextInt());

		for (int i = 0; i < n; i++) {
			w1[i] = new Point(sc.nextInt(),sc.nextInt());
			w2[i] = new Point(sc.nextInt(),sc.nextInt());
			int x1 = Math.min(w1[i].x,w2[i].x);
			int x2 = Math.max(w1[i].x,w2[i].x);
			int y1 = Math.min(w1[i].y,w2[i].y);
			int y2 = Math.max(w1[i].y,w2[i].y);
			w1[i].x = x1; w2[i].x = x2;
			w1[i].y = y1; w2[i].y = y2;
		}
		w1[n] = new Point(t);
		w2[n] = new Point(t);

		n++;
		p = new int[n];
		used = new boolean[n];
		
		int res = rec(0);
		if (res < 0) System.out.println("impossible");
		else System.out.println(res);

	}

}
