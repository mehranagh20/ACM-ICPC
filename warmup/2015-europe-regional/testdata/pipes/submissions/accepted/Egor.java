import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


public class Egor {

	public static void main(String[] args) throws IOException {
		 BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 String[] ss=reader.readLine().split(" ");
		 int W=Integer.parseInt(ss[0]);
		 int P=Integer.parseInt(ss[1]);
		 
		 Point[] wells=new Point[W];
		 for(int i=0;i<W;i++)
			 wells[i]=new Point(reader.readLine());
		 
		 Segment[] segs=new Segment[P];
		 for(int i=0;i<P;i++)
			 segs[i]=new Segment(wells, reader.readLine());
		 
		 
		 List<Integer>[] graph=new List[P];
		 for(int i=0;i<P;i++)
			 graph[i]=new LinkedList<Integer>();
		 
		 for(int i=0;i<P;i++)
			 for(int j=i+1;j<P;j++)
				 if(Segment.doIntersect(segs[i], segs[j])){
					 graph[i].add(j);
					 graph[j].add(i);
				 }
		 
		 if(twoColorbar(graph))
			 System.out.println("possible");
		 else
			 System.out.println("impossible");

	}
	
	
	
	static boolean twoColorbar(List<Integer>[] graph){
		int n=graph.length;
		int[] color=new int[n];
		Arrays.fill(color, -1);
		for(int i=0;i<n;i++)
			if(color[i]==-1){
				color[i]=0;
				Queue<Integer> q=new LinkedList<Integer>();
				q.offer(i);
				while(!q.isEmpty()){
					int cur=q.poll();
					int nextColor=color[cur]^1;
					for(int next: graph[cur]){
						if(color[next]==-1){
							color[next]=nextColor;
							q.offer(next);
							continue;
						}
						if(color[next]!=nextColor)
							return false;
					}
				}
			}
		
		return true;
	}
	
	static class Point{
		int x; int y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
		public Point(String line){
			String[] ss=line.split(" ");
			x=Integer.parseInt(ss[0]);
			y=Integer.parseInt(ss[1]);
		}
		
	}
	
	static class Segment{
		Point well;
		Point end;
		Segment(Point[] wells, String line){
			String[] ss=line.split(" ");
			int wellIndex=Integer.parseInt(ss[0])-1;
			int x=Integer.parseInt(ss[1]);
			int y=Integer.parseInt(ss[2]);
			
			well=wells[wellIndex];
			end=new Point(x,y);
		}
		
		
		private static boolean separated(Segment s1, Segment s2){
			long dx=-(s1.end.y-s1.well.y);
			long dy=s1.end.x-s1.well.x;
			
			long d1=s1.end.x*dx+s1.end.y*dy;
			
			long a=s2.end.x*dx+s2.end.y*dy;
			long b=s2.well.x*dx+s2.well.y*dy;
			
			return (a<d1 && b<d1) || (a>d1 && b>d1);
		}
		static boolean doIntersect(Segment s1, Segment s2){
			if(s1.well==s2.well)
				return false;
			return (!separated(s1,s2) && !separated(s2,s1));
		}
	}

}
