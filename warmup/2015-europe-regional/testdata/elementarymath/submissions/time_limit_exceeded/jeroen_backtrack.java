import java.util.*;
import java.io.*;

public class jeroen_backtrack
{
	static int n;
	static long[] a, b;
	
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

		lines = new String[n];
		if (Backtrack(0))
			for (int i = 0; i < n; i++)
				System.out.println(lines[i]);
		else
			System.out.println("impossible");
	}

	static HashSet<Long> done = new HashSet<Long>();
	static String[] lines;

	public static boolean Backtrack(int i)
	{
		if (i == n) return true;

		long[] answ = new long[] { a[i] + b[i], a[i] - b[i], a[i] * b[i] };
		String op = "+-*";
		for (int j = 0; j < 3; j++)
		{
			if (done.contains(answ[j])) continue;
			done.add(answ[j]);
			if (Backtrack(i + 1))
			{
				lines[i] = String.format("%d%c%d=%d", a[i], op.charAt(j), b[i], answ[j]);
				return true;
			}
			done.remove(answ[j]);
		}

		return false;
	}
}