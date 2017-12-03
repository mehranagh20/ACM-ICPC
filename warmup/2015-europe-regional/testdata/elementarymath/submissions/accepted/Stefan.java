import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

/**
 * This is a solution to the elementarymath problem. We solve the corresponding
 * matching problem by computing a flow from an artificial source to equation
 * nodes to result nodes to an artificial target with all unit capacities.
 * 
 * @author Stefan Toman (toman@tum.de)
 */
public class Stefan {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		// read input
		int n = Integer.parseInt(in.readLine());

		// create nodes
		Node s = new Node();
		Node t = new Node();
		Node[] equations = new Node[n];
		long[] a = new long[n];
		long[] b = new long[n];
		Map<Long, Node> results = new HashMap<Long, Node>();
		for (int j = 0; j < n; j++) {
			equations[j] = new Node();

			String[] ab = in.readLine().split(" ");
			a[j] = Integer.parseInt(ab[0]);
			b[j] = Integer.parseInt(ab[1]);
			Edge es = new Edge(s, equations[j], 1, null);
			s.adj.add(es);
			equations[j].adj.add(es);

			// add
			if (!results.containsKey(a[j] + b[j])) {
				Node tn = new Node();
				results.put(a[j] + b[j], tn);
				Edge et = new Edge(tn, t, 1, null);
				tn.adj.add(et);
				t.adj.add(et);

			}
			Edge ep = new Edge(equations[j], results.get(a[j] + b[j]), 1, a[j]
					+ "+" + b[j] + "=" + (a[j] + b[j]));
			equations[j].adj.add(ep);
			results.get(a[j] + b[j]).adj.add(ep);

			// multiply
			if (!results.containsKey(a[j] * b[j])) {
				Node tn = new Node();
				results.put(a[j] * b[j], tn);
				Edge et = new Edge(tn, t, 1, null);
				tn.adj.add(et);
				t.adj.add(et);

			}
			Edge em = new Edge(equations[j], results.get(a[j] * b[j]), 1, a[j]
					+ "*" + b[j] + "=" + (a[j] * b[j]));
			equations[j].adj.add(em);
			results.get(a[j] * b[j]).adj.add(em);

			// subtract
			if (!results.containsKey(a[j] - b[j])) {
				Node tn = new Node();
				results.put(a[j] - b[j], tn);
				Edge et = new Edge(tn, t, 1, null);
				tn.adj.add(et);
				t.adj.add(et);

			}
			Edge esu = new Edge(equations[j], results.get(a[j] - b[j]), 1, a[j]
					+ "-" + b[j] + "=" + (a[j] - b[j]));
			equations[j].adj.add(esu);
			results.get(a[j] - b[j]).adj.add(esu);

			//triviality check
			if(results.size() < j) {
				System.out.println("impossible");
				return;
			}
		}

		// compute the matching
		if (maxflow(s, t) < n) {
			System.out.println("impossible");
		} else {
			// print matching
			for (int i = 0; i < n; i++) {
				for (Edge e : equations[i].adj) {
					if (e.x == 1 && e.s != null) {
						System.out.println(e.s);
					}
				}
			}
		}
	}

	private static int maxflow(Node source, Node target) {
		// find distances
		source.d = Node.nodes.size();
		target.d = 0;
		Queue<Node> bfs = new LinkedList<Node>();
		bfs.add(target);
		while (!bfs.isEmpty()) {
			Node t = bfs.poll();
			for (Edge e : t.adj) {
				Node x = e.otherNode(t);
				if (e.b == t && x.d == Integer.MAX_VALUE) {
					x.setD(t.d + 1);
					bfs.add(x);
				}
			}
		}

		// initialize
		Queue<Node> active = new LinkedList<Node>();
		for (Edge e : source.adj) {
			if (e.a == source) {
				e.addFlow(e.c);
				active.add(e.otherNode(source));
			}
		}

		// loop
		while (!active.isEmpty()) {
			Node t = active.poll();

			// push
			for (Edge e : t.adj) {
				Node x = e.otherNode(t);

				if (t.d == x.d + 1) {
					// starts at t
					if (e.a == t) {
						int v = Math.min(t.e, e.c - e.x);
						if (v > 0 && !active.contains(x) && x != source
								&& x != target) {
							active.add(x);
						}
						e.addFlow(v);
					}
					// ends at t
					else {
						int v = Math.min(t.e, e.x);
						if (v > 0 && !active.contains(x) && x != source
								&& x != target) {
							active.add(x);
						}
						e.addFlow(-v);
					}
				}
			}

			// relabel
			if (t.e > 0) {
				//gap heuristics
				if(Node.a.get(t.d) == 1) {
					for(Node n: Node.nodes) {
						if(n.d < t.d) {
							n.setD(t.d+1);
						}
					}
				}

				int newLabel = Integer.MAX_VALUE;
				for (Edge e : t.adj) {
					Node x = e.otherNode(t);

					// starts at t
					if (e.a == t) {
						if (e.x < e.c) {
							newLabel = Math.min(newLabel, x.d + 1);
						}
					}
					// ends at t
					else {
						if (0 < e.x) {
							newLabel = Math.min(newLabel, x.d + 1);
						}
					}
				}
				
				t.setD(newLabel);
				active.add(t);
			}
		}

		return target.e;
	}

	static class Edge {
		int c;// capacity
		int x;// value
		Node a, b;// start, end
		String s;

		public Edge(Node a, Node b, int c, String s) {
			super();
			this.a = a;
			this.b = b;
			this.c = c;
			this.s = s;
			x = 0;
		}

		public void addFlow(int t) {
			x += t;
			a.e -= t;
			b.e += t;
		}

		public Node otherNode(Node x) {
			return x == a ? b : a;
		}
	}

	static class Node {
		public static Set<Node> nodes = new HashSet<Node>();
		public static ArrayList<Integer> a = new ArrayList<Integer>();//array for gap heuristics
		int d;// distance label
		int e;// flow excess
		List<Edge> adj;// incident edges

		public Node() {
			super();
			adj = new LinkedList<Edge>();
			d = Integer.MAX_VALUE;
			e = 0;
			nodes.add(this);
		}

		public void setD(int d) {
			if(this.d != Integer.MAX_VALUE) {
				a.set(this.d, a.get(this.d)-1);
			}
			this.d = d;
			while(a.size() <= d) {
				a.add(0);
			}
			a.set(d, a.get(d)+1);
		}
	}
}
