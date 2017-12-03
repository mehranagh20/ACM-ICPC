import java.util.*;
import java.io.*;

public class jeroen_greedy
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		// Read input
		int n = Integer.valueOf(in.readLine());
		Pair[] pair = new Pair[n];
		for (int i = 0; i < n; i++)
		{
			String[] ps = in.readLine().split(" ");
			pair[i] = new Pair(i, Long.valueOf(ps[0]), Long.valueOf(ps[1]));

			pair[i].answers = new Answer[3];
			pair[i].answers[0] = new Answer(pair[i].a + pair[i].b, '+');
			pair[i].answers[1] = new Answer(pair[i].a - pair[i].b, '-');
			pair[i].answers[2] = new Answer(pair[i].a * pair[i].b, '*');
			Arrays.sort(pair[i].answers);
		}

		boolean found = false;

		if (!found) found = SmallestFirst(pair);
		if (!found) found = BiggestFirst(pair);

		if (found)
		{
			Arrays.sort(pair, new Comparator<Pair>() {
				public int compare(Pair a, Pair b) {
					return a.idx - b.idx;
				}
			});
			for (int i = 0; i < n; i++)
				System.out.println(pair[i].ans);
		}
		else
		{
			System.out.println("impossible");
		}
	}

	public static boolean SmallestFirst(Pair[] pair)
	{
		return GreedyCompare(pair, new Comparator<Pair>() {
			public int compare(Pair a, Pair b) {
				for (int i = 0; i < 3; i++)
					if (a.answers[i].num != b.answers[i].num)
						return a.answers[i].num - b.answers[i].num < 0 ? -1 : 1;
				return 0;
			}
		});
	}

	public static boolean BiggestFirst(Pair[] pair)
	{
		return GreedyCompare(pair, new Comparator<Pair>() {
			public int compare(Pair a, Pair b) {
				for (int i = 2; i >= 0; i--)
					if (a.answers[i].num != b.answers[i].num)
						return a.answers[i].num - b.answers[i].num < 0 ? 1 : -1;
				return 0;
			}
		});
	}

	public static boolean GreedyCompare(Pair[] pair, Comparator<Pair> comp)
	{
		Arrays.sort(pair, comp);

		HashSet<Long> taken = new HashSet<Long>();
		for (int i = 0; i < pair.length; i++)
		{
			boolean found = false;
			for (int j = 0; j < 3; j++)
			{
				if (!taken.contains(pair[i].answers[j].num))
				{
					taken.add(pair[i].answers[j].num);
					pair[i].ans = String.format("%d%c%d=%d", pair[i].a, pair[i].answers[j].op, pair[i].b, pair[i].answers[j].num);
					found = true;
					break;
				}
			}
			if (!found) return false;
		}

		return true;
	}
}

class Answer implements Comparable<Answer> {
	public long num;
	public char op;
	
	public Answer(long num, char op) {
		this.num = num;
		this.op = op;
	}
	
	public int compareTo(Answer other) {
		if(num < other.num)
			return -1;
		else if(num > other.num)
			return 1;
		else
			return 0;
	}
}

class Pair
{
	public int idx;
	public long a, b;
	public String ans;
	public Answer[] answers;

	public Pair(int idx, long a, long b)
	{
		this.idx = idx;
		this.a = a;
		this.b = b;
	}
}