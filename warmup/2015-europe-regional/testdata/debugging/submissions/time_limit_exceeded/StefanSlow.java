import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * This is a solution for the debugging problem. It computes the time in
 * question for all numbers of code lines starting at 1 and growing this number.
 * For each number of lines we check all possibilities to add printf statements
 * (just the number is important, they need to be distributed uniformly) and
 * compute the resulting time using the results for smaller numbers of lines.
 * 
 * This submissions should be slow since it computes the result for all numbers
 * of lines of code instead of just the ones needed.
 * 
 * @author Stefan Toman (toman@tum.de)
 *
 */
public class StefanSlow {
	public static void main(String[] args) throws IOException {
		// read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] nrp = in.readLine().split(" ");
		int n = Integer.parseInt(nrp[0]);
		long r = Long.parseLong(nrp[1]);
		long p = Long.parseLong(nrp[2]);

		// compute times for all code lengths
		long[] time = new long[n + 1];
		Arrays.fill(time, Long.MAX_VALUE);
		time[0] = 0;
		time[1] = 0;
		for (int i = 1; i < time.length; i++) {
			int s = (int) Math.sqrt(i);
			// check all numbers of printf statements
			for (int j = 1; j <= s; j++) {
				time[i] = Math.min(time[i], r + p * j + time[1 + (i - 1) / (j + 1)]);
			}
			// for j > sqrt(i) the number 1 + (i - 1) / (j + 1) changes rarely.
			// We only take the ones that do something interesting from here.
			// k is the number of lines per code block after splitting it
			for (int k = 1; k <= s; k++) {
				time[i] = Math.min(time[i], r + p * (i - 1) / k + time[k]);
			}
		}

		// print result
		System.out.println(time[n]);
	}
}
