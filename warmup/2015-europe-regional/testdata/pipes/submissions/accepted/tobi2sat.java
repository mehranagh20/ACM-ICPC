import java.util.*;
import java.io.*;
import java.awt.geom.Line2D.*;
import java.awt.geom.*;

public class tobi2sat {
	public static long sources[][] = new long[1000][2], pipes[] = new long[1000], color[] = new long[1000], comp[] = new long[2000];
	public static ArrayList<ArrayList<Integer>> adjList = new ArrayList<>(), adjListRev = new ArrayList<>();
	public static Line2D.Double lines[] = new Line2D.Double[1000];
	public static ArrayList<Integer> sorted = new ArrayList<>();

	public static void dfs(int n, int dir, int c) {
		if (comp[n] != -1) return;
		comp[n] = c;
		ArrayList<Integer> adj = dir == 0 ? adjList.get(n) : adjListRev.get(n);
		for (int next : adj) dfs(next, dir, c);
		if (dir == 0) sorted.add(n);
	}

	public static void scc(int P) {
		Arrays.fill(comp, -1);
		for (int i = 0; i < P*2; i++) if (comp[i] == -1) dfs(i, 0, 0);
		Arrays.fill(comp, -1);
		Collections.reverse(sorted);
		int C = 0;
		for (int next : sorted) if (comp[next] == -1) dfs(next, 1, C++);
	}

	public static void add(int from, int to) {
		adjList.get(from).add(to);
		adjListRev.get(from).add(to);
		adjList.get(to).add(from);
		adjListRev.get(to).add(from);
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
			adjListRev.add(new ArrayList<Integer>()); adjListRev.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < P; i++) for (int j = i+1; j < P; j++) {
			if (pipes[i] != pipes[j] && lines[i].intersectsLine(lines[j])) {
				add(i, P+j);
				add(j, P+i);
			}
		}
		scc(P);
		boolean possible = true;
		for (int i = 0; i < P; i++) if (comp[i] == comp[P+i]) possible = false;
		System.out.println(possible ? "possible" : "impossible");
	}
}
