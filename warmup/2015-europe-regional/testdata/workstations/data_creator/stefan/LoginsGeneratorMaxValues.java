/**
 * This generator creates inputs for the logins problem such that all inputs
 * are set to their maximum values. Additionally, an argument may be given
 * specifying that the researchers do not arrive in one bug group but in
 * several smaller ones. The number given is used as the number of groups.
 *
 * @author Stefan Toman (toman@tum.de)
 */
public class LoginsGeneratorMaxValues {

    public static void main(String[] args) {
        int groups = args.length >= 1 ? Integer.parseInt(args[0]) : 1;
        StringBuilder sb = new StringBuilder();
        sb.append(300000).append(' ').append(100000000).append("\n");
        for (int i = 0; i < 300000; i++) {
            sb.append((groups > 1 ? (i/(300000/groups)+1) : 1)*100000000/groups).append(' ').append(100000000).append("\n");
        }
        System.out.print(sb);
    }
}
