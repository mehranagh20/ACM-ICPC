// Ported to Java by Jeroen
import java.util.*;
import java.io.*;

public class per
{
	static int n;
	static int[] a, x, y, bp, cp;
	static bit[] T;
	static Integer[] pts;

	static Comparator<Integer> y_less = new Comparator<Integer>() { public int compare(Integer i, Integer j) { return y[i] - y[j]; } };
	static Comparator<Integer> x_less = new Comparator<Integer>() { public int compare(Integer i, Integer j) { return x[i] - x[j]; } };

	static <T> int lower_bound(T[] a, T key, Comparator<? super T> c) {
		int res = Arrays.binarySearch(a, key, c);
		if(res < 0) res = -res - 1;
		return res;
	}

	static class bit {
		Integer[] pts;
		int[] cnt;
		
		public bit(Integer[] pts) {
			this.pts = pts;
			this.cnt = new int[pts.length];
			Arrays.sort(pts, y_less);
		}
		int find(int p) {
			return lower_bound(pts, p, y_less);
		}
		void add(int p) {
			for (int i = find(p); i < pts.length; i += (i+1) & -(i+1)) ++cnt[i];
		}
		int get(int p) {
			int res = 0;
			for (int i = find(p)-1; i >= 0; i -= (i+1) & -(i+1)) res += cnt[i];
			return res;
		}
	}


	static void init() {
		pts = new Integer[n];
		T = new bit[n+1];
		for (int i = 0; i < n; ++i) pts[i] = i;
		Arrays.sort(pts, x_less);
		for (int e = 1; e <= n; ++e) T[e-1] = new bit(Arrays.copyOfRange(pts, e - (e&-e), e));
	}
	
	static int find(int p) {
		return lower_bound(pts, p, x_less);
	}
	
	static void add(int p) {
		for (int i = find(p); i < n; i += (i+1) & -(i+1)) T[i].add(p);
	}
	
	static int get(int p) {
		int res = 0;
		for (int i = find(p)-1; i >= 0; i -= (i+1) & -(i+1)) res += T[i].get(p);
		return res;
	}
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(in.readLine());
		a = readArray(in);
		x = readArray(in);
		y = readArray(in);
		bp = new int[n+1];
		cp = new int[n+1];
		
		for (int i = 0; i < n; ++i) bp[x[i]] = i;
		for (int i = 0; i < n; ++i) cp[y[i]] = i;
		for (int i = 0; i < n; ++i) { x[i] = bp[a[i]]; y[i] = cp[a[i]]; }
		long ans = 0;
		init();
		for (int i = 0; i < n; add(i), ans += get(i), ++i);
		System.out.println(ans);
	}
	
	public static int[] readArray(BufferedReader in) throws IOException {
		String[] ss = in.readLine().split(" ");
		int[] ret = new int[ss.length];
		for(int i = 0; i < ss.length; i++)
			ret[i] = Integer.parseInt(ss[i]);
		return ret;
	}
}
