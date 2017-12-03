import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.TreeSet;
/*
 * 
 * the most obvious solution: bipartite matching (with hopcroft-karp)
 * 
 */

public class EgorHK {

	/**
	 * @param args
	 */
	public static void main(String[] args)  throws Exception {
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 int N=Integer.parseInt(reader.readLine());
		 int gSize=N*4+2;
		 TreeSet<Integer>[] graph=new TreeSet[gSize];
		 for(int i=0;i<gSize;i++)
			 graph[i]=new TreeSet<Integer>();
		 Map<Long, Integer> res2id=new HashMap<Long, Integer>();
		 long[][] equations=new long[N][];
		 
		 for(int i=0;i<N;i++){
			 graph[gSize-2].add(i);
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
				 graph[index].add(gSize-1);
			 }
		 }
		 
		 HopcroftKarp solver=new HopcroftKarp();
		 
		 int matched=solver.matchingHopcroftKarp(graph, gSize-2, gSize-1);
		 
		 
		 
		 if(matched!=N)
			 System.out.println("impossible");
		 else{
			 String[] output=new String[N];
			 for(int index:graph[gSize-1]){//for all matched result find the original equation
				 int eq=graph[index].first();
				 long a=equations[eq][0];
				 long b=equations[eq][1];
				 String op="*";
				 long result=a*b;
				 if(res2id.get(a+b)==index){
					 op="+";
					 result=a+b;
				 }
				 if(res2id.get(a-b)==index){
					 op="-";
					 result=a-b;
				 }
				output[eq]=a+op+b+"="+result;
			 }
			 for(String s:output)
				 System.out.println(s);
		 }
	}
	
	
	
	public static class HopcroftKarp {

		private Set<Integer>[] getBfsTree(Set<Integer>[] graph, int source, int target){
			int n=graph.length;
			int[] used=new int[n];
			Arrays.fill(used, -1);
			
			@SuppressWarnings("unchecked")
			Set<Integer>[] result=new Set[n];
			for(int i=0;i<n;result[i++]=new TreeSet<Integer>());
			Queue<Integer> q=new LinkedList<Integer>();
			
			used[source]=0;
			q.offer(source);
			while(!q.isEmpty()){
				int current=q.poll();
				if(current==target)
					return result;
				
				int currentDist=used[current];
				for(int next:graph[current]){
					if(used[next]==-1){
						used[next]=currentDist+1;
						q.offer(next);
					}
					if(used[next]==currentDist+1)
						result[current].add(next);
				}
			}
			//no path to target:
			return null;
		}
		
		private boolean dfs(Set<Integer>[] graph, Set<Integer>[] bfsTree, int source,  int target, boolean[] used){
			if(source==target)
				return true;
			
			used[source]=true;
			for(int next: bfsTree[source]){
				if(!used[next] && dfs(graph, bfsTree, next, target, used)){
					graph[source].remove(next);
					graph[next].add(source);
					return true;
				}
			}
			return false;
		}
	
		
		//matching with hopcroft-karp O(m*sqrt(n))
		public int matchingHopcroftKarp(Set<Integer>[] graph, int source, int target){
			int result=0;
			int n=graph.length;
			boolean[] used=new boolean[n];
			while(true){
				
				Set<Integer>[] bfsTree=getBfsTree(graph, source, target);
				if(bfsTree==null) 
					return result;

				
				Arrays.fill(used, false);
				while(dfs(graph, bfsTree, source, target, used))
					result++;
				
			}
			
		}
	}

}
