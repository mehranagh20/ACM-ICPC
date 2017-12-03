import java.util.*;
import java.io.*;
import java.awt.geom.Line2D.*;
import java.awt.geom.*;

public class tobi_Line2D {
	public static long W, P, sources[][] = new long[1000][2], pipes[] = new long[1000], color[] = new long[1000];
	public static ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
	public static Line2D.Double lines[] = new Line2D.Double[1000];

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
			lines[i] = new Line2D.Double(sources[(int)pipes[i]][0], sources[(int)pipes[i]][1], sc.nextLong(), sc.nextLong());
			adjList.add(new ArrayList<Integer>());
		}
		for (int i = 0; i < P; i++) for (int j = i+1; j < P; j++) {
			if (pipes[i] != pipes[j] && lines[i].intersectsLine(lines[j])) {
				adjList.get(i).add(j);
				adjList.get(j).add(i);
			}
		}
		boolean possible = true;
		for (int i = 0; i < P; i++) if (color[i] == 0) possible &= twoc(i,1);
		System.out.println(possible ? "possible" : "impossible");
	}
}
