import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * This is a sample solution for the kitchen problem. We simply brute force all
 * possibilities and sum them up.
 * 
 * @author Stefan Toman (toman@tum.de)
 *
 */
public class Stefan {
	public static long max = 1000000000000000000l;

	public static void main(String[] args) throws IOException {
		// read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] rsmdn = in.readLine().split(" ");
		int r = Integer.parseInt(rsmdn[0]);
		int s = Integer.parseInt(rsmdn[1]);
		int m = Integer.parseInt(rsmdn[2]);
		int d = Integer.parseInt(rsmdn[3]);
		int n = Integer.parseInt(rsmdn[4]);

		int[] b = new int[r + 1];
		b[0] = 1;// ingredient 0 <=> not used
		String[] bs = in.readLine().split(" ");
		for (int i = 0; i < r; i++) {
			b[i + 1] = Integer.parseInt(bs[i]);
		}

		int[][] ingredients = new int[s + m + d][20];
		for (int i = 0; i < s + m + d; i++) {
			String[] is = in.readLine().split(" ");
			for (int j = 1; j < is.length; j++) {
				ingredients[i][j - 1] = Integer.parseInt(is[j]);
			}
		}

		boolean[][] incompatible = new boolean[s + m + d][s + m + d];
		for (int i = 0; i < n; i++) {
			String[] ds = in.readLine().split(" ");
			int x = Integer.parseInt(ds[0]) - 1;
			int y = Integer.parseInt(ds[1]) - 1;
			incompatible[x][y] = true;
			incompatible[y][x] = true;
		}

		// try all combinations
		long nr = 0;
		for (int x = 0; x < s; x++) {
			for (int y = s; y < s + m; y++) {
				if (incompatible[x][y])
					continue;
				for (int z = s + m; z < s + m + d; z++) {
					if (incompatible[x][z] || incompatible[y][z])
						continue;
					long p = 1;
					boolean[] added = new boolean[r + 1];
					for (int i = 0; i < 20; i++) {
						if (!added[ingredients[x][i]]) {
							if (b[ingredients[x][i]] > max / p + 1)
								tooMany();
							added[ingredients[x][i]] = true;
							p *= b[ingredients[x][i]];
						}
						if (!added[ingredients[y][i]]) {
							if (b[ingredients[y][i]] > max / p + 1)
								tooMany();
							added[ingredients[y][i]] = true;
							p *= b[ingredients[y][i]];
						}
						if (!added[ingredients[z][i]]) {
							if (b[ingredients[z][i]] > max / p + 1)
								tooMany();
							added[ingredients[z][i]] = true;
							p *= b[ingredients[z][i]];
						}
					}
					nr += p;
					if (nr > max)
						tooMany();
				}
			}
		}
		System.out.println(nr);
	}

	public static void tooMany() {
		System.out.println("too many");
		System.exit(0);
	}
}
