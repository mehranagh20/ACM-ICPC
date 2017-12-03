import java.util.Arrays;
import java.util.Scanner;

/*
  dp is too slow because it also calculates values, which are not needed, 
  so trying to speed it up by stepping over some cells
  but alas, it does not work...
 */

public class EgorDPSteppingOverCells{
	
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
        for(int i=1;i<=N;i++){
           int factor=2;
           while(true){
        	   if(factor*i>N)
        		   break;
        	   int goal=factor*i;
        	   int neededLines=factor-1;
        	   mem[goal]=Math.min(mem[goal], (neededLines)*C+T+mem[i]);
        	   factor++;
           }
        }
        
        System.out.println(mem[N]);
    }
	
}
