import java.util.*;
import java.io.*;

public class Lukas {
  static Kattio io = new Kattio(System.in, System.out);

  static int[] read(int n) {
    int[] res = new int[n];
    for (int i = 0; i < n; i++) {
      res[i] = io.getInt() - 1;
    }
    return res;
  }

  static long inversions(int[] a, int[] b) {
    int[] inv = new int[a.length];
    for (int  i = 0; i < a.length; i++)
      inv[a[i]] = i;

    long res = a.length * (long)(a.length - 1) / 2;

    FenwickTree t = new FenwickTree(a.length);
    for (int x : b) {
        res -= t.query(inv[x]);
        t.update(inv[x], 1);
    }

    return res;
  }

  public static void main(String args[]) {
    int n = io.getInt();
    int[] a = read(n);
    int[] b = read(n);
    int[] c = read(n);

    long inverse = inversions(a, b) + inversions(a, c) + inversions(b, c);
    long total = n * (long)(n - 1) / 2;
    System.out.println(total - inverse / 2);
  }
}

class FenwickTree {
  private int n;
  private double[] s;

  public FenwickTree(int n) {
    s = new double[n];
    this.n = n;
  }

  public void update(int pos, double difference) {
    for (; pos < n; pos |= pos + 1) {
      s[pos] += difference;
    }
  }

  public int query(int pos) {
    int count = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
        count += s[pos];
    return count;
  }
}

/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

class Kattio extends PrintWriter {
  public Kattio(InputStream i) {
    super(new BufferedOutputStream(System.out));
    r = new BufferedReader(new InputStreamReader(i));
  }
  public Kattio(InputStream i, OutputStream o) {
    super(new BufferedOutputStream(o));
    r = new BufferedReader(new InputStreamReader(i));
  }

  public boolean hasMoreTokens() {
    return peekToken() != null;
  }

  public int getInt() {
    return Integer.parseInt(nextToken());
  }

  public double getDouble() {
    return Double.parseDouble(nextToken());
  }

  public long getLong() {
    return Long.parseLong(nextToken());
  }

  public String getWord() {
    return nextToken();
  }

  private BufferedReader r;
  private String line;
  private StringTokenizer st;
  private String token;

  private String peekToken() {
    if (token == null)
      try {
        while (st == null || !st.hasMoreTokens()) {
          line = r.readLine();
          if (line == null) return null;
          st = new StringTokenizer(line);
        }
        token = st.nextToken();
      } catch (IOException e) { }
    return token;
  }

  private String nextToken() {
    String ans = peekToken();
    token = null;
    return ans;
  }
}
