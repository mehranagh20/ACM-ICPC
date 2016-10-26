import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        final int MAX = 10000;
        double[] memo = new double[MAX + 1];
        memo[0] = 1;
        for (int i = 1; i <= MAX; i++) {
            memo[i] = memo[i - 1];
            if (BigInteger.valueOf(i * i + i + 41).isProbablePrime(10))
                memo[i]++;
        }

        Scanner sc = new Scanner(System.in);
        int a, b;
        while (sc.hasNextInt()) {
            a = sc.nextInt();
            b = sc.nextInt();
            System.out.println(String.format("%.2f", (memo[b] - (a > 0 ? memo[a - 1] : 0)) * 100 / (b - a + 1)));
        }
    }
}
