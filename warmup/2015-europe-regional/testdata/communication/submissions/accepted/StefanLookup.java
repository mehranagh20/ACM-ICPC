import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * This is a solution to the encryption problem. All solutions to the 256
 * possible numbers are stored in a lookup table.
 * 
 * @author Stefan Toman (toman@tum.de)
 */
public class StefanLookup {
	public static final int[] lookup = { 0, 255, 254, 1, 252, 3, 2, 253, 248, 7, 6, 249, 4, 251, 250, 5, 240, 15, 14,
			241, 12, 243, 242, 13, 8, 247, 246, 9, 244, 11, 10, 245, 224, 31, 30, 225, 28, 227, 226, 29, 24, 231, 230,
			25, 228, 27, 26, 229, 16, 239, 238, 17, 236, 19, 18, 237, 232, 23, 22, 233, 20, 235, 234, 21, 192, 63, 62,
			193, 60, 195, 194, 61, 56, 199, 198, 57, 196, 59, 58, 197, 48, 207, 206, 49, 204, 51, 50, 205, 200, 55, 54,
			201, 52, 203, 202, 53, 32, 223, 222, 33, 220, 35, 34, 221, 216, 39, 38, 217, 36, 219, 218, 37, 208, 47, 46,
			209, 44, 211, 210, 45, 40, 215, 214, 41, 212, 43, 42, 213, 128, 127, 126, 129, 124, 131, 130, 125, 120, 135,
			134, 121, 132, 123, 122, 133, 112, 143, 142, 113, 140, 115, 114, 141, 136, 119, 118, 137, 116, 139, 138,
			117, 96, 159, 158, 97, 156, 99, 98, 157, 152, 103, 102, 153, 100, 155, 154, 101, 144, 111, 110, 145, 108,
			147, 146, 109, 104, 151, 150, 105, 148, 107, 106, 149, 64, 191, 190, 65, 188, 67, 66, 189, 184, 71, 70, 185,
			68, 187, 186, 69, 176, 79, 78, 177, 76, 179, 178, 77, 72, 183, 182, 73, 180, 75, 74, 181, 160, 95, 94, 161,
			92, 163, 162, 93, 88, 167, 166, 89, 164, 91, 90, 165, 80, 175, 174, 81, 172, 83, 82, 173, 168, 87, 86, 169,
			84, 171, 170, 85 };

	public static void main(String[] args) throws IOException {
		// read the input
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		String[] tmp = in.readLine().split(" ");

		// iterate over the numbers
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(lookup[Integer.parseInt(tmp[i])]);
			if (i < n - 1) {
				sb.append(' ');
			}
		}

		// print all numbers
		System.out.println(sb);
	}
}

