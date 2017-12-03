/**
 * This class generates special inputs for the login problem. First, n/2
 * researchers arrive distributed over the interval 1..10^7. After 10^7
 * minutes, each of them leaves again. A second batch of researchers
 * arrives 2*10^7 minutes later as the first one. We always fix m=2*10^7.
 *
 * These arguments should be given
 * - n: the number of researchers
 * - inverse: setting this to true makes the first batch of researchers
 *     appear in reversed order
 * - pop: setting this to true put all researcher into the first batch
 *
 * @author Stefan Toman (toman@tum.de)
 */
public class LoginsGeneratorFullPQ {

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("usage: java LoginsGeneratorFullPQ n inverse pop");
        }
        //number of researchers
        int n = Integer.parseInt(args[0]);
        //should the first batch be given in inverted order?
        boolean inverse = Boolean.parseBoolean(args[1]);
        //should there be a second batch of researchers?
        boolean pop = Boolean.parseBoolean(args[2]);
        int m = 20000000;
        int b = 20000000;
        
        StringBuilder sb = new StringBuilder();
        sb.append(n).append(' ').append(m).append("\n");
        for (int i = 0; i < n/(pop ? 2 : 1); i++) {
            sb.append(1+(int) ((double) b*(inverse ? n/(pop ? 2 : 1)-i : i)/n)).append(' ').append(b).append("\n");
        }
        for (int i = n/2; pop && i < n; i++) {
            sb.append(1+m+b+(int) ((double) b*(i-n/2)/n)).append(' ').append(b).append("\n");
        }
        System.out.print(sb);
    }
}
