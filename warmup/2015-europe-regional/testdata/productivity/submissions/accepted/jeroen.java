import java.util.*;
import java.io.*;

public class jeroen {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int p = sc.nextInt();
		Worker[] worker = new Worker[n];
		for(int i = 0; i < n; i++)
			worker[i] = new Worker(sc.nextInt(), sc.nextInt());
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i != j && worker[i].a <= worker[j].a && worker[j].b <= worker[i].b && worker[i].b - worker[i].a > worker[j].b - worker[j].a)
					worker[i].sup = true;
		
		Arrays.sort(worker);
		int s = 0;
		while(s < n && !worker[s].sup) s++;
		
		ArrayList<Integer> largestSingle = new ArrayList<Integer>();
		for(int i = s; i < n; i++)
			largestSingle.add(worker[i].b - worker[i].a);
		Collections.sort(largestSingle);
		
		int[][] dp = new int[s+1][p+1];
		for(int i = 0; i <= s; i++)
			for(int j = 0; j <= p; j++)
				dp[i][j] = Integer.MIN_VALUE / 2;
				
		dp[0][0] = 0;
		for(int i = 0; i < s; i++) {
			for(int j = 0; j < p; j++) {
				int start = worker[i].a;
				int end = worker[i].b;
				for(int k = i; k < s; k++) {
					start = Math.max(worker[k].a, start);
					end = Math.min(worker[k].b, end);
					if(end <= start) break;
					dp[k+1][j+1] = Math.max(dp[k+1][j+1], dp[i][j] + end - start);
				}
			}
		}
		
		int ans = 0;
		int sum = 0;
		for(int i = 0; i <= largestSingle.size() && i < p; i++) {
			ans = Math.max(ans, dp[s][p-i] + sum);
			if(i < largestSingle.size())
				sum += largestSingle.get(largestSingle.size()-i-1);
		}
		System.out.println(ans);
	}
}

class Worker implements Comparable<Worker> {
	public int a, b;
	public boolean sup = false;
	
	public Worker(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	public int compareTo(Worker other) {
		if(!sup && other.sup) return -1;
		if(sup && !other.sup) return 1;
		return a - other.a;
	}
}
