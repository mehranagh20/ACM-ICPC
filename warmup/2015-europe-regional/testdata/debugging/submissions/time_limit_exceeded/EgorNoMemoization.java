import java.util.Arrays;
import java.util.Scanner;

/*
 rucursion but without memoization -> should time limit
 */

public class EgorNoMemoization{
	
	static long T;
	static long C;
	
	
	public static void main(String[] args)throws Exception{
        Scanner in=new Scanner(System.in);
        
        int N=in.nextInt();
        T=in.nextInt();
        C=in.nextInt();
        
        System.out.println(getMin(N));
    }
	
    static long getMin(int N){
    	if(N==0 || N==1)
    		return 0L;
    	
		long res=Long.MAX_VALUE;
		for(int i=2;i<=N;i++)
				res=Math.min(res, (i-1)*C+T+getMin((N+i-1)/i));
		
		return res;
	}
}
