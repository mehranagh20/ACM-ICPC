import java.util.*;
import java.io.*;

public class jeroen_randomized
{
	static int n;
	static long[] a, b;
	static long ops;
	static String op = "+-*";
	static Map<Long, Integer> idx;
	static long[][] anss;
	static Random rand = new Random(31337);

	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		// Read input
		n = Integer.valueOf(in.readLine());
		a = new long[n];
		b = new long[n];
		for (int i = 0; i < n; i++)
		{
			String[] ps = in.readLine().split(" ");
			a[i] = Long.valueOf(ps[0]);
			b[i] = Long.valueOf(ps[1]);
		}

		// Compute possible answers
		int numAns = 0;
		idx = new HashMap<Long, Integer>();
		anss = new long[n][];
		for (int i = 0; i < n; i++)
		{
			anss[i] = new long[] { a[i] + b[i], a[i] - b[i], a[i] * b[i] };
			for(long ans : anss[i])
				if (!idx.containsKey(ans))
					idx.put(ans, numAns++);
		}

		// Do randomized search for a max number of iterations
		boolean found = false;
		lines = new String[n];
		done = new boolean[numAns];
		ops = 0;
		while (ops < 1000000) // tweak to fit in time
		{
			if (Try(0))
			{
				found = true;
				break;
			}
		}

		if (found)
			for (int i = 0; i < n; i++)
				System.out.println(lines[i]);
		else
			System.out.println("impossible");
	}

	static boolean[] done;
	static String[] lines;

	public static boolean Try(int i)
	{
		if (i == n) return true;

		ops++;

		int npos = 0;
		for (int j = 0; j < 3; j++)
			if (!done[idx.get(anss[i][j])])
				npos++;
		if (npos == 0) return false;

		int take = npos == 1 ? 0 : rand.nextInt(npos);

		for (int j = 0; j < 3; j++)
		{
			if (done[idx.get(anss[i][j])]) continue;
			if (take-- == 0)
			{
				done[idx.get(anss[i][j])] = true;
				if (Try(i + 1))
				{
					lines[i] = String.format("%d%c%d=%d", a[i], op.charAt(j), b[i], anss[i][j]);
					return true;
				}
				done[idx.get(anss[i][j])] = false;
				break;
			}
		}

		return false;
	}
}