import java.util.*;
import java.io.*;

public class tobi {
	public static long W, P, sources[][] = new long[1000][2], endp[][] = new long[1000][2], pipes[] = new long[1000], color[] = new long[1000];
	public static ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();

	public static long ccw(long[] a, long[] b, long[] p) {
		long c = (b[0] - a[0]) * (p[1] - a[1]) - (p[0] - a[0]) * (b[1] - a[1]);
		return (c == 0 ? 0 : (c > 0) ? 1 : -1);
	}

	public static boolean intersects(long[] S, long[] T, long[] A, long[] B) {
		return ccw(A,B,S) * ccw(A,B,T) <= 0;
	}

	public static boolean intersects2(long[] S, long[] T, long[] A, long[] B) {
		return intersects(S, T, A, B) && intersects(A, B, T, S);
	}

	public static boolean twoc(int pipe, int curCol) {
		if (color[pipe] != 0) return color[pipe] == curCol;
		color[pipe] = curCol;
		for (int next : adjList.get(pipe)) if (!twoc(next, -1*curCol)) return false;
		return true;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		W = sc.nextLong();
		P = sc.nextLong();
		for (int i = 0; i < W; i++) {
			sources[i][0] = sc.nextLong();
			sources[i][1] = sc.nextLong();
		}
		for (int i = 0; i < P; i++) {
			pipes[i] = sc.nextLong()-1;
			endp[i][0] = sc.nextLong();
			endp[i][1] = sc.nextLong();
			adjList.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < P; i++) for (int j = i+1; j < P; j++) {
			if (pipes[i] != pipes[j] && intersects2(sources[(int)pipes[i]], endp[i], sources[(int)pipes[j]], endp[j])) {
				adjList.get(i).add(j);
				adjList.get(j).add(i);
			}
		}
		boolean possible = true;
		for (int i = 0; i < P; i++) if (color[i] == 0) possible &= twoc(i,1);
		System.out.println(possible ? "possible" : "impossible");
	}
}
