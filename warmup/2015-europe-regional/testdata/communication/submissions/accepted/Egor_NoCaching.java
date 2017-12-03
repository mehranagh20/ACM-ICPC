import java.io.BufferedReader;
import java.io.InputStreamReader;

/*
most time is used for IO and parsing, so we can be inefficient during the calculation
*/
public class Egor_NoCaching {

    static int encode(int z){

		for(int i=0;i<256;i++){
			int decoded=(i^(i*2))%256;
			if(decoded==z)
				return i;
		}
		return 0;
    }
    
    
	public static void main(String[] args)  throws Exception {
		
		
		
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 
		 //skip first line (N):
		 reader.readLine();
	 
		 String[] bytes=reader.readLine().split(" ");
		 StringBuilder sb=new StringBuilder();
		 int cnt=0;
		 for(String b:bytes){
			 if(cnt!=0)
				 sb.append(" ");
			 sb.append(encode(Integer.parseInt(b)));
			 cnt++;
		 }
		 
		 System.out.println(sb.toString());
	}

}
