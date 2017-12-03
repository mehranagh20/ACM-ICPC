import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/**
 * This is a solution to the pipes problem. It uses the fact that cleaning the
 * pipes is possible iff there is no cycle of pipes of odd length such that each
 * neighbouring pipes intersect in a point that is not a well. To compute this
 * we intersect all pipes first using projective geometry. Then we find cycles
 * off odd length by a simple BFS.
 * 
 * @author Stefan Toman (toman@tum.de)
 */
public class Stefan {
	public static void main(String[] args) throws IOException {
		// read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] wp = in.readLine().split(" ");
		int w = Integer.parseInt(wp[0]);
		int p = Integer.parseInt(wp[1]);

		// wells
		Point[] pw = new Point[w];
		for (int i = 0; i < w; i++) {
			String[] wxwy = in.readLine().split(" ");
			pw[i] = new Point(wxwy[0], wxwy[1]);
		}

		// pipes
		int[] s = new int[p];
		Point[] pp = new Point[p];// the end points of the pipes
		Point[] ppl = new Point[p];// the pipes themselves
		for (int i = 0; i < p; i++) {
			String[] sxy = in.readLine().split(" ");
			s[i] = Integer.parseInt(sxy[0])-1;
			pp[i] = new Point(sxy[1], sxy[2]);
			ppl[i] = pp[i].cross(pw[s[i]]);
		}

		// compute intersections
		boolean[][] intersects = new boolean[p][p];
		for (int i = 0; i < p; i++) {
			for (int j = i + 1; j < p; j++) {
				if (s[i] != s[j]) {
					Point intersection = ppl[i].cross(ppl[j]);
					if (intersection.between(pp[i], pw[s[i]]) && intersection.between(pp[j], pw[s[j]])) {
						intersects[i][j] = true;
						intersects[j][i] = true;
					}
				}
			}
		}

		// compute whether there are odd cycles
		boolean[] visited = new boolean[p];
		boolean[] even = new boolean[p];
		for (int i = 0; i < p; i++) {
			if (!visited[i]) {
				Queue<Integer> q = new LinkedList<Integer>();
				q.add(i);
				visited[i] = true;
				while (!q.isEmpty()) {
					int t = q.poll();
					for (int j = 0; j < p; j++) {
						if (intersects[t][j]) {
							if (!visited[j]) {
								even[j] = !even[t];
								q.add(j);
								visited[j] = true;
							} else if (even[t] == even[j]) {
								System.out.println("impossible");
								System.exit(0);
							}
						}
					}
				}
			}
		}
		System.out.println("possible");
	}

	// a point in RP^3
	static class Point {
		long x, y, z;

		public Point(long x, long y, long z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public Point(String x, String y) {
			this.x = Long.parseLong(x);
			this.y = Long.parseLong(y);
			this.z = 1;
		}

		public Point cross(Point a) {
			return new Point(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
		}

		public boolean between(Point a, Point b) {
			return between(z * a.x * b.z, x * a.z * b.z, z * a.z * b.x)
					&& between(z * a.y * b.z, y * a.z * b.z, z * a.z * b.y);
		}

		public static boolean between(long a, long x, long b) {
			return (a <= x && x <= b) || (a >= x && x >= b);
		}
	}
}
