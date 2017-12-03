import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

/*
 * 
 *  this solution forgets to sort the input
 */
public class EgorNoSort {


	public static void main(String[] args) throws Exception {
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 String[] line=reader.readLine().split(" ");
		 int n=Integer.parseInt(line[0]);
		 int m=Integer.parseInt(line[1]);
		
		 
		 Session[] sessions=new Session[n];
		 for(int i=0;i<n;i++)
			 sessions[i]=new Session(reader.readLine());
		 
		 
		 //simulate the process;
		 //Arrays.sort(sessions); sortig forgotten
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
