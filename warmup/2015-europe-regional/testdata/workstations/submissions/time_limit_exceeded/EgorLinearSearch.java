import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.*;

/*
 * 
 *  simulates the event with a slow priority queue - the add-operation runs in O(n), thus:  
 *  running time O(n*n)
 */
public class EgorLinearSearch {


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

	static class SlowPriorityQueue{
		List<Integer> list;
		SlowPriorityQueue(){
			list=new LinkedList<Integer>();
		}
		
		void add(int i){
		    ListIterator<Integer> it=list.listIterator();
		    while(it.hasNext()){
		    	if(it.next()>i){
		    		it.previous();
		    		it.add(i);
		    		return;
		    	}
		    }
		    it.add(i);
		}
		
		int peek(){
			return list.get(0);
		}
		
		int poll(){
			return list.remove(0);
		}
		
		boolean isEmpty(){
			return list.isEmpty();
		}
	}
	
	static class Computers{
		int minutesTilLogOff;
		SlowPriorityQueue sessions;
		
		Computers(int minutesTilLogOff){
			sessions=new SlowPriorityQueue();
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
