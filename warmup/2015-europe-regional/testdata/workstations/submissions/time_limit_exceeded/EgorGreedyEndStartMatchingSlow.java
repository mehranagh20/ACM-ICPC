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
public class EgorGreedyEndStartMatchingSlow {

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
    		int index=Arrays.binarySearch(vals, to+1);//+1 needed otherwise somewhere in the middle if all elements == to
    		if(index<0)
    			index=-index-2;//if to+1 too big, than take the element prior to it
    		
    		while(index>=0 && vals[index]>=from){
    			if(vals[index]<=to && !used[index]){
    				used[index]=true;
    				return true;
    			}
    			index--;
    		}
    		return false;//not found	
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
