import java.util.*;
import java.io.*;
import java.awt.geom.Line2D.*;
import java.awt.geom.*;

public class tobi2sat_dfs {
	public static long sources[][] = new long[1000][2], pipes[] = new long[1000], color[] = new long[1000], comp[] = new long[2000], C = 0;
	public static ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
	public static Line2D.Double lines[] = new Line2D.Double[1000];

	public static void dfs(int n, long c) {
		if (comp[n] != 0) return;
		comp[n] = c;
		for (int next : adjList.get(n)) dfs(next, c);
	}

	public static void add(int from, int to) {
		adjList.get(from).add(to);
		adjList.get(to).add(from);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int W = sc.nextInt();
		int P = sc.nextInt();
		for (int i = 0; i < W; i++) {
			sources[i][0] = sc.nextLong();
			sources[i][1] = sc.nextLong();
		}
		for (int i = 0; i < P; i++) {
			pipes[i] = sc.nextLong()-1;
			lines[i] = new Line2D.Double(sources[(int)pipes[i]][0], sources[(int)pipes[i]][1], sc.nextLong(), sc.nextLong());
			adjList.add(new ArrayList<Integer>()); adjList.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < P; i++) for (int j = i+1; j < P; j++) {
			if (pipes[i] != pipes[j] && lines[i].intersectsLine(lines[j])) {
				add(i, P+j);
				add(j, P+i);
			}
		}
		for (int i = 0; i < P; i++) if (comp[i] == 0) dfs(i, ++C);
		boolean possible = true;
		for (int i = 0; i < P; i++) if (comp[i] == comp[P+i]) possible = false;
		System.out.println(possible ? "possible" : "impossible");
	}
}
