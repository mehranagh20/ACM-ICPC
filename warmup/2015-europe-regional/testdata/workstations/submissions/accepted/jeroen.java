import java.io.*;
import java.util.*;

public class jeroen
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ps = in.readLine().split(" ");
		int n = Integer.valueOf(ps[0]);
		int m = Integer.valueOf(ps[1]);

		List<Tuple<Integer, Event>> events = new ArrayList<Tuple<Integer, Event>>();
		for (int i = 0; i < n; i++)
		{
			ps = in.readLine().split(" ");
			int a = Integer.valueOf(ps[0]);
			int b = Integer.valueOf(ps[1]);
			events.add(new Tuple<Integer, Event>(a, Event.Arrive));
			events.add(new Tuple<Integer, Event>(a + b, Event.Leave));
		}
		Collections.sort(events);

		int ans = 0;
		PriorityQueue<Integer> compFree = new PriorityQueue<Integer>();
		for (Tuple<Integer, Event> ev : events)
		{
			if (ev.Item2 == Event.Arrive)
			{
				// Take computer that was left longest ago
				boolean canSave = false;
				while (!compFree.isEmpty())
				{
					int nextFree = compFree.poll();
					if (nextFree + m >= ev.Item1)
					{
						canSave = true;
						break;
					}
				}
				if (canSave) ans++;
			}
			else
			{
				compFree.offer(ev.Item1);
			}
		}
		System.out.println(ans);
	}

	enum Event
	{
		Leave, Arrive // order is important, first handle Leave
	}
}

// Translation of C# class
class Tuple<A extends Comparable<A>,B extends Comparable<B>> implements Comparable<Tuple<A,B>> {
	public A Item1;
	public B Item2;
	
	public Tuple(A a, B b) {
		Item1 = a;
		Item2 = b;
	}
	
	public int compareTo(Tuple<A,B> other) {
		int ret = Item1.compareTo(other.Item1);
		if(ret != 0) return ret;
		return Item2.compareTo(other.Item2);
	}
}
