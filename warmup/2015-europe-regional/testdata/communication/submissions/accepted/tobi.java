import java.util.*;

public class tobi {
	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			String s = Integer.toBinaryString(sc.nextInt()), ret = "";
			int last = 0;
			for (int j = s.length() - 1; j >= 0; j--) {
				last = (s.charAt(j) - '0') ^ last;
				ret = last + ret;
			}
			while (last == 1 && ret.length() < 8) ret = "1" + ret;
			System.out.println(Integer.parseInt(ret, 2));
		}
	}
}
