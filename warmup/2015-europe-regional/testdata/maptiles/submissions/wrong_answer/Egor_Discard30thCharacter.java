import java.util.Scanner;


public class Egor_Discard30thCharacter {

	public static void main(String[] args)throws Exception{
        Scanner in=new Scanner(System.in);
        
        String line=in.nextLine();
        
        int[] xs={0,1,0,1};
        int[] ys={0,0,1,1};
        
        int xCoord=0;
        int yCoord=0;
        
        for(int i=0;i<Math.min(line.length(), 29);i++){
        	int ch=line.charAt(i)-'0';
        	xCoord=xCoord*2+xs[ch];
        	yCoord=yCoord*2+ys[ch];
        }
        System.out.println(line.length()+" "+xCoord+" "+yCoord);
        in.close();
    }

}
