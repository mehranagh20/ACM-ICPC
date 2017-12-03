import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collections;

/**
 * This is a solution for the productivity problem. We first solve the problem
 * for an easier version assuming that no interval contains another interval.
 * This means that after sorting the intervals by the arrival time they are also
 * sorted by the leaving time (otherwise an interval would contain another one).
 * If two intervals are on the same machine then all intervals between them (in
 * sorted order) should be on that machine, too, to maximize productivity. Now
 * the problem is to decide where the p-1 cuts between the machines should be
 * placed between the n intervals which can be solved by dynamic programming.
 * The dp array saves the best value for a given number of machines used and the
 * last worker involved.
 * 
 * To use this special case we split the set of intervals into all intervals
 * that contain another interval and the rest. The rest is solved as described
 * above. The remaining intervals can be added to the dp-distribution of workers
 * without changing their productivity by putting each worker to a machine where
 * another worker with contained interval is placed. It is never useful to add
 * them to other machines in this distribution.
 * 
 * It can improve the productivity if some of the workers with intervals that
 * contain others are placed at separate machines. Here, it is never useful to
 * add other workers to these machines, they always work alone to be as
 * productive as possible. Therefore, we should always take the ones with
 * maximum interval length first.
 * 
 * We can combine both types of machines by checking all up to p possibilities
 * to distribute the machines between both types of workers. The maximum of
 * these possibilities is printed in the end.
 * 
 * @author Stefan Toman (toman@tum.de)
 *
 */
public class Stefan {
	public static void main(String[] args) throws IOException {
		// read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] np = in.readLine().split(" ");
		int n = Integer.parseInt(np[0]), p = Integer.parseInt(np[1]);
		ArrayList<Interval> containing = new ArrayList<Interval>(), noncontaining = new ArrayList<Interval>();
		for (int i = 0; i < n; i++) {
			String[] ab = in.readLine().split(" ");
			int a = Integer.parseInt(ab[0]), b = Integer.parseInt(ab[1]);
			noncontaining.add(new Interval(a, b));
		}

		// check whether an interval contains another one and add the
		// interval to the corresponding set of intervals
		outer: for (Interval x : noncontaining) {
			for (Interval t : noncontaining) {
				if (x != t && x.a <= t.a && t.b <= x.b && !containing.contains(t)) {
					containing.add(x);
					continue outer;
				}
			}
		}
		noncontaining.removeAll(containing);

		// sort the sets: noncontaining by a (and b), containing by interval
		// length
		Collections.sort(noncontaining, new Comparator<Interval>() {
			public int compare(Interval x, Interval y) {
				return x.a - y.a;
			}
		});
		Collections.sort(containing, new Comparator<Interval>() {
			public int compare(Interval x, Interval y) {
				return (x.a - x.b) - (y.a - y.b);
			}
		});

		// dynamic programming on noncontaining
		int[][] dp = new int[p][noncontaining.size()];
		for (int j = 0; j < noncontaining.size(); j++) {
			dp[0][j] = Math.max(0, noncontaining.get(0).b - noncontaining.get(j).a);
		}
		for (int i = 1; i < p; i++) {
			for (int j = 0; j < noncontaining.size(); j++) {
				for (int k = 0; k < j; k++) {
					int v = dp[i - 1][k] + noncontaining.get(k + 1).b - noncontaining.get(j).a;
					if (v > dp[i][j] && v > dp[i - 1][k] && dp[i - 1][k] > 0) {
						dp[i][j] = v;
					}
				}
			}
		}

		// check all possibilities to distribute the machines
		int max = dp[p - 1][noncontaining.size() - 1];
		int containingLength = 0;
		for (int i = 0; i < Math.min(p - 1, containing.size()); i++) {
			containingLength += containing.get(i).b - containing.get(i).a;
			int v = dp[p - i - 2][noncontaining.size() - 1] + containingLength;
			if (max < v && dp[p - i - 2][noncontaining.size() - 1] > 0) {
				max = v;
			}
		}

		// print result
		System.out.println(max);
	}

	static class Interval {
		int a, b;

		public Interval(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}
}
