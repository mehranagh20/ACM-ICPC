import java.io.BufferedReader;
import java.io.InputStreamReader;


public class EgorDummy {

	public static void main(String[] args)  throws Exception {
			 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
			 int N=Integer.parseInt(reader.readLine());
			 for(int i=0;i<N;i++)
				 System.out.println("1+"+i+"="+(i+1));
	}

}
