import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * This is a solution for the maptiles problem. We compute the coordinates by
 * reading the input beginning with the last character and moving the tile by
 * 2^i in step i.
 * 
 * @author Stefan Toman (toman@tum.de)
 *
 */
public class Stefan {
	public static void main(String[] args) throws IOException {
		// read input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String quadkey = in.readLine();

		// compute coordinates
		int n = quadkey.length();
		int x = 0, y = 0;
		int twopow = 1;
		for (int i = n - 1; i >= 0; i--) {
			switch (quadkey.charAt(i)) {
			case '0':
				break;
			case '1':
				x += twopow;
				break;
			case '2':
				y += twopow;
				break;
			case '3':
				x += twopow;
				y += twopow;
				break;
			}
			twopow *= 2;
		}

		// print result
		System.out.println(n + " " + x + " " + y);
	}
}
