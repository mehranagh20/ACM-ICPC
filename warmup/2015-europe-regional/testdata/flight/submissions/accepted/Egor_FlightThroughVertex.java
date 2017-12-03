import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/*
this solution can get mixed up, if a flight goes straight trough a vertex of the continent -> it could confuse inside and outside during the sweep of the events on a flight segment

yet those test cases are excluded throught the constrains on the input data, so this solution should pass as well
*/

public class Egor_FlightThroughVertex {

	/**
	 * @param args
	 */
	
	public static void main(String[] args) throws IOException{
	  List<SphereSegment> coastline=new LinkedList<SphereSegment>();
	  BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		 
	    int nContinents=Integer.parseInt(reader.readLine());
	    for(int i=0;i<nContinents;i++){
	    	coastline.addAll(readPolygone(reader, true));
	    }
	    
	    List<SphereSegment> flight=readPolygone(reader, false);
	   
	    //System.out.println(flight);
	    
		 
	    double flightInRad=getWholeFlightAngle(flight);
	    double flightOverContinent=getAngleOverContinent(flight, coastline);
	    
	    
	    final double EARTH_RADIUS=6370.0;
	    
	    System.out.println(flightInRad*EARTH_RADIUS+" "+100.0*(1.0-flightOverContinent/flightInRad));
	}
	
	
	
	static List<SphereSegment> readPolygone(BufferedReader reader, boolean closedPolygone) throws IOException{
		List<SphereSegment> coastline=new LinkedList<SphereSegment>();
		String[] angles=reader.readLine().split(" ");
	    	SpherePoint start=SpherePoint.createFromAngles(angles[1], angles[2]);
	    	SpherePoint last=start;
	    	for(int j=3;j<angles.length;j+=2){
	    		SpherePoint current=SpherePoint.createFromAngles(angles[j], angles[j+1]);
	    		coastline.add(new SphereSegment(last, current));
	    		last=current;
	    	}
	    	if(closedPolygone)
	    		coastline.add(new SphereSegment(last, start));	
	    	
	    	return coastline;
	}
	
	
	static double getAngleOverContinent(List<SphereSegment> flight, List<SphereSegment> coastline){
		SphereSegment.Direction currentDir = SphereSegment.Direction.dIn;
		double result=0.0;
		for(SphereSegment flightSeg: flight){
			for(SphereSegment continentSeg: coastline)
				flightSeg.addSegmentToTimeLine(continentSeg);
			
			SphereSegment.Event segmentSweepResult=flightSeg.sweepTimeLine(currentDir);
			result+=segmentSweepResult.angle;
			currentDir=segmentSweepResult.direction;		
		}
		return result;
	}
	
	static double getWholeFlightAngle(List<SphereSegment> flight){
		double result=0.0;
		for(SphereSegment flightSeg: flight)
			result+=flightSeg.getRotationAngle();
		
		return result;
	}
	
	
	static class SpherePoint {
		
		static public double eps=1e-10;
		
	    private double x;
	    private double y;
	    private double z;
	    
	    static SpherePoint createFromAngles(String sTheta, String sPhi){
	    	
	    	int theta=Integer.parseInt(sTheta);
	    	int phi=Integer.parseInt(sPhi);
	    	
		double thetaRad=Math.toRadians(theta);
		double phiRad=Math.toRadians(phi);
		double z=Math.sin(thetaRad);
		double r=Math.cos(thetaRad);
		double x=r*Math.cos(phiRad);
		double y=r*Math.sin(phiRad);
			
		return new SpherePoint(x,y,z);
	    }

		public SpherePoint(double x, double y, double z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}
		
		public String toString(){
			return "["+x+","+y+","+z+"]";
		}
	    
		
		public double getNorm(){
			return Math.sqrt(x*x+y*y+z*z);
		}
		
		public void scale(double scalingFactor){
			x*=scalingFactor;
			y*=scalingFactor;
			z*=scalingFactor;
		}
		
		public void normalize(){
			scale(1.0/getNorm());
		}
		
		
		public void mirror(){
			x=-x;
			y=-y;
			z=-z;
		}
	    
		static double dotProduct(SpherePoint p1, SpherePoint p2){
			return(p1.x*p2.x+p1.y*p2.y+p1.z*p2.z);
		}
		
		static SpherePoint getRotation(SpherePoint from, SpherePoint to){
			double resX=from.y*to.z-from.z*to.y;
			double resY=-from.x*to.z+from.z*to.x;
			double resZ=from.x*to.y-from.y*to.x;
			SpherePoint result= new SpherePoint(resX,resY,resZ);
			result.normalize();
			result.scale(SpherePoint.getAngleBetween(from, to));
			
			return result;
		}
		
		static SpherePoint getRotationAxis(SpherePoint from, SpherePoint to){
			SpherePoint res=getRotation(from, to);
			res.normalize();
			return res;
		}
		
		static double getAngleBetween(SpherePoint p1, SpherePoint p2){
			double d=dotProduct(p1, p2)/p1.getNorm()/p2.getNorm();
			d=Math.max(-1.0, Math.min(1.0, d));
			return Math.acos(d);
		}
		
		static boolean sameHemisphere(SpherePoint p1, SpherePoint p2){
			return dotProduct(p1, p2)>0.0;
		}
		
		static boolean areSameRotationDirection(SpherePoint p1, SpherePoint p2){
			double dot=dotProduct(p1, p2);
			if(dot<0.0)
				return false;
			double diff=dot-p1.getNorm()*p2.getNorm();
			return Math.abs(diff)<eps;
		}
		


	}
	
	
	static class SphereSegment {
		
		//Intersection:
		
		SpherePoint from;
		SpherePoint to;
		
		SpherePoint rotation;
		
		public String toString(){
			return from.toString()+"->"+to.toString()+" = "+rotation.toString();
		}
		
		public SphereSegment(SpherePoint from, SpherePoint to) {
			super();
			this.from = from;
			this.to = to;
			rotation=SpherePoint.getRotation(from, to);
			
			events=new LinkedList<Event>();
		}
		
		
		private double getRotationAngle(){
			return SpherePoint.getAngleBetween(from, to);
		}
		
		private boolean onLine(SpherePoint p){
			return Math.abs(SpherePoint.dotProduct(rotation, p))<SpherePoint.eps;
		}
		
		private boolean onSegment(SpherePoint p){
			
			SpherePoint rotation2p=SpherePoint.getRotation(from, p);
			//System.out.println("onSphereRotation: "+rotation2p);
			if(!SpherePoint.areSameRotationDirection(rotation,rotation2p))
				return false;
			
			return rotation.getNorm()>=rotation2p.getNorm();
		}
		
		public static SpherePoint intersect(SphereSegment s1, SphereSegment s2){
			SpherePoint candidate=SpherePoint.getRotationAxis(s1.rotation,s2.rotation);
			//System.out.println("Intersection candidate: "+candidate);
			if(s1.onSegment(candidate) && s2.onSegment(candidate))
					return candidate;
			
			candidate.mirror();
			//System.out.println("Intersection candidate2: "+candidate);
			if(s1.onSegment(candidate) && s2.onSegment(candidate))
				return candidate;
			
			return null;
		}
		
		static enum Direction {dOut, dIn};
		
		public Direction goingInsideOrOutside(SphereSegment s){
			if(s.onLine(from))
				return SpherePoint.sameHemisphere(to, s.rotation)? Direction.dIn : Direction.dOut;
			else
				return SpherePoint.sameHemisphere(from, s.rotation)? Direction.dOut : Direction.dIn;
		}
		
		//"Timeline":
		
		static class Event implements Comparable<Event>{
			
			public Event(double angle, Direction direction) {
				super();
				this.angle = angle;
				this.direction = direction;
			}

			double angle;
			SphereSegment.Direction direction;
			
			public String toString(){
				return "[a: "+angle+", dir"+direction+"]";
			}
			
			@Override
			public int compareTo(Event other) {
				if(angle<other.angle)
					return -1;
				return 1;
			}	
		}
		
		LinkedList<Event> events;
		
		void addSegmentToTimeLine(SphereSegment s){
			SpherePoint inter=intersect(this, s);
			//System.out.println("Intersection between "+this+" and "+s+" at: "+inter);
			if(inter!=null)
				events.add(new Event(SpherePoint.getAngleBetween(from, inter), goingInsideOrOutside(s)));	
		}
		
		Event sweepTimeLine(Direction start){
			Event[] events=this.events.toArray(new Event[0]);
			Arrays.sort(events);
			//System.out.println("Events: "+Arrays.toString(events));
			Direction currentDir=start;
			double wayOverContinent=0.0;
			double last=0.0;
			for(int i=0;i<events.length;){
				Event curEvent=events[i];
                                //Here we go: if we are going through a vertix, the order of IN and OUT can get mixed up
				//if(i+1!=events.length){
				//	if(events[i+1].angle-curEvent.angle<SpherePoint.eps &&
				//	   events[i+1].direction!=curEvent.direction){
				//		i+=2;//they are canceling each other out
				//		continue;
				//	}	
				//}
				double dist=curEvent.angle-last;
				last=curEvent.angle;
				if(currentDir==Direction.dIn)
					wayOverContinent+=dist;
				currentDir=curEvent.direction;
				i++;		
			}
			
			if(currentDir==Direction.dIn)
				wayOverContinent+=getRotationAngle()-last;
			//System.out.println("result: "+new Event(wayOverContinent, currentDir));
			return new Event(wayOverContinent, currentDir);
		}
		
		

	}
	


}
