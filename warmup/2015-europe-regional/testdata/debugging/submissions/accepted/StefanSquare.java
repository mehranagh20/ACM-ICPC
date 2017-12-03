import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * This is a solution for the debugging problem. It computes the time in
 * question for all numbers of code lines starting at 1 and growing this number.
 * These results are only computed when they are needed to avoid unnecessary
 * computations. For each number of lines we check all possibilities to add
 * printf statements (just the number is important, they need to be distributed
 * uniformly) and compute the resulting time using the results for smaller
 * numbers of lines.
 * 
 * @author Stefan Toman (toman@tum.de)
 *
 */
public class StefanSquare {
	public static long[] time;
	public static long r, p;

	public static void main(String[] args) throws IOException {
		// read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] nrp = in.readLine().split(" ");
		int n = Integer.parseInt(nrp[0]);
		r = Long.parseLong(nrp[1]);
		p = Long.parseLong(nrp[2]);

		// compute times for all code lengths
		time = new long[n + 1];
		Arrays.fill(time, Long.MAX_VALUE);
		time[0] = 0;
		time[1] = 0;
		computeTime(n);

		// print result
		System.out.println(time[n]);
	}

	private static void computeTime(int i) {
		// check all numbers of printf statements
		for (int j = 1; j <= i-1; j++) {
			int blocklength = 1 + (i - 1) / (j + 1);
			if (time[blocklength] == Long.MAX_VALUE) {
				computeTime(blocklength);
			}
			time[i] = Math.min(time[i], r + p * j + time[blocklength]);
		}
	}
}
