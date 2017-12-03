import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

/*
 * 
 *  simulating the log-on/log off process with the help of priority queue:
 *   
 *  finding the next event of freeing a computer in log(n)
 *  
 *  running time O(n logn)
 */
public class Egor {


	public static void main(String[] args) throws Exception {
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 String[] line=reader.readLine().split(" ");
		 int n=Integer.parseInt(line[0]);
		 int m=Integer.parseInt(line[1]);
		 
		 Session[] sessions=new Session[n];
		 for(int i=0;i<n;i++)
			 sessions[i]=new Session(reader.readLine());
		 
		 
		 //simulate the process;
		 Arrays.sort(sessions);
		 Computers coms=new Computers(m);
		 int cnt=0;
		 for(Session s:sessions)
			 if(!coms.addSessionReturnNewLogInNeeded(s))
				 cnt++;
		 
		 System.out.println(cnt);
		 
	}
	
	static class Session implements Comparable<Session>{
		
		int start;
		int end;
		
		Session(String line){
			String[] ss=line.split(" ");
			start=Integer.parseInt(ss[0]);
			end=start+Integer.parseInt(ss[1])-1;
		}

		@Override
		public int compareTo(Session arg0) {
			return start-arg0.start;
		}
		
	}

	
	static class Computers{
		int minutesTilLogOff;
		PriorityQueue<Integer> sessions;
		
		Computers(int minutesTilLogOff){
			sessions=new PriorityQueue<Integer>();
			this.minutesTilLogOff=minutesTilLogOff+1;
		}
		
		boolean addSessionReturnNewLogInNeeded(Session ses){
			while(!sessions.isEmpty()){
				int nextEnd=sessions.peek();
				if(nextEnd>=ses.start){
					sessions.add(ses.end);
					return true;
				}
				sessions.poll();
				if(nextEnd+minutesTilLogOff>=ses.start){
					sessions.add(ses.end);
					return false;//no new log on needed!
				}
			}
			sessions.add(ses.end);
			return true;
		}
	}

}
