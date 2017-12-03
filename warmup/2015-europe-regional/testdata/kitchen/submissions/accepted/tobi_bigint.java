import java.util.*;
import java.io.*;
import java.math.*;

public class tobi_bigint {
	public static int R, S, M, D, N, K[] = new int[80], B[] = new int[1005], I[][] = new int[80][1005], l, r;
	public static boolean incompat[][] = new boolean[80][80];
	public static final BigInteger MAX = BigInteger.valueOf(1_000_000_000_000_000_000L);

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
		BigInteger ret = BigInteger.ZERO;
		for (int i = 0; i < S; i++) for (int j = S; j < S + M; j++) for (int k = S + M; k < S + M + D; k++) {
			if (incompat[i][j] || incompat[j][k] || incompat[i][k]) continue;
			HashSet<Integer> ings = new HashSet<>();
			int dishes[] = new int[] {i, j, k};
			for (int l = 0; l < 3; l++) {
				for (int m = 0; m < K[dishes[l]]; m++) ings.add(I[dishes[l]][m]);
			}
			BigInteger tmp = BigInteger.ONE;
			for (Integer it : ings) {
				tmp = tmp.multiply(BigInteger.valueOf(B[it-1]));
			}
			ret = tmp.add(ret);
		}
		if (MAX.compareTo(ret) < 0) System.out.println("too many");
		else System.out.println(ret);
	}
}
