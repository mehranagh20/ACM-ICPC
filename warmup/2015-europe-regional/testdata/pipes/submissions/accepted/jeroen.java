import java.util.*;
import java.io.*;

public class jeroen
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ps = in.readLine().split(" ");
		int W = Integer.valueOf(ps[0]);
		int P = Integer.valueOf(ps[1]);

		Point[] well = new Point[W];
		for (int i = 0; i < W; i++)
		{
			ps = in.readLine().split(" ");
			well[i] = new Point(Integer.valueOf(ps[0]), Integer.valueOf(ps[1]));
		}

		int[] s = new int[P];
		Point[] pipe = new Point[P];
		for (int i = 0; i < P; i++)
		{
			ps = in.readLine().split(" ");
			s[i] = Integer.valueOf(ps[0])-1;
			pipe[i] = new Point(Integer.valueOf(ps[1]), Integer.valueOf(ps[2]));
		}

		TwoSAT ts = new TwoSAT(P);
		for (int i = 0; i < P; i++)
		{
			for (int j = i + 1; j < P; j++)
			{
				if (s[i] == s[j]) continue;
				if (!Intersect(well[s[i]], pipe[i], well[s[j]], pipe[j])) continue;

				// One of the two must contain robot
				ts.AddClause(i + 1, j + 1);

				// But not both
				ts.AddClause(-i - 1, -j - 1);
			}
		}

		System.out.println(ts.Satisfiable() ? "possible" : "impossible");
	}


	/*** Prewritten code ***/
	public static class Point
	{
		public long X, Y;

		public Point(long x, long y)
		{
			X = x; Y = y;
		}
	}

	public static Point minus(Point A, Point B)
	{
		return new Point(A.X - B.X, A.Y - B.Y);
	}

	public static long cross(Point A, Point B)
	{
		return A.X * B.Y - A.Y * B.X;
	}

	/* Returns whether segments AB and CD intersect */
	public static boolean Intersect(Point A, Point B, Point C, Point D)
	{
		long num1 = cross(minus(D,C),minus(A,C));
		long num2 = cross(minus(B,A),minus(A,C));
		long denom = cross(minus(B,A),minus(D,C));
		if (denom < 0)
		{
			num1 *= -1;
			num2 *= -1;
			denom *= -1;
		}
		return 0 <= num1 && num1 <= denom && 0 <= num2 && num2 <= denom;
	}
}

class TwoSAT
{
	private int n;
	private Scc scc;

	public TwoSAT(int n)
	{
		this.n = n;
		this.scc = new Scc(2 * n);
	}

	// 1..n for true, -1..-n for false
	// adding clause v1 or v2
	public void AddClause(int v1, int v2)
	{
		scc.AddEdge(getNum(-v1), getNum(v2));
		scc.AddEdge(getNum(-v2), getNum(v1));
	}

	public boolean Satisfiable()
	{
		scc.FindComponents();
		for (int i = 1; i <= n; i++)
			if (scc.component[getNum(i)] == scc.component[getNum(-i)])
				return false;
		return true;
	}

	private int getNum(int num)
	{
		return num < 0 ? n - num - 1 : num - 1;
	}
}

class Scc
{
	public int n;
	public int[] component;
	public ArrayList<Integer>[] Neighbors, NeighborsR;
	private int[] order;
	private int order_num, actnum;

	public Scc(int n)
	{
		this.n = n;
		Neighbors = new ArrayList[n];
		NeighborsR = new ArrayList[n];
		for (int i = 0; i < n; i++)
		{
			Neighbors[i] = new ArrayList<Integer>();
			NeighborsR[i] = new ArrayList<Integer>();
		}
	}

	public void AddEdge(int i, int j)
	{
		Neighbors[i].add(j);
		NeighborsR[j].add(i);
	}

	public int FindComponents()
	{
		component = new int[n];
		order = new int[n];
		order_num = 0;

		for (int i = 0; i < n; i++)
			Dfs1(i);

		actnum = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (component[order[i]] == -1)
			{
				Dfs2(order[i]);
				actnum++;
			}
		}
		return actnum;
	}

	private void Dfs1(int i)
	{
		if (component[i] != 0) return;
		component[i] = -1;
		for (int adj : Neighbors[i])
			Dfs1(adj);
		order[order_num++] = i;
	}

	private void Dfs2(int i)
	{
		if (component[i] != -1) return;
		component[i] = actnum;
		for (int adj : NeighborsR[i])
			Dfs2(adj);
	}
}
