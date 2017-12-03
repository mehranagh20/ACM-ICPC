import java.util.Scanner;

/**
 * This class converts an input of the flight problem to a GPX file. Save the
 * output and open it in your favorite maps program to visualize the results.
 * 
 * @author Stefan Toman (toman@tum.de)
 *
 */
public class FlightInputToGPX {
	public static void main(String[] args) {
		// print xml header
		System.out
				.println("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" ?><gpx xmlns=\"http://www.topografix.com/GPX/1/1\" version=\"1.1\" creator=\"Wikipedia\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd\">");

		// open input
		Scanner s = new Scanner(System.in);

		// read continents
		int c = s.nextInt();
		for (int i = 0; i < c; i++) {
			printTrack("Continent " + i, s, true);
		}

		// read route
		printTrack("Flight", s, false);

		// end xml file
		System.out.println("</gpx>");
	}

	// print one track
	public static void printTrack(String name, Scanner s, boolean close) {
		System.out.format("<rte><name>%s</name>", name);
		int n = s.nextInt();
		int firstLat = 0, firstLon = 0;
		for (int j = 0; j < n; j++) {
			int lat = s.nextInt();
			int lon = s.nextInt();
			if (lon >= 180) lon -= 360;
			if (j == 0) {
				firstLat = lat;
				firstLon = lon;
			}
			System.out.format("<rtept lat=\"%d\" lon=\"%d\" />", lat, lon);
		}
		if (close) {
			System.out.format("<rtept lat=\"%d\" lon=\"%d\" />", firstLat,
					firstLon);
		}
		System.out.println("</rte>");

	}
}
