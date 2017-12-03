import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * This is a submission for the flight problem. There is no interesting
 * algorithm here: We just compute all the intersections and sum up the lengths
 * of the arcs.
 * 
 * @author Stefan Toman (toman@tum.de)
 *
 */
public class Stefan {
	public static Point comparatorPoint;

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		// open input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		// read continents
		int c = Integer.parseInt(in.readLine());
		Point[][] continents = new Point[c][];
		for (int i = 0; i < c; i++) {
			String[] t = in.readLine().split(" ");
			int n = Integer.parseInt(t[0]);
			continents[i] = new Point[n + 1];
			for (int j = 0; j < n; j++) {
				continents[i][j] = new Point(Integer.parseInt(t[2 * j + 1]),
						Integer.parseInt(t[2 * j + 2]));
			}
			continents[i][n] = continents[i][0];
		}

		// read route
		String[] t = in.readLine().split(" ");
		int m = Integer.parseInt(t[0]);
		Point[] route = new Point[m];
		for (int j = 0; j < m; j++) {
			route[j] = new Point(Integer.parseInt(t[2 * j + 1]),
					Integer.parseInt(t[2 * j + 2]));
		}

		// iterate over route segments
		double l = 0;
		double w = 0;
		boolean land = true;
		for (int i = 0; i + 1 < route.length; i++) {
			// update total distance
			l += route[i].distArc(route[i + 1]);
			// compute intersections with borders
			comparatorPoint = route[i];
			PriorityQueue<Point> q = new PriorityQueue<Point>(1,
					new Comparator<Point>() {
						public int compare(Point o1, Point o2) {
							return (int) Math.signum(o1
									.distArc(comparatorPoint)
									- o2.distArc(comparatorPoint));
						}
					});
			for (int j = 0; j < continents.length; j++) {
				for (int k = 0; k < continents[j].length - 1; k++) {
					Point intersection = Point.intersection(route[i],
							route[i + 1], continents[j][k],
							continents[j][k + 1]);
					if (intersection != null) {
						q.add(intersection);
					}
				}
			}
			// go through intersections
			Point lastPoint = route[i];
			while(!q.isEmpty()) {//thanks for the hint, Per
				Point p = q.poll();
				if (!land) {
					w += lastPoint.distArc(p);
				}
				land = !land;
				lastPoint = p;
			}
			if (!land) {
				w += lastPoint.distArc(route[i + 1]);
			}
		}

		// print result
		System.out.println(l * 6370 + " " + 100 * w / l);
	}

	static class Point {
		double x, y, z;

		public Point(double x, double y, double z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public Point(double lat, double lon) {
			x = Math.cos(lon) * Math.cos(lat);
			y = Math.sin(lon) * Math.cos(lat);
			z = Math.sin(lat);
		}

		public Point(int lat, int lon) {
			this(Math.PI * lat / 180, Math.PI * lon / 180);
		}

		public Point cross(Point a) {
			return new Point(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y
					* a.x);
		}

		public double distArc(Point b) {
			return 2 * Math.asin(distLine(b) / 2);
		}

		public double distLine(Point b) {
			return new Point(x - b.x, y - b.y, z - b.z).getLength();
		}

		public static Point intersection(Point a1, Point a2, Point b1, Point b2) {
			Point p = a1.cross(a2).cross(b1.cross(b2)).normalize();
			if (!p.between(a1, a2)) {
				p = new Point(-p.x, -p.y, -p.z);
			}
			if (!p.between(a1, a2) || !p.between(b1, b2)) {
				return null;
			}
			return p;
		}

		public Point normalize() {
			double l = getLength();
			return new Point(x / l, y / l, z / l);
		}

		public double getLength() {
			return Math.sqrt(x * x + y * y + z * z);
		}

		public boolean between(Point a, Point b) {
			return Math.abs(distArc(a) + distArc(b) - a.distArc(b)) <= 1e-8;
		}
	}
}
