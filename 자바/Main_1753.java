import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main_1753 {

	static int V,E,K;
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
		StringBuilder sb = new StringBuilder();
		st = new StringTokenizer(br.readLine());
		V=Integer.parseInt(st.nextToken());
		E=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(br.readLine());
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
		}
		dijkstra(K);
		for(int i=1;i<=V;i++) {
			if(dist[i]==200001) {
				sb.append("INF\n");
			}
			else sb.append(dist[i]+"\n");
		}
		System.out.println(sb.toString());
	}
	
	private static void dijkstra(int start) {
		PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
			@Override
			public int compare(Info o1, Info o2) {
				return o1.cost-o2.cost;
			}
		});
		
		//dist 배열 값들을 INF로 초기화
		Arrays.fill(dist, 200001);
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
	}
}
