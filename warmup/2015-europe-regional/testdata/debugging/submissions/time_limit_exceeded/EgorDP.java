import java.util.Arrays;
import java.util.Scanner;

/*
  dp is too slow because it also calculates values, which are not needed, 
  thus resulting in O(n^2)
 */

public class EgorDP{
	
	static long T;
	static long C;
	
	
	public static void main(String[] args)throws Exception{
        Scanner in=new Scanner(System.in);
        
        int N=in.nextInt();
        T=in.nextInt();
        C=in.nextInt();
        
        long[] mem=new long[N+1];
        Arrays.fill(mem, Long.MAX_VALUE);
        mem[0]=0;
        mem[1]=0;
        for(int i=1;i<=N;i++)
        	for(int goal=i+1;goal<=N;goal++){
        		int neededLines=(goal+i-1)/i-1;
        		mem[goal]=Math.min(mem[goal], (neededLines)*C+T+mem[i]);
        	}
      
        
        System.out.println(mem[N]);
    }
	
}
