
import java.util.Random;

/**
 * This generator creates random inputs for the logins problem. It needs three
 * arguments:
 * - seed: a 64-bit seed for the random number generator
 * - n: the number of researchers
 * - maxTime: the latest time a researcher should arrive, also used as the
 *     maximum time a researchers stays
 *
 * @author Stefan Toman (toman@tum.de)
 */
public class LoginsGeneratorRandom {

    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("usage: java LoginsGeneratorRandom seed n maxTime");
        }
        long seed = Long.parseLong(args[0]);
        int n = Integer.parseInt(args[1]);
        int maxTime = Integer.parseInt(args[2]);

        Random r = new Random(seed);
        int m = 1 + r.nextInt(maxTime);
        StringBuilder sb = new StringBuilder();
        sb.append(n).append(' ').append(m).append("\n");
        for (int i = 0; i < n; i++) {
            sb.append(1 + r.nextInt(maxTime)).append(' ').append(1 + r.nextInt(maxTime)).append("\n");
        }
        System.out.print(sb);
    }
}
