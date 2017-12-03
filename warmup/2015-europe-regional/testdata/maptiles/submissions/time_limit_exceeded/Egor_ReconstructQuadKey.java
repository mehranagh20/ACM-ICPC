import java.util.Scanner;


public class Egor_ReconstructQuadKey {

	public static void main(String[] args)throws Exception{
        Scanner in=new Scanner(System.in);
        
        String line=in.nextLine();
        
        char[] ids={'0','1','2', '3'};
        
        int MAX=1<<line.length();
        
        for(int x=0;x<MAX;x++)
          for(int y=0;y<MAX;y++){
        	char[] quadkey=new char[line.length()];
        	int curX=x;
        	int curY=y;
        	for(int i=0;i<line.length();i++){
        	   quadkey[line.length()-i-1]=ids[(curY%2)*2+curX%2];
        	   curX/=2;
        	   curY/=2;
        	}
        	
        	if(line.equals(new String(quadkey))){
        		System.out.println(line.length()+" "+x+" "+y);
                in.close();
        		return;
        	}
          }
        
        in.close();
    }

}
