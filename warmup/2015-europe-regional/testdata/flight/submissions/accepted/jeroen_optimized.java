import java.util.*;
import java.io.*;

public class jeroen_optimized {
	static int EARTH_RADIUS = 6370;
	public static double eps = 1e-6;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int C = sc.nextInt();
		Continent[] cont = new Continent[C];
		for(int i = 0; i < C; i++) {
			int N = sc.nextInt();
			Point[] pts = new Point[N];
			for(int j = 0; j < N; j++)
				pts[j] = new Point(sc.nextInt(), sc.nextInt());
			cont[i] = new Continent(pts);
		}
		
		int M = sc.nextInt();
		Vec3[] route = new Vec3[M];
		for(int i = 0; i < M; i++)
			route[i] = new Point(sc.nextInt(), sc.nextInt()).toVec();
		
		double L = 0;
		double W = 0;
		boolean land = true;
		for(int k = 0; k < route.length - 1; k++) {
			// Find intersection points
			Vec3 cur = route[k];
			Vec3 nextv = route[k+1];
			ArrayList<Double> inters = new ArrayList<Double>();
			for(int i = 0; i < C; i++) {
				for(int j = 0; j < cont[i].pts.length; j++) {
					Vec3 p1 = cont[i].pts[j];
					Vec3 p2 = cont[i].pts[(j+1)%cont[i].pts.length];
					Vec3 int2 = intersection(cur, nextv, p1, p2);
					if(int2 != null) {
						double dist2 = dst(cur, int2);
						inters.add(dist2);
					}
				}
			}
			// Update distances
			Collections.sort(inters);
			double prevd = 0;
			for(int i = 0; i < inters.size(); i++) {
				if(!land) W += inters.get(i) - prevd;
				prevd = inters.get(i);
				land ^= true;
			}
			double dist = dst(cur, nextv);
			if(!land) W += dist - prevd;
			L += dist;
		}
		System.out.println(L + " " + (100*W/L));
	}
	
	public static double dst(Vec3 A, Vec3 B) {
		return Math.acos(Vec3.dot(A,B) / A.norm() / B.norm()) * EARTH_RADIUS;
	}
	
	// Get intersection point of A -- B and C -- D
	public static Vec3 intersection(Vec3 A, Vec3 B, Vec3 C, Vec3 D) {
		// Ternary search for intersection point
		double low = 0;
		double up = 1;
		Vec3 ans = null;
		double fullDst = dst(A,B);
		for(int i = 0; i < 40; i++) {
			double f1 = (low + low + up) / 3;
			double f2 = (low + up + up) / 3;
			
			// Problem statement guarentees intersections are never closer than
			// 0.1 km from some point, so then we are sure there is no intersection
			if(f1 * fullDst < 0.1) break;
			if(f2 * fullDst > fullDst - 0.1) break;
			Vec3 v1 = pointOnVec(C,D,f1);
			Vec3 v2 = pointOnVec(C,D,f2);
			double diff1 = Math.abs(fullDst - dst(v1,A) - dst(v1,B));
			double diff2 = Math.abs(fullDst - dst(v2,A) - dst(v2,B));
			
			if(diff1 < diff2) {
				up = f2;
				if(diff1 < eps)
					ans = v1;
			}
			else {
				low = f1;
				if(diff2 < eps)
					ans = v2;
			}
		}
		return ans;
	}
	
	// Point on certain fraction between A and B
	// 0 <= frac <= 1
	private static Vec3 pointOnVec(Vec3 A, Vec3 B, double frac) {
		double x = frac * (B.x - A.x) + A.x;
		double y = frac * (B.y - A.y) + A.y;
		double z = frac * (B.z - A.z) + A.z;
		return new Vec3(x,y,z);
	}
}

class Point {
	public int lat, lon;
	
	public Point(int lat, int lon) {
		this.lat = lat;
		this.lon = lon;
	}
	
	public Vec3 toVec() {
		double y = Math.sin(toRad(lat));
		double r = Math.cos(toRad(lat));
		double x = Math.sin(toRad(lon)) * r;
		double z = Math.cos(toRad(lon)) * r;
		return new Vec3(x, y, z);
	}
	
	private static double toRad(int degree) {
		return Math.PI * degree / 180.0;
	}
}

class Vec3 {
	public double x, y, z;
	
	public Vec3(double x, double y, double z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public static double dot(Vec3 a, Vec3 b) {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	
	public double norm() {
		return Math.sqrt(dot(this,this));
	}
}

class Continent {
	public Vec3[] pts;
	
	public Continent(Point[] pts) {
		this.pts = new Vec3[pts.length];
		for(int i = 0; i < pts.length; i++)
			this.pts[i] = pts[i].toVec();
	}
}