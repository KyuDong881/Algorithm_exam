import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main_18223 {

	static int V,E,P;
	static ArrayList<Info>[] list;
	static int[] dist;
	static StringTokenizer st;
	static class Info {
		Integer dest;
		Integer cost;
		
		public Info(Integer dest,Integer cost) {
			this.dest=dest;
			this.cost=cost;
		}
		public Integer first() {
			return this.dest;
		}
		public Integer second() {
			return this.cost;
		}

	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		V=Integer.parseInt(st.nextToken());
		E=Integer.parseInt(st.nextToken());
		P=Integer.parseInt(st.nextToken());
		list = new ArrayList[V+1];
		dist = new int[V+1];
		
		for(int i=0;i<=V;i++) {
			list[i] = new ArrayList<>();
		}
		
		for(int i=0;i<E;i++) {
			st = new StringTokenizer(br.readLine());
			int start,dest,cost;
			start=Integer.parseInt(st.nextToken());
			dest=Integer.parseInt(st.nextToken());
			cost=Integer.parseInt(st.nextToken());
			list[start].add(new Info(dest,cost));
			list[dest].add(new Info(start,cost));
		}
		int root1,root2;
		root1 = find(1,V);
		root2 = find(1,P)+find(P,V);
		if(root1!=root2) System.out.println("GOOD BYE");
		else System.out.println("SAVE HIM");
	}
	
	private static int find(int start, int end) {
		PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
			@Override
			public int compare(Info o1, Info o2) {
				return o1.cost-o2.cost;
			}
		});
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[start]=0;
		pq.add(new Info(start,0));
		while(!pq.isEmpty()) {
			int curnode = pq.peek().first();
			int cost = pq.peek().second();
			pq.poll();
			for(int i=0;i<list[curnode].size();i++) {
				int next = list[curnode].get(i).dest;
				int nextcost = list[curnode].get(i).cost;
				int tdist = cost+nextcost;
				if(dist[next]>tdist) {
					dist[next] = tdist;
					pq.add(new Info(next,tdist));
				}
			}
		}
		return dist[end];
	}

}
