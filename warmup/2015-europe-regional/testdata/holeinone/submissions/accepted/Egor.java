import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class Egor {

	public static void main(String[] args) throws IOException {
		Scanner in=new Scanner(System.in);
		 
		int n=in.nextInt();
		
		orignalScene=new Scenery(n, in);
		
		int best=-1;
		
		for(int set=0;set<(1<<n);set++){
			hitWalls=new int[Integer.bitCount(set)];
			int cnt=0;
			for(int i=0;i<n;i++){
				if((set&(1<<i))!=0)
					hitWalls[cnt++]=i;
			}
			double maxLength=bruteForcePermutations();
			if(maxLength!=-1.0)
				best=Math.max(best, hitWalls.length);
		}
		
		if(best==-1)
			System.out.println("impossible");
		else
			System.out.println(best);
	}
	
	static Scenery orignalScene;
	static int[] hitWalls;
	
	static boolean[] used;
	static int[] perm;
	static double best;
    static  double bruteForcePermutations(){
		perm=new int[hitWalls.length];
		used=new boolean[hitWalls.length];
		best=-1.0;
		
		doPermut(0);
		
		return best;
		
	}
    
    static void doPermut(int current){
    	if(current==used.length){
    		int[] order=new int[perm.length];
    		for(int i=0;i<perm.length;i++)
    			order[i]=hitWalls[perm[i]];
    		Scenery copy=orignalScene.clone();
    		copy.mirrorOnWalls(order);
    		Point direction=copy.goal;
    		copy=orignalScene.clone();
    		double val=copy.getLengthToGoal(order, direction);
//    		if(val>best){
//    			System.out.println(best+"->"+val+" by "+Arrays.toString(order));
//    			System.out.println("direction "+direction);
//    		}
    		best=Math.max(best, val);
    	}
    	else
    		for(int i=0;i<used.length;i++)
    			if(!used[i]){
    				used[i]=true;
    				perm[current]=i;
    				doPermut(current+1);
    				used[i]=false;
    			}
    }
	
	
	
	static class Scenery{
		Point goal;
		Wall[] walls;
		boolean[] vanished;
		
		
		private Scenery(int n){
			walls=new Wall[n];
			vanished=new boolean[n];
		}
		
		Scenery(int n, Scanner in){ 
			walls=new Wall[n];
			vanished=new boolean[n];
			int x=in.nextInt();
			int y=in.nextInt();
			goal=new Point(x, y);
			for(int i=0;i<n;i++){
				int xV=in.nextInt();
				int yV=in.nextInt();
				int xW=in.nextInt();
				int yW=in.nextInt();
				walls[i]=new Wall(new Point(xV, yV), new Point(xW, yW));
			}		
		}
		public String toString(){
			String s=goal.toString()+"\n";
			for(int i=0;i<walls.length;i++){
				s=s+walls[i].p1.toString()+" "+walls[i].p2.toString()+" "+(vanished[i]?"vanished":"")+"\n";
			}
				
			
			return s;
		}
		
		public Scenery clone(){
			Scenery res=new Scenery(walls.length);
			res.goal=goal.clone();
			for(int i=0;i<walls.length;i++)
				res.walls[i]=walls[i].clone();
			
			return res;
		}
		
		void mirrorOnWalls(int[] wallIDs){
			for(int i:wallIDs)
				mirrorOnWall(i);
		}
		
		void mirrorOnWall(int wallIndex){
			vanished[wallIndex]=true;
			Wall mirror=walls[wallIndex];
			
			mirror.mirror(goal);
			for(int i=0;i<walls.length;i++)
				if(!vanished[i])
					mirror.mirror(walls[i]);
		}
		
		
		double getLengthToGoal(int[] wallIDs, Point direction){
			
			double last=0.0;
			for(int i:wallIDs){
				double nextHit=walls[i].hitInXCoordinate(direction);
				if(nextHit==-1.0  || nextHit<last)
					return -1.0;
				
				vanished[i]=true;
				for(int j=0;j<walls.length;j++){
					if(!vanished[j]){
						double hit=walls[j].hitInXCoordinate(direction);
						if(hit>last && hit<nextHit)
							return -1.0;
					}
				}
				
				//everything O, mirror:
				mirrorOnWall(i);
				last=nextHit;
			}
			
			double maxDist=direction.x*direction.x+direction.y*direction.y;
			//check last segment:
			for(int j=0;j<walls.length;j++){
				if(!vanished[j]){
					double hit=walls[j].hitInXCoordinate(direction);
					//System.out.println("last hit: "+hit);
					if(hit>last && hit<maxDist)
						return -1.0;
				}
			}
			
			
			//System.out.println("direction: "+direction+" "+(direction.x*direction.x+direction.y*direction.y));	
			return Math.sqrt(direction.x*direction.x+direction.y*direction.y);
		}
		
	}
	
	
	static class Wall{
		Point p1;
		Point p2;
		
		int mirrorPlane;
		

		void mirror(Point p){
			if(mirrorPlane==0)
				p.x=p1.x-(p.x-p1.x);
			else
				p.y=p1.y-(p.y-p1.y);
		}
		
		void mirror(Wall wall){
			mirror(wall.p1);
			mirror(wall.p2);
		}
		
		Wall(Point p1, Point p2){
			this.p1=p1;
			this.p2=p2;
			if(p1.x==p2.x)
				mirrorPlane=0;
			else
				mirrorPlane=1;
		}
		
		public Wall clone(){
			Point nP1=p1.clone();
			Point nP2=p2.clone();
			return new Wall(nP1,nP2);
		}
		
		private static boolean separated(Wall s1, Wall s2){
			long dx=-(s1.p1.y-s1.p2.y);
			long dy=s1.p1.x-s1.p2.x;
			
			long d1=s1.p1.x*dx+s1.p1.y*dy;
			
			long a=s2.p1.x*dx+s2.p1.y*dy;
			long b=s2.p2.x*dx+s2.p2.y*dy;
			
			return (a<d1 && b<d1) || (a>d1 && b>d1);
		}
		
		double hitInXCoordinate(Point goal){
			Wall other=new Wall(new Point(0,0), goal);
			boolean hit = !separated(this, other) && !separated(other, this);
			if(!hit)
				return -1.0;
			
			if(mirrorPlane==0){
				double y=goal.y/((double)goal.x)*p1.x;
				return p1.x*p1.x+y*y;
			}
			else{
				double x=goal.x/((double)goal.y)*p1.y;
				return p1.y*p1.y+x*x;
			}
		}
		
	}

	static class Point{
		int x;
		int y;
		
		Point(int x, int y){
			this.x=x;
			this.y=y;
		}
		
		public Point clone(){
			return new Point(x,y);
		}
		
		public String toString(){
			return "("+x+","+y+")";
		}
	}
}
