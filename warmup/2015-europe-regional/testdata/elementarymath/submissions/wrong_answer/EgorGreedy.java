import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeSet;
/*
 * 
 * the most obvious solution: bipartite matching (with hopcroft-karp)
 * 
 */


/* Uses the following greedy strategy:
 *     -take first the node with the minimal number of edges pair it with the neighbor with the minimal number of edges.
 *     -remove both nodes, update the graph
 *     
 *     if an equation has no neighbors and is not paired -> impossible
 *     
 *     Running time O(N log(N))
 * 
 */


public class EgorGreedy {
	
	private static class Node implements Comparable<Node>{
		int pos;
		int value;
		public Node(int pos, int value){
			this.pos=pos;
			this.value=value;
		}
		@Override
		public int compareTo(Node arg0) {
			if(value<arg0.value)
				return -1;
			if(value==arg0.value)
				return 0;
			return 1;
		}
	  }
	/**
	 * @param args
	 */
	public static void main(String[] args)  throws Exception {
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 int N=Integer.parseInt(reader.readLine());
		 int gSize=N*4;
		 TreeSet<Integer>[] graph=new TreeSet[gSize];
		 for(int i=0;i<gSize;i++)
			 graph[i]=new TreeSet<Integer>();
		 Map<Long, Integer> res2id=new HashMap<Long, Integer>();
		 long[][] equations=new long[N][];
		 
		 for(int i=0;i<N;i++){
			 String[] zs=reader.readLine().split(" ");
			 long a=Integer.parseInt(zs[0]);
			 long b=Integer.parseInt(zs[1]);
			 equations[i]=new long[]{a,b};
			 long[] possible={a+b,a-b,a*b};
			 for(long result:possible){
				 Integer index=res2id.get(result);
				 if(index==null){
					 index=res2id.size()+N;
					 res2id.put(result, index);
				 }
				 graph[i].add(index);
				 graph[index].add(i);
			 }
		 }
		 //System.out.println("Map: "+res2id);
		 //System.out.println("Graph"+Arrays.toString(graph));
		 
		 int ALL=N+res2id.size();
		 int[] cnts=new int[ALL];
		 PriorityQueue<Node> queue=new PriorityQueue<Node>();
		 for(int i=0;i<ALL;i++){
			 cnts[i]=graph[i].size();
			 queue.add(new Node(i, cnts[i]));
		 }	 
		 String[] output=new String[N];
		 while(!queue.isEmpty()){
			 Node current=queue.poll();
		     //System.out.println("Polled: "+current.pos+" "+current.value);
		     //System.out.println(Arrays.toString(cnts));
		     
			 if(current.value!=cnts[current.pos])//old value
				 continue;
			 if(graph[current.pos].size()==0){
				 if(current.pos>=N)
					  continue;
				 else{
					 System.out.println("impossible");
					 return;
				 }
			 }
			 //find greedy the best 
			 int min=Integer.MAX_VALUE;
			 int bestIndex=-1;
			 //System.out.println("candidates "+graph[current.pos]);
			 for(int candidate:graph[current.pos]){
				 if(cnts[candidate]<min){
					 bestIndex=candidate;
					 min=cnts[candidate];
				 }
			 }
			 //reconstruct the equation:
			 int eq=Math.min(bestIndex, current.pos);
			 int index=Math.max(bestIndex, current.pos);

			 long a=equations[eq][0];
			 long b=equations[eq][1];
			 String op="*";
			 long result=a*b;
			 //System.out.println("could be +?"+res2id.get(a+b));
			 if(res2id.get(a+b)==index){
				 op="+";
				 result=a+b;
			 }
			 //System.out.println("could be -?"+res2id.get(a-b)+" searched for "+index);
			 if(res2id.get(a-b)==index){
				 op="-";
				 result=a-b;
			 }
			output[eq]=a+op+b+"="+result;
			
			//System.out.println(output[eq]);
			
			
			//remove the pair from neighbors connections
			int[] toRemove=new int[]{eq, index};
			//System.out.println("TorRemove "+eq+" "+(index));
			for(int rem:toRemove){
				cnts[rem]=-1;
				for(int neighbour: graph[rem]){
					graph[neighbour].remove(rem);
					cnts[rem]--;
					if(cnts[rem]>=0)
						queue.offer(new Node(neighbour, cnts[rem]));
				}
					
			}
			 
		 }
		 
		 for(String s:output)
			 System.out.println(s);

	}
	


}
