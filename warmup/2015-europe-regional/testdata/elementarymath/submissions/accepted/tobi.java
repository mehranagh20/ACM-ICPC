import java.util.*;
import java.io.*;

public class tobi {
	public static ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
	public static HashMap<Long, Integer> notoint = new HashMap<>();
	public static int N, nodes, pred[] = new int[7505];
	public static long a[] = new long[2505];
       	public static long b[] = new long[2505];
	public static long idtores[] = new long[7505];
	public static long res[] = new long[2505];
	public static boolean[] mark = new boolean[7505];

	public static boolean match(int n) {
		if (n == -1) return true;
		for (int to : adj.get(n)) {
			if (mark[to]) continue;
			mark[to] = true;
			if (match(pred[to])) {
				pred[to] = n;
				return true;
			}
		}
		return false;
	}

	public static int maxmatch() {
		Arrays.fill(pred, -1);
		int ret = 0;
		for (int i = 0; i < N; i++) {
			Arrays.fill(mark, false);
			if (match(i)) ret++;
		}
		return ret;
	}

	public static int get(long x) {
		if (notoint.get(x) == null) {
			notoint.put(x, nodes++);
			idtores[notoint.get(x)] = x;
		}
		return notoint.get(x);
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 0; i < N; i++) adj.add(new ArrayList<Integer>());
		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			adj.get(i).add(get(a[i]+b[i]));
			adj.get(i).add(get(a[i]*b[i]));
			adj.get(i).add(get(a[i]-b[i]));
		}

		if (maxmatch() < N) System.out.println("impossible");
		else {
			for (int i = 0; i < nodes; i++) if (pred[i] >= 0) res[pred[i]] = idtores[i];
			for (int i = 0; i < N; i++) {
				char c = '+';
				if (a[i]*b[i] == res[i]) c = '*';
				else if (a[i]-b[i] == res[i]) c = '-';
				System.out.println(a[i] + "" + c  + "" + b[i] + "=" + res[i]);
			}
		}
	}
}
