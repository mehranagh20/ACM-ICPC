import java.util.Arrays;
import java.util.Scanner;

/*
 
 recursion does not test all possible partitions, but only first N 
 (and adding printf after every line of cause)
 
  I guess there is a N big enough due to the constrains, the question is, how big this n should be...

  the answer: 1000 (sqrt(1_000_000))
  
 */


public class EgorOnlyFirstN_2{
	
	static long T;
	static long C;
	
	static int FIRST_N=999; //not good enough...
	
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
		if(mem[N]==Long.MAX_VALUE)
			for(int i=2;i<=Math.min(N, FIRST_N);i++)
				mem[N]=Math.min(mem[N], (i-1)*C+T+getMin((N+i-1)/i));
		//printf after every line:
		mem[N]=Math.min(mem[N], (N-1)*C+T);
		return mem[N];
	}
}
