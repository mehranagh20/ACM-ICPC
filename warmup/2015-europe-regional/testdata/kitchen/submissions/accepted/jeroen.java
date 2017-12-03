import java.util.*;
import java.io.*;

public class jeroen {
	private static final long MAX = 1000000000000000000L;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int r = sc.nextInt();
		int s = sc.nextInt();
		int m = sc.nextInt();
		int d = sc.nextInt();
		int n = sc.nextInt();
		
		int[] b = new int[r];
		for(int i = 0; i < r; i++) b[i] = sc.nextInt();
		List<Integer>[] dish = new ArrayList[s+m+d];
		for(int i = 0; i < s+m+d; i++) {
			int k = sc.nextInt();
			dish[i] = new ArrayList<Integer>();
			for(int j = 0; j < k; j++)
				dish[i].add(sc.nextInt() - 1);
		}
		boolean[][] inc = new boolean[s+m+d][s+m+d];
		for(int i = 0; i < n; i++) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			inc[x][y] = inc[y][x] = true;
		}
		long ret = 0;
		for(int i = 0; i < s; i++) {
			for(int j = s; j < s + m; j++) {
				if(inc[i][j]) continue;
				for(int k = s + m; k < s + m + d; k++) {
					if(inc[i][k] || inc[j][k]) continue;
					TreeSet<Integer> ingredients = new TreeSet<Integer>();
					for(Integer ing : dish[i]) ingredients.add(ing);
					for(Integer ing : dish[j]) ingredients.add(ing);
					for(Integer ing : dish[k]) ingredients.add(ing);
					long poss = 1;
					for(Integer ing : ingredients)
						poss = safeMult(poss, b[ing]);
					ret = Math.min(MAX+1, ret + poss);
				}
			}
		}
		if(ret > MAX)
			System.out.println("too many");
		else
			System.out.println(ret);
	}
	
	private static long safeMult(long a, long b) {
		if(b > MAX / a) return MAX + 1;
		long ret = a * b;
		if(ret < 0 || ret > MAX) return MAX + 1;
		return ret;
	}
}