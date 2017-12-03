import java.util.*;
import java.io.*;

public class tobi {
	public static int N, M, walks, a, b;
	public static MultiInt[] logins = new MultiInt[1000005];
	public static PriorityQueue<Integer> active = new PriorityQueue<>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		for (int i = 0; i < N; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			logins[2*i + 0] = new MultiInt(a,1);
			logins[2*i + 1] = new MultiInt(a+b,0);
		}
		Arrays.sort(logins, 0, 2*N);

		for (int i = 0; i < 2 * N; i++) {
			if (logins[i].second == 1) {
				while (active.size() > 0 && active.peek() < logins[i].val) active.poll();
				if (active.size() > 0) active.poll();
				else walks++;
			} else active.add(logins[i].val + M);
		}
		System.out.println(N-walks);
	}
}

class MultiInt implements Comparable<MultiInt> {
	int val, second;
	MultiInt(int val, int second) {
		this.val = val;
		this.second = second;
	}
	public int compareTo(MultiInt m) {
		if (val != m.val) return val - m.val;
		return second - m.second;
	}
}
