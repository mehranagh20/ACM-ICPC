import java.awt.Font;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

import javax.imageio.ImageIO;

/**
 * This class visualizes a possible solution to each input
 * of the login problem. Each machine is displayed as a
 * horizontal bar, time is shown using the horizontal
 * axis from left to right.
 * 
 * Read areas indicate a used
 * machine (the number of the researcher is always given
 * on the left of the red area) that Peter had to enable
 * whereas green areas indicate time used by a researcher
 * that could use a running session, yellow areas indicate
 * times where the machine is not used but the session is
 * still active and gray areas indicate unused machines.
 * 
 * We try to scale the image in a way that it has
 * dimensions of ~1920x1000 pixels.
 * 
 * Note that the schedule given here may reuse machines
 * with closed sessions. This is not necessary but shrinks
 * the images.
 *
 * @author Stefan Toman (toman@tum.de)
 */
public class LoginsVisualizer {

	public static void main(String[] args) throws IOException {
		//read input
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = r.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int m = Integer.parseInt(tmp[1]);
        TimeSlot[] jobs = new TimeSlot[n];
        int lastTime = 0;
        for (int i = 0; i < n; i++) {
            tmp = r.readLine().split(" ");
            jobs[i] = new TimeSlot(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]), i);
            if(lastTime < jobs[i].a + jobs[i].b + m) {
            	lastTime = jobs[i].a + jobs[i].b + m;
            }
        }
        
        //sort jobs by start time
        Arrays.sort(jobs, new Comparator<TimeSlot>() {
            @Override
            public int compare(TimeSlot x, TimeSlot y) {
                return x.a - y.a;
            }
        });
        
        //iterate through jobs
        PriorityQueue<TimeSlot> q = new PriorityQueue<>(n, new Comparator<TimeSlot>() {
			public int compare(TimeSlot o1, TimeSlot o2) {
				return o1.a + o1.b - o2.a - o2.b;
			}
		});
        int machines = 0;
        Queue<Integer> freeMachines = new LinkedList<Integer>();
        for(TimeSlot job: jobs) {
            while(!job.matched && !q.isEmpty() && q.peek().a + q.peek().b <= job.a) {
                TimeSlot t = q.poll();
                if(t.a + t.b + m >= job.a) {
                	job.matched = true;
                	job.machine = t.machine;
                }
                else {
                	freeMachines.add(t.machine);
                }
            }
            if(!job.matched) {
           		job.machine = freeMachines.isEmpty() ? machines++ : freeMachines.poll();
            }
            q.add(job);
        }
        
        //create image
        int barHeight = 16;
        while(barHeight > 4 && barHeight * machines > 1000) {
        	barHeight /= 2;
        }
        while(barHeight > 1 && barHeight * machines > 10000) {
        	barHeight /= 2;
        }
        double widthScale = lastTime/1920.0;
		BufferedImage image = new BufferedImage((int) (lastTime/widthScale), barHeight * machines, BufferedImage.TYPE_INT_RGB);
		Graphics2D graphics = image.createGraphics();
		graphics.setFont(graphics.getFont().deriveFont((float) barHeight).deriveFont(Font.BOLD));
		
	    //draw machines
	    for (int i = 0; i < machines; i++) {
    		graphics.setColor(Color.GRAY);
        	graphics.fillRect(0, barHeight*i, (int) (lastTime/widthScale), barHeight);
		}
	    
		//draw jobs
        for(TimeSlot job: jobs) {
        	//active login
    		graphics.setColor(Color.YELLOW);
        	graphics.fillRect((int) (job.a/widthScale), barHeight*job.machine, (int) ((job.b + m)/widthScale), barHeight);

        	//job
    		graphics.setColor(job.matched ? Color.GREEN : Color.RED);
        	graphics.fillRect((int) (job.a/widthScale), barHeight*job.machine, (int) (job.b/widthScale), barHeight);
        	
        	//id
    		graphics.setColor(Color.BLACK);
    		graphics.drawString(job.id + "", (int) (job.a/widthScale), barHeight*(job.machine+1));
        }
		
        //print image
		ImageIO.write(image, "png", System.out);
	}

	static class TimeSlot {
        int a, b, id, machine;
        boolean matched;
        public TimeSlot(int a, int b, int id) {
            this.a = a;
            this.b = b;
            this.id = id;
        }
    }
}
