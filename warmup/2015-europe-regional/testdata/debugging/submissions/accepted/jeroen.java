import java.util.*;
import java.io.*;

public class jeroen
{
	static long T, C;
	static long[] mem;
	static boolean[] done;
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		T = sc.nextInt();
		C = sc.nextInt();
		done = new boolean[N+1];
		mem = new long[N+1];
		System.out.println(rec(N));
	}
	
	public static long rec(int N) {
		if(N == 1) return 0;
		if(done[N]) return mem[N];
		done[N] = true;
		
		mem[N] = Long.MAX_VALUE;
		for(int i = 2; i <= N; i++) {
			mem[N] = Math.min(mem[N], T + C * (i - 1) + rec((N + i - 1) / i));
		}
		return mem[N];
	}
}