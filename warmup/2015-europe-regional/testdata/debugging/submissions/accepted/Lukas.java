import java.util.*;
import java.io.*;

public class Lukas {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int t = sc.nextInt();
    int c = sc.nextInt();

    long[] best = new long[2 * n];
    Arrays.fill(best, 1L<<60);
    best[1] = 0;
    for (int i = 1; i < best.length; i++)
    {
        for (int j = 2; j * i < best.length; j++)
            best[j * i] = Math.min(best[j * i], best[i] + (long)(j - 1) * c + t);
    }

    long ma = best[n];
    for (int i = n + 1; i < best.length; i++)
      ma = Math.min(ma, best[i]);
    System.out.println(ma);
  }
}
