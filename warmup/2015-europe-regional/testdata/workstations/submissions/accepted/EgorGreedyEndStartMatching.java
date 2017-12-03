import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.*;

/*
 * 
 *  matches free times of the computers with login and starts of the session
 *   
 * do it in greedy fashion: for every log off matches the nearest possible 
 *    (that means prior to log off and but not more than m minutes) start of the session
 *    
 *  start matching with the latest end, than second last and so on...
 *  
 *  running time O(n logn)
 */
public class EgorGreedyEndStartMatching {


	public static void main(String[] args) throws Exception {
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 String[] line=reader.readLine().split(" ");
		 int n=Integer.parseInt(line[0]);
		 int m=Integer.parseInt(line[1]);
		 
		 int[] endTimes=new int[n];
		 NavigableSet<Start> starts=new TreeSet<Start>(); 
		 for(int i=0;i<n;i++){
			 String[] ss=reader.readLine().split(" ");
			 int from=Integer.parseInt(ss[0]);
			 int duration=Integer.parseInt(ss[1]);
			 endTimes[i]=from+duration+m;
			 starts.add(new Start(from, i));
		 }
			
		 //match end with the nearest start
		 Arrays.sort(endTimes);
		// System.out.println(Arrays.toString(endTimes));
		 int cnt=0;
		 for(int i=i=n-1;i>=0;i--){
			 //System.out.println(endTimes[i]+" "+starts);
			 Start nearestStart=starts.floor(new Start(endTimes[i], n+1));
			 if(nearestStart==null)
				 continue;
			 if(nearestStart.startTime>=endTimes[i]-m){
				 cnt++;
				 starts.remove(nearestStart);
			 }
			// System.out.println(cnt+" "+nearestStart);
		 }
		 
		 System.out.println(cnt);
		 
	}
	
	static class Start implements Comparable<Start>{
		int startTime;
		int index;
		
		Start(int startTime, int index){
			this.startTime=startTime;
			this.index=index;
		}
		
		public int compareTo(Start other){
			if(startTime==other.startTime)
				return index-other.index;
			
			return startTime-other.startTime;
		}
		
		public boolean equals(Start obj) {
			return startTime==obj.startTime && index==obj.index;
		}
		
		public String toString(){
			return "["+startTime+","+index+"]";
		}
	}

}
