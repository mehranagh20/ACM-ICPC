import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int test = 0; test < t; test++) {
			String x = sc.next();
			String z = sc.next();
			BigInteger[][] dp = new BigInteger[10001][101];
			for (int i = 0; i <= x.length(); i++)
				for (int j = 0; j <= z.length(); j++)
					dp[i][j] = BigInteger.ZERO;

			dp[0][0] = BigInteger.ZERO;
			for (int i = 1; i <= x.length(); i++)
				dp[i][0] = BigInteger.ONE;

			for (int i = 1; i <= x.length(); i++)
				for (int j = 1; j <= z.length(); j++) {
					if (i < j)
						continue;
					if (x.charAt(i - 1) == z.charAt(j - 1)) {
						dp[i][j] = dp[i - 1][j - 1].add(dp[i - 1][j]);
						if (dp[i][j] == BigInteger.ZERO && j == 1)
							dp[i][j] = BigInteger.ONE;
					} else {
						dp[i][j] = dp[i - 1][j];
					}
				}

			// for (int i = 0; i <= x.length(); i++) {
			// 	for (int j = 0; j <= z.length(); j++)
			// 		System.out.print(dp[i][j] + " ");
			// 	System.out.println();
			// }
			System.out.println(dp[x.length()][z.length()]);
		}
    }
}
