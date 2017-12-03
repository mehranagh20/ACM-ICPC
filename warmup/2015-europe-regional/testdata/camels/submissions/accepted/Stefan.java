import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * This is a solution for the camels problem. First, we solve the problem for
 * two bets. For the first entry in the first bet we may find all camels that
 * have the same order to this one in both bets. This is the index of this camel
 * in the second bet since all camels are slower in the first one. We can then
 * remove this camel from both bets, repeat this process and sum up the
 * possibilities.
 * 
 * To do so we need a data structure that allows to find the current position of
 * an entry of a list and to remove items. We will add a binary tree above the
 * list where each node saves the size of its subtree. Finding the position can
 * be done by going up to the root and counting the elements on the left of the
 * path, deleting an item can be done by decreasing the size of all ancestors of
 * the node to be deleted. Therefore, this complete algorithm works in O(n log
 * n).
 * 
 * We can now compute the number of pairs of camels that are ranked in the same
 * order in all three pairs of bets. If a pair of camels is in the same order in
 * all bets we count this pair three times, otherwise we count it exactly once.
 * We can therefore subtract the number of pairs and the divide the result by
 * two to get the number that is asked for.
 * 
 * @author Stefan Toman (toman@tum.de)
 *
 */
public class Stefan {
	public static void main(String[] args) throws NumberFormatException, IOException {
		// read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		int[][] bets = new int[3][n];
		for (int i = 0; i < 3; i++) {
			String[] l = in.readLine().split(" ");
			for (int j = 0; j < n; j++) {
				bets[i][j] = Integer.parseInt(l[j]) - 1;
			}
		}

		// compute the problem for two pairs
		long sum = 0;
		sum += sameBets(bets[0], bets[1]);
		sum += sameBets(bets[0], bets[2]);
		sum += sameBets(bets[1], bets[2]);

		// compute the final answer
		sum -= (((long) n) * (n - 1)) / 2;
		sum /= 2;

		// print the result
		System.out.println(sum);
	}

	public static long sameBets(int[] bet1, int[] bet2) {
		// compute width of the tree
		int width = 1;
		while (width < bet2.length) {
			width *= 2;
		}

		// fill arrays
		int[] size = new int[2 * width - 1];
		int[] pos = new int[bet2.length];
		for (int i = 0; i < bet2.length; i++) {
			pos[bet2[i]] = width + i - 1;
			int t = pos[bet2[i]];
			size[t]++;
			while (t > 0) {
				t = (t - 1) / 2;
				size[t]++;
			}
		}

		// check all elements
		long ret = 0;
		for (int i = 0; i < bet1.length; i++) {
			int t = pos[bet1[i]];
			size[t]--;
			while (t > 0) {
				if (t % 2 == 1) {
					ret += size[t + 1];
				}
				t = (t - 1) / 2;
				size[t]--;
			}
		}

		return ret;
	}
}
