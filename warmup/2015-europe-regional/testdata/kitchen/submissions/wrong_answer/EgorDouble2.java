import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.BitSet;
/*
 uses double in order not to get an overflow. However using it only for the product. Saving the sum in a long.
*/

public class EgorDouble2 {

	
	public static void main(String[] args) throws IOException {
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 String[] ss=reader.readLine().split(" ");
		 int r=Integer.parseInt(ss[0]);
		 int s=Integer.parseInt(ss[1]);
		 int m=Integer.parseInt(ss[2]);
		 int d=Integer.parseInt(ss[3]);
		 int n=Integer.parseInt(ss[4]);
		 
		 int dN=s+m+d;
		 
		 int[] brandCnts=readArrayFromLine(reader.readLine());
		 BitSet[] dishes=new BitSet[dN];
		 
		 for(int i=0;i<dN;i++)
			 dishes[i]=readBitSetFromLine(reader.readLine());
		 
		 boolean[][] forbidden=new boolean[dN][dN];
		 for(int i=0;i<n;i++){
			 ss=reader.readLine().split(" ");
			 int from=Integer.parseInt(ss[0])-1; int to=Integer.parseInt(ss[1])-1;
			 forbidden[from][to]=true;
			 forbidden[to][from]=true;
		 }
		
		 long result=0;
		 BitSet current=new BitSet(r);
		 for(int i=0;i<s;i++){	 
			 for(int j=s;j<s+m;j++){
				 if(forbidden[i][j])
					 continue;
				 for(int k=s+m;k<dN;k++){
					 if(forbidden[i][k] || forbidden[j][k])
						 continue;
					 

					 current.clear();
					 current.or(dishes[i]); current.or(dishes[j]); current.or(dishes[k]);
					 
					 double cnt=1;
					 for(int ing=0;ing<r;ing++)
						 if(current.get(ing))
							 cnt*=brandCnts[ing];
					 if(cnt>1e18){
						System.out.println("too many");
						return;
					 }
					 result+=(long)Math.round(cnt);
				 }
			 }
		 }
		 
		 if(result>1_000_000_000_000_000_000L)
			 System.out.println("too many");
		 else
			 System.out.println((long)Math.round(result));
		

	}
	
	static int[] readArrayFromLine(String line){
		String[] ss=line.split(" ");
		int[] res=new int[ss.length];
		for(int i=0;i<ss.length;i++)
			res[i]=Integer.parseInt(ss[i]);
		
		return res;	
	}
	
	
	static BitSet readBitSetFromLine(String line){
		String[] ss=line.split(" ");
		BitSet res=new BitSet();
		for(int i=1;i<ss.length;i++)
			res.set(Integer.parseInt(ss[i])-1);
		
		return res;
	}
	

}
