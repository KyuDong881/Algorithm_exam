import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main_14950_krus {
	
	static int N,M,t;
	static ArrayList<Node> info;
	static StringTokenizer st;
	static int[] parent;
	static int scary,answer;
	static class Node {
		int start;
		int dest;
		int cost;
		public Node(int start,int dest,int cost) {
			this.start=start;
			this.dest=dest;
			this.cost=cost;
		}
	}
	
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		t=Integer.parseInt(st.nextToken());
		info = new ArrayList<>();
		parent = new int[N+1];
		for(int i=1;i<=N;i++) {
			parent[i]=i;
		}
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int dest = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			info.add(new Node(start, dest, cost));
			info.add(new Node(dest, start, cost));
		}
		
		Collections.sort(info, new Comparator<Node>() {
			@Override
			public int compare(Node o1, Node o2) {
				return o1.cost-o2.cost;
			}
		});
		
		for(int i=0;i<info.size();i++) {
			int cost = info.get(i).cost;
			int start = info.get(i).start;
			int dest = info.get(i).dest;
			
			if(check(start,dest)==false) {
				union(start,dest);
				answer+=cost+scary;
				scary+=t;
			}
		}
		
		System.out.println(answer);
		
		
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
