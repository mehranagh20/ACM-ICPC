import java.util.Arrays;
import java.util.Scanner;


public class Egor{
	
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
		if(mem[N]==Long.MAX_VALUE)
			for(int i=2;i<=N;i++)
				mem[N]=Math.min(mem[N], (i-1)*C+T+getMin((N+i-1)/i));
		
		return mem[N];
	}
}
