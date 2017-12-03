import java.util.*;
import java.io.*;

public class jeroen
{
	static int n;
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(in.readLine());
		int[] a = readArray(in);
		int[] b = readArray(in);
		int[] c = readArray(in);
		
		// Because there are 3 arrays, we count each inversion exactly twice
		System.out.println(((long)n * (long)(n-1) - inversions(a,b) - inversions(a,c) - inversions(b,c)) / 2);
	}
	
	public static int[] readArray(BufferedReader in) throws IOException {
		String[] ss = in.readLine().split(" ");
		int[] ret = new int[ss.length];
		for(int i = 0; i < ss.length; i++)
			ret[i] = Integer.parseInt(ss[i]);
		return ret;
	}
	
	public static long inversions(int[] a, int[] b) {
		BIT bit = new BIT(n+1);
		int[] pos = new int[n+1];
		for(int i = 0; i < n; i++)
			pos[a[i]] = i;
		long ret = 0;
		for(int i = 0; i < n; i++) {
			ret += i - bit.readupto(pos[b[i]]);
			bit.add(pos[b[i]], 1);
		}
		return ret;
	}
}

class BIT
{
	int max;
	int[] tree;

	public BIT(int max)
	{
		this.max = max;
		this.tree = new int[max];
	}

	public int readupto(int index)
	{
		index++;
		int ret = 0;
		while (index > 0)
		{
			ret += tree[index];
			index -= (index & -index);
		}
		return ret;
	}

	public void add(int index, int val)
	{
		index++;
		while (index < max)
		{
			tree[index] += val;
			index += (index & -index);
		}
	}
}