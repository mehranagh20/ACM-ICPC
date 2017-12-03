import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Egor {

	public static void main(String[] args)  throws Exception {
		
		int[] table=new int[256];
		for(int i=0;i<256;i++)
			table[(i^(i*2))%256]=i;
		
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 
		 //skip first line (N):
		 reader.readLine();
	 
		 String[] bytes=reader.readLine().split(" ");
		 StringBuilder sb=new StringBuilder();
		 int cnt=0;
		 for(String b:bytes){
			 if(cnt!=0)
				 sb.append(" ");
			 sb.append(table[Integer.parseInt(b)]);
			 cnt++;
		 }
		 
		 System.out.println(sb.toString());
	}

}
