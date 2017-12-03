
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Stefan {

    public static void main(String[] args) throws IOException {
        //read input
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        String[] tmp = r.readLine().split(" ");
        int n = Integer.parseInt(tmp[0]);
        int m = Integer.parseInt(tmp[1]);
        TimeSlot[] jobs = new TimeSlot[n];
        for (int i = 0; i < n; i++) {
            tmp = r.readLine().split(" ");
            jobs[i] = new TimeSlot(Integer.parseInt(tmp[0]), Integer.parseInt(tmp[1]));
        }
        
        //sort jobs by start time
        Arrays.sort(jobs, new Comparator<TimeSlot>() {
            @Override
            public int compare(TimeSlot x, TimeSlot y) {
                return x.a - y.a;
            }
        });
        
        //iterate through jobs
        int saved = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(TimeSlot job: jobs) {
            boolean matched = false;
            while(!matched && !q.isEmpty() && q.peek()-m <= job.a) {
                int t = q.poll();
                matched = t >= job.a;
            }
            if(matched) {
                saved++;
            }
            q.add(job.a + job.b + m);
        }
        
        //print result
        System.out.println(saved);
    }

    static class TimeSlot {

        int a, b;

        public TimeSlot(int a, int b) {
            this.a = a;
            this.b = b;
        }

    }
}
