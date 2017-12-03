import java.util.Scanner;


public class Egor {

	public static void main(String[] args)throws Exception{
        Scanner in=new Scanner(System.in);
        
        String line=in.nextLine();
        
        int[] xs={0,1,0,1};
        int[] ys={0,0,1,1};
        
        int xCoord=0;
        int yCoord=0;
        
        for(int i=0;i<line.length();i++){
        	int ch=line.charAt(i)-'0';
        	xCoord=xCoord*2+xs[ch];
        	yCoord=yCoord*2+ys[ch];
        }
        System.out.println(line.length()+" "+xCoord+" "+yCoord);
        in.close();
    }

}
