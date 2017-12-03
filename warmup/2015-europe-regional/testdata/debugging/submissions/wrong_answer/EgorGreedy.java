import java.util.Arrays;
import java.util.Scanner;

/*
  recursion without memoization is too slow, so try to choose the best move and take the steepest descend
 */

public class EgorGreedy{
	
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
	    double bestGrade=0.0;
	    int bestFactor=1;
	    for(int i=2;i<=N;i++){
			int lineReduced=N-(N+i-1)/i;
			long curCost=(i-1)*C+T;
			double curGrade=((double) lineReduced)/curCost;
			if(curGrade>= bestGrade){
				bestFactor=i;
				bestGrade=curGrade;
			}
		}
		
	    return (bestFactor-1)*C+T+getMin((N+bestFactor-1)/bestFactor);
	}
}
