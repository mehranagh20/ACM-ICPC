import java.util.*;
import java.io.*;

public class jeroen
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int[] table = new int[256];
		for (int x = 0; x < 256; x++)
			table[(x ^ (x << 1)) & 0xFF] = x;
		
		in.readLine();
		String[] nums = in.readLine().split(" ");
		for(int i = 0; i < nums.length; i++) {
			if(i > 0) System.out.print(" ");
			System.out.print(table[Integer.valueOf(nums[i])]);
		}
		System.out.println();
	}
}