import java.util.*;
import java.io.*;

public class tobi {
	public static int R, S, M, D, N, K[] = new int[80], B[] = new int[1005], I[][] = new int[80][1005], l, r;
	public static boolean incompat[][] = new boolean[80][80];
	public static final long MAX = 1_000_000_000_000_000_000L;

	public static boolean mult(long prod, long factor) {
		long neu = prod * factor;
		if (neu / factor == prod) {
			prod = neu;
			return true;
		}
		return false;
	}

	public static void main(String[] main) {
		Scanner sc = new Scanner(System.in);
		R = sc.nextInt();
		S = sc.nextInt();
		M = sc.nextInt();
		D = sc.nextInt();
		N = sc.nextInt();
		for (int i = 0; i < R; i++) B[i] = sc.nextInt();
		for (int i = 0; i < S+M+D; i++) {
			K[i] = sc.nextInt();
			for (int j = 0; j < K[i]; j++) I[i][j] = sc.nextInt();
		}
		for (int i = 0; i < N; i++) {
			l = sc.nextInt();
			r = sc.nextInt();
			incompat[l-1][r-1] = incompat[r-1][l-1] = true;
		}
		long ret = 0;
		boolean overflow = false;
		for (int i = 0; i < S; i++) for (int j = S; j < S + M; j++) for (int k = S + M; k < S + M + D; k++) {
			if (incompat[i][j] || incompat[j][k] || incompat[i][k]) continue;
			HashSet<Integer> ings = new HashSet<>();
			int dishes[] = new int[] {i, j, k};
			for (int l = 0; l < 3; l++) {
				for (int m = 0; m < K[dishes[l]]; m++) ings.add(I[dishes[l]][m]);
			}
			long tmp = 1;
			for (Integer it : ings) {
				if (!mult(tmp, B[it-1])) overflow = true;
				tmp *= B[it-1];
				if (tmp > MAX) overflow = true;
			}
			ret += tmp;
			if (ret > MAX) overflow = true;
		}
		if (overflow) System.out.println("too many");
		else System.out.println(ret);
	}
}
