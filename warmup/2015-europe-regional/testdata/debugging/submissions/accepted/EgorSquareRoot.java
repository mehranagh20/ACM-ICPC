import java.util.Arrays;
import java.util.Scanner;

/*
Number of printfs is maximal sqrt(N) or N-1 [the last would mean we are in the last level of the recursion]

too see why this works consider:

 a/N/M=a/M/N (for rounding the result of the division up)

so if in the first step we have N printfs and and the second M, we would get the same
result if we would do M printfs in the first step and N in the second.

Now we could sort the number of the printfs, so that in the earlier step of the recursion we
have no more printfs as in the latter steps.

In the latter step we can have at most "LineCnt in the latter step"-1 printfs, so it is enough to explore only sqrt(N) printfs in the first step.

As for the running time: Don't really know, but it seems to be fast...:)

*/


public class EgorSquareRoot{
	
	static long T;
	static long C;
	
	static long[] mem;
	
    public static void main(String[] args)throws Exception{
        Scanner in=new Scanner(System.in);
        
        int N=in.nextInt();
        T=in.nextInt();
        C=in.nextInt();
        
        mem=new long[N+1];
        Arrays.fill(mem, Long.MAX_VALUE);
        
        mem[0]=0;
        mem[1]=0;
        
        System.out.println(getMin(N));
    }
	
    static long getMin(int N){
		if(mem[N]==Long.MAX_VALUE){
			for(int i=2;i*i<=N;i++)
				mem[N]=Math.min(mem[N], (i-1)*C+T+getMin((N+i-1)/i));
		
			mem[N]=Math.min(mem[N], (N-1)*C+T);//printf after every line
		}


		return mem[N];
	}
}
