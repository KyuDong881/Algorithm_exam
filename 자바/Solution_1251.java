import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;



public class Solution_1251 {

	static int T,N;
	static StringTokenizer stx;
	static StringTokenizer sty;
	static ArrayList<Node> info;
	static double answer,E;
	static int[] parent;
	static double[] x,y;
	
	static class Node {
		int start;
		int dest;
		double cost;

		public Node(int start, int dest, double cost) {
			this.start = start;
			this.dest = dest;
			this.cost = cost;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++) {
			answer=0;
			info = new ArrayList<>();
			N=Integer.parseInt(br.readLine());
			x=new double[N+1];
			y=new double[N+1];
			
			stx=new StringTokenizer(br.readLine());
			sty=new StringTokenizer(br.readLine());
			
			for(int i=1;i<=N;i++) {
				x[i]=Double.parseDouble(stx.nextToken());
				y[i]=Double.parseDouble(sty.nextToken());
			}
			E=Double.parseDouble(br.readLine());
			
			parent = new int[N+1];
			for(int i=1;i<=N;i++) {
				parent[i]=i;
			}
			
			solve();
			System.out.printf("#%d ",tc);
			System.out.println(Math.round(answer*E));
			
		}
	}
	
	private static void solve() {
		for(int i=1;i<=N;i++) {
			for(int j=i+1;j<=N;j++) {
				double dist = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				info.add(new Node(i,j,dist));
			}
		}
		
		Collections.sort(info,new Comparator<Node>() {
			@Override
			public int compare(Node o1, Node o2) {
				if(o1.cost-o2.cost>=0) return 1;
				return -1;
			}
		});
		
		for(int i=0;i<info.size();i++) {
			double cost = info.get(i).cost;
			int start = info.get(i).start;
			int dest = info.get(i).dest;
			
			if(!check(start, dest)) {
				union(start,dest);
				answer+=cost;
			}
		}

		
	}

	private static int find_parent(int x) {
		if(parent[x]==x) return x;
		else return parent[x]=find_parent(parent[x]);
	}
	
	private static void union(int x,int y) {
		x=find_parent(x);
		y=find_parent(y);
		if(x!=y) {
			parent[y]=x;
		}
	}
	
	private static boolean check(int x,int y) {
		if(find_parent(x)==find_parent(y)) return true;
		else return false;
	}

}
