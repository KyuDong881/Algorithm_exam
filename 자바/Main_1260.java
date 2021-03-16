import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_1260 {
	
	static int N,M,V;
	static ArrayList<Integer>[] info;
	static StringTokenizer st;
	static boolean visit_d[];
	static boolean visit_b[];
	static StringBuilder sb;

	
	static class Node {
		int dest;
		
		public Node(int dest) {
			this.dest=dest;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		V=Integer.parseInt(st.nextToken());
		
		sb=new StringBuilder();
		
		info = new ArrayList[N+1];
		visit_b=new boolean[N+1];
		visit_d=new boolean[N+1];
		
		 for(int i=0;i<N+1;i++) {
			info[i] = new ArrayList<>();
		}
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int dest = Integer.parseInt(st.nextToken());
			info[start].add(dest);
			info[dest].add(start);
		}
		 for(int i=0;i<N+1;i++) {
			 Collections.sort(info[i]);
		}
		dfs(V);
		sb.append("\n");
		bfs();
		System.out.println(sb.toString());
		
	}

	private static void dfs(int cur) {
		visit_d[cur]=true;
		sb.append(cur+" ");
		
		for(int i=0;i<info[cur].size();i++) {
			int next = info[cur].get(i);
			if(visit_d[next]) continue;
			dfs(next);
		}
	}
	
	private static void bfs() {
		visit_b[V]=true;
		sb.append(V+" ");
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(V);
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int i=0;i<info[cur].size();i++) {
				int next=info[cur].get(i);
				if(visit_b[next]) continue;
				visit_b[next]=true;
				sb.append(next+" ");
				q.add(next);
			}
		}
	}
	
}
