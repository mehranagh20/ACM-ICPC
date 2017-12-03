import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * This is a solution to the encryption problem. It translates the input numbers
 * to boolean arrays and reconstructs the array entries. Afterwards, the result
 * is summed up. This is probably slow.
 * 
 * @author Stefan Toman (toman@tum.de)
 */
public class Stefan {
	public static void main(String[] args) throws IOException {
		// read the input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		String[] tmp = in.readLine().split(" ");

		// iterate over the numbers
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			int b = Integer.parseInt(tmp[i]);

			// read to bits array
			boolean[] bits = new boolean[8];
			for (int j = 0; j < bits.length; j++) {
				bits[j] = b % 2 == 1;
				b /= 2;
			}

			// transform to answer
			boolean[] rbits = new boolean[8];
			rbits[0] = bits[0];
			for (int j = 1; j < rbits.length; j++) {
				rbits[j] = bits[j] ^ rbits[j - 1];
			}

			// add result to answer
			int r = 0;
			int pot = 1;
			for (int j = 0; j < bits.length; j++) {
				if (rbits[j]) {
					r += pot;
				}
				pot *= 2;
			}
			sb.append(r);
			if (i < n - 1) {
				sb.append(' ');
			}
		}

		// print all numbers
		System.out.println(sb);
	}
}

