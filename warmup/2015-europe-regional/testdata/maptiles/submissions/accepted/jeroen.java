import java.util.*;
import java.io.*;

public class jeroen
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		String quadkey = in.readLine();
		int x = 0;
		int y = 0;
		for (int i = 0; i < quadkey.length(); i++)
		{
			x <<= 1;
			y <<= 1;
			if (quadkey.charAt(i) == '1' || quadkey.charAt(i) == '3')
				x++;
			if (quadkey.charAt(i) == '2' || quadkey.charAt(i) == '3')
				y++;
		}
		System.out.println(quadkey.length() + " " + x + " " + y);
	}
}