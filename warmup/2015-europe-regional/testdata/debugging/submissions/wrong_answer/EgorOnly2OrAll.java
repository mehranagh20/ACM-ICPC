import java.util.Arrays;
import java.util.Scanner;

/*
  recursion without memoization is too slow, so mix two strategies: put all lines or only one
 */

public class EgorOnly2OrAll{
	
	
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
    	
		return Math.min((N-1)*C+T, C+T+getMin((N+1)/2));	
	}
}
