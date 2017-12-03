import java.util.*;
import java.io.*;

public class jeroen_arraylist
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		// Read input
		int n = Integer.valueOf(in.readLine());
		long[] a = new long[n];
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
		{
			String[] ps = in.readLine().split(" ");
			a[i] = Long.valueOf(ps[0]);
			b[i] = Long.valueOf(ps[1]);
		}

		// Compute possible answers
		int numAns = 0;
		HashSet<Long>[] anss = new HashSet[n];
		Map<Long, Integer> idx = new HashMap<Long, Integer>();
		for (int i = 0; i < n; i++)
		{
			anss[i] = new HashSet<Long>();
			anss[i].add(a[i] + b[i]);
			anss[i].add(a[i] - b[i]);
			anss[i].add(a[i] * b[i]);
			for (long ans : anss[i])
				if (!idx.containsKey(ans))
					idx.put(ans, numAns++);
		}

		// Create matching problem using generic max flow code
		MaxFlow mf = new MaxFlow(n + numAns);
		for (int i = 0; i < n; i++)
		{
			mf.Add(mf.Source, i, 1);
			for (long ans : anss[i])
				mf.Add(i, n + idx.get(ans), 1);
		}
		for (int i = 0; i < numAns; i++)
			mf.Add(n + i, mf.Sink, 1);

		// Is the problem solvable?
		if (mf.NetworkFlow() != n)
		{
			System.out.print("IMPOSSIBLE");
			return;
		}

		// Solvable, construct the output
		for (int i = 0; i < n; i++)
		{
			long res = -1;
			char op = '#';
			if (mf.Flow[i][n + idx.get(a[i] + b[i])] == 1)
			{
				op = '+';
				res = a[i] + b[i];
			}
			else if (mf.Flow[i][n + idx.get(a[i] - b[i])] == 1)
			{
				op = '-';
				res = a[i] - b[i];
			}
			else if (mf.Flow[i][n + idx.get(a[i] * b[i])] == 1)
			{
				op = '*';
				res = a[i] * b[i];
			}
			else
			{
				throw new Exception("The impossible happened.");
			}
			System.out.print(String.format(" %d %c %d = %d", a[i], op, b[i], res));
		}
	}
}

class MaxFlow
{
	public int Nodes;
	public int Source;
	public int Sink;
	public int[][] Capacity;
	ArrayList<Integer>[] Neighbours;
	boolean[][] NeighbourAdded;
	public int[][] Flow;

	public MaxFlow(int Nodes)
	{
		this.Nodes = Nodes + 2;
		this.Source = Nodes;
		this.Sink = Nodes + 1;
		Neighbours = new ArrayList[this.Nodes];
		for (int i = 0; i < this.Nodes; i++)
			Neighbours[i] = new ArrayList<Integer>();
		Capacity = new int[this.Nodes][this.Nodes];
		NeighbourAdded = new boolean[this.Nodes][this.Nodes];
	}

	public void Add(int From, int To, int Cap)
	{
		Capacity[From][To] += Cap;
		if (!NeighbourAdded[From][To])
		{
			NeighbourAdded[From][To] = true;
			NeighbourAdded[To][From] = true;
			Neighbours[From].add(To);
			Neighbours[To].add(From);
		}
	}

	public int NetworkFlow()
	{
		Flow = new int[Nodes][Nodes];
		int[] parent = new int[Nodes];
		int[] cap = new int[Nodes];

		int total = 0;
		while (true)
		{
			for (int i = 0; i < Nodes; i++)
				parent[i] = -1;
			parent[this.Source] = -2;
			cap[this.Source] = Integer.MAX_VALUE;
			Queue<Integer> Q = new LinkedList<Integer>();
			Q.offer(this.Source);
			while (!Q.isEmpty() && parent[this.Sink] == -1)
			{
				int act = Q.poll();
				for(int next : Neighbours[act])
				{
					if (parent[next] == -1 && Capacity[act][next] > Flow[act][next])
					{
						parent[next] = act;
						cap[next] = Math.min(cap[act], Capacity[act][next] - Flow[act][next]);
						Q.offer(next);
					}
				}
			}

			if (parent[this.Sink] == -1)
				return total;

			total += cap[this.Sink];
			int j = this.Sink;
			while (j != this.Source)
			{
				Flow[parent[j]][j] += cap[this.Sink];
				Flow[j][parent[j]] -= cap[this.Sink];
				j = parent[j];
			}
		}
	}
}