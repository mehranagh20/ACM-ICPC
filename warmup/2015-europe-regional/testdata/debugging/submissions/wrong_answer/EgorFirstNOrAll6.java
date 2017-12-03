import java.util.Arrays;
import java.util.Scanner;

/*
  recursion without memoization is too slow, so try only factors 2 to MAXI N or all
  MAXI is with 6  too small to get all results right (for these test cases now you will need exactly 1000)
 */

public class EgorFirstNOrAll6{
	
	
	static long T;
	static long C;
	
	static int MAXI=6;//number of maximal steps
	
	
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
		for(int i=2;i<=MAXI;i++)
				res=Math.min(res, (i-1)*C+T+getMin((N+i-1)/i));
		
		return Math.min(res, (N-1)*C+T);	
	}
}
