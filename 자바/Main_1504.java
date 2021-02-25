import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;



public class Main_1504 {

	static int N,E;
	static StringTokenizer st;
	static int[] dist;
	static ArrayList<Info>[] list;
	static long answer;
	static int musts,mustd;
	
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
		N=Integer.parseInt(st.nextToken());
		E=Integer.parseInt(st.nextToken());
		list = new ArrayList[N+1];
		for(int i=0;i<=N;i++) {
			list[i] = new ArrayList<>();
		}
		dist = new int[N+1];

		
		int a,b,c;
		for(int i=0;i<E;i++) {
			st = new StringTokenizer(br.readLine());
			a=Integer.parseInt(st.nextToken());
			b=Integer.parseInt(st.nextToken());
			c=Integer.parseInt(st.nextToken());
			list[a].add(new Info(b,c));
			list[b].add(new Info(a,c));
			
		}
		st = new StringTokenizer(br.readLine());
		musts = Integer.parseInt(st.nextToken());
		mustd = Integer.parseInt(st.nextToken());
		solution();
		
	}
	
	private static void solution() {
	
		long tmp1=0;
		long tmp2=0;

		tmp1 += find(1,musts);
		tmp1 += find(musts,mustd);
		tmp1 += find(mustd,N);

		tmp2 += find(1,mustd);
		tmp2 += find(mustd,musts);
		tmp2 += find(musts,N);

		answer = Math.min(tmp1, tmp2);
		
		if(answer>=Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(answer);
	}

	private static int find(int start,int end) {
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
