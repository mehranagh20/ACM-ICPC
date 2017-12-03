import java.util.Arrays;


public class OSDSolver {
	
	static long T;
	static long C;	
	static long[] mem;
	
	public static long solveProblem(int lineCnt, int runningTime, int typingTime){
		int N=lineCnt;
        T=runningTime;
        C=typingTime;
        
        mem=new long[N+1];
        Arrays.fill(mem, Long.MAX_VALUE);
        
        mem[0]=0;
        mem[1]=0;
        
        return getMin(N);
	}


    static long getMin(int N){
		if(mem[N]==Long.MAX_VALUE)
			for(int i=2;i<=N;i++)
				mem[N]=Math.min(mem[N], (i-1)*C+T+getMin((N+i-1)/i));
		
		return mem[N];
	}
}
