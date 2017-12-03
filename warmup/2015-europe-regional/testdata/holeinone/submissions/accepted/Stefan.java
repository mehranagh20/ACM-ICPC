import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Solution for the trickshot problem. We brute force all subsets of walls to
 * hit, look at each order of them and check whether this order of walls is
 * valid. If so, we compute the corresponding number of points and print the
 * maximum. To find the direction to shoot we compute the sum of the distances
 * to the walls instead of computing the mirror image of the hole.
 * 
 * @author Stefan Toman (toman@tum.de)
 */
public class Stefan {
	public static int n, xh, yh;
	public static int[] xv, xw, yv, yw;
	public static boolean[] horizontal;
	public static int max = -1;

	public static void main(String[] args) throws IOException {
		// read the input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(in.readLine());
		String[] xhyh = in.readLine().split(" ");
		xh = Integer.parseInt(xhyh[0]);
		yh = Integer.parseInt(xhyh[1]);
		xv = new int[n];
		xw = new int[n];
		yv = new int[n];
		yw = new int[n];
		horizontal = new boolean[n];
		for (int i = 0; i < n; i++) {
			String[] line = in.readLine().split(" ");
			xv[i] = Integer.parseInt(line[0]);
			yv[i] = Integer.parseInt(line[1]);
			xw[i] = Integer.parseInt(line[2]);
			yw[i] = Integer.parseInt(line[3]);
			horizontal[i] = yv[i] == yw[i];
		}

		// compute all subsets
		subsets(n);

		// print output
		System.out.println(max == -1 ? "impossible" : max);
	}

	/**
	 * Compute all subsets of the integers from 0 to n-1. Call the function
	 * {@link Stefan#permutations(int[])} for each subset.
	 * 
	 * @param n
	 *            the number of items
	 */
	public static void subsets(int n) {
		for (int i = 0; i < 1 << n; i++) {
			int[] r = new int[Integer.bitCount(i)];
			int t = 0;
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) > 0) {
					r[t++] = j;
				}
			}
			permutations(r);
		}
	}

	/**
	 * Iterate over all permutations of an array using Heap's algorithm. Call
	 * the function {@link Stefan#check(int[])} for each permutation.
	 * 
	 * @param r
	 *            the array to permute
	 */
	public static void permutations(int[] r) {
		int[] c = new int[r.length];
		check(r);
		for (int i = 1; i < r.length;) {
			if (c[i] < i) {
				int s = i % 2 * c[i];
				int t = r[s];
				r[s] = r[i];
				r[i] = t;
				check(r);
				c[i]++;
				i = 1;
			} else {
				c[i++] = 0;
			}
		}
	}

	/**
	 * Check whether one order of walls works and adjust the maximum points
	 * {@link Stefan#max} in case.
	 * 
	 * @param r
	 *            the walls to hit
	 */
	public static void check(int[] r) {
		// compute the distance to move the ball
		int distx = 0, disty = 0, lastx = 0, lasty = 0;
		int dirx = 0, diry = 0;
		for (int i = 0; i < r.length; i++) {
			if (horizontal[r[i]]) {
				disty += Math.abs(lasty - yv[r[i]]);
				lasty = yv[r[i]];
				if (diry == 0) {
					diry = (int) Math.signum(yv[r[i]]);
				}
			} else {
				distx += Math.abs(lastx - xv[r[i]]);
				lastx = xv[r[i]];
				if (dirx == 0) {
					dirx = (int) Math.signum(xv[r[i]]);
				}
			}
		}
		distx += Math.abs(lastx - xh);
		disty += Math.abs(lasty - yh);

		// starting direction
		distx *= dirx == 0 ? Math.signum(xh) : dirx;
		disty *= diry == 0 ? Math.signum(yh) : diry;

		// check whether this path is valid
		double currentx = 0.0, currenty = 0.0, newx, newy;
		boolean[] wallremoved = new boolean[n];
		for (int i = 0; i < r.length; i++) {

			// avoid dividing by zero
			if (horizontal[r[i]] && disty == 0) return;
			if (!horizontal[r[i]] && distx == 0) return;

			// compute intersection
			if (horizontal[r[i]]) {
				newy = yv[r[i]];
				newx = currentx + (newy - currenty) * distx / disty;
			} else {
				newx = xv[r[i]];
				newy = currenty + (newx - currentx) * disty / distx;
			}

			// moving into wrong direction?
			if (disty * (newy - currenty) < 0 || distx * (newx - currentx) < 0) return;

			// next wall not hit?
			if (!between(xv[r[i]], newx, xw[r[i]]) || !between(yv[r[i]], newy, yw[r[i]])) return;

			// another wall hit?
			if (wallOnThePath(currentx, currenty, newx, newy, wallremoved, r[i])) return;

			// reset variables
			wallremoved[r[i]] = true;
			currentx = newx;
			currenty = newy;
			if (horizontal[r[i]]) {
				disty *= -1;
			} else {
				distx *= -1;
			}
		}

		// hole reachable?
		if (wallOnThePath(currentx, currenty, xh, yh, wallremoved, -1)) return;
		if (disty * (yh - currenty) < 0 || distx * (xh - currentx) < 0) return;

		// compute points
		int points =  r.length;
		if (max < points) {
			max = points;
		}
	}

	/**
	 * A helper function that checks whether a value is between two other values
	 * 
	 * @param a
	 *            one bound
	 * @param b
	 *            the value to check
	 * @param c
	 *            the other bound
	 * @return whether b is between a and c
	 */
	public static boolean between(double a, double b, double c) {
		return (a <= b && b <= c) || (c <= b && b <= a);
	}

	/**
	 * Check whether there is a wall between two points.
	 * 
	 * @param currentx
	 *            x-coordinate of the first point
	 * @param currenty
	 *            y-coordinate of the first point
	 * @param newx
	 *            x-coordinate of the second point
	 * @param newy
	 *            y-coordinate of the second point
	 * @param wallremoved
	 *            an array specifying the walls to ignore
	 * @param exclude
	 *            the index of a wall to ignore
	 * @return whether there is a wall between the points
	 */
	public static boolean wallOnThePath(double currentx, double currenty,
			double newx, double newy, boolean[] wallremoved, int exclude) {
		for (int j = 0; j < n; j++) {
			if (j != exclude && !wallremoved[j]) {
				if (horizontal[j]) {
					if (newy - currenty != 0) {
						double minv = ((double) (newx - currentx)) / (newy - currenty);
						double hitx = currentx + (yv[j] - currenty) * minv;
						if (between(currentx, hitx, newx)// correct direction
								&& between(currenty, yv[j], newy)// wall on the path
								&& between(xv[j], hitx, xw[j])// wall hit
						) return true;
					}
				} else {
					if (newx - currentx != 0) {
						double m = ((double) (newy - currenty)) / (newx - currentx);
						double hity = currenty + (xv[j] - currentx) * m;
						if (between(currenty, hity, newy)// correct direction
								&& between(currentx, xv[j], newx)// wall on the path
								&& between(yv[j], hity, yw[j])// wall hit
						) return true;
					}
				}
			}
		}
		return false;
	}
}
