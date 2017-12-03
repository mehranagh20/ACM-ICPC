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
 *  running time O(n*n) because it does not uses tree but a sorted lazy array 
 *          in which deleted elements are only marked
 */
public class EgorGreedyEndStartMatchingSlowForward {

    static class LookUp{
    	int[] vals;
    	boolean[] used;
    	int current;
    	
    	LookUp(int n){
    		vals=new int[n];
    		used=new boolean[n];
    		current=0;
    	}
    	
    	void pushBack(int val){
    		vals[current++]=val;
    		if(current==vals.length)
    			Arrays.sort(vals);
    	}
    	
    	boolean removeBiggestInTheRange(int from, int to){
    		int index=Arrays.binarySearch(vals, from-1);// -1 needed
    		if(index<0)
    			index=-index-1;//- 2 would not be a problem, because of the check vals[index]>=from latter on
    		
    		//Ok, not that nifty, but we are searching for the last starting with the first:)
    		int lastIndex=-1;
    		while(index>=0 && index<vals.length && vals[index]<=to){
    			if(vals[index]>=from && !used[index]){
    				lastIndex=index;
    			}
    			index++;
    		}
    		
    		if(lastIndex==-1)
    			return false;//not found
    		else{
    			used[lastIndex]=true;
    			return true;
    		}
    	}
    }
    
    
	public static void main(String[] args) throws Exception {
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 String[] line=reader.readLine().split(" ");
		 int n=Integer.parseInt(line[0]);
		 int m=Integer.parseInt(line[1]);
		 
		 int[] endTimes=new int[n];
		 LookUp starts=new LookUp(n);
		 for(int i=0;i<n;i++){
			 String[] ss=reader.readLine().split(" ");
			 int from=Integer.parseInt(ss[0]);
			 int duration=Integer.parseInt(ss[1]);
			 endTimes[i]=from+duration+m;
			 starts.pushBack(from);
		 }
			
		 //match end with the nearest start
		 Arrays.sort(endTimes);
		// System.out.println(Arrays.toString(endTimes));
		 int cnt=0;
		 for(int i=i=n-1;i>=0;i--)
			 if(starts.removeBiggestInTheRange(endTimes[i]-m, endTimes[i]))
					 cnt++;
		 
		 System.out.println(cnt);
		 
	}


}
