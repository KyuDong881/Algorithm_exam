import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_9370 {

	static int n,m,t,s,g,h,a,b,d,x,T;
	static StringTokenizer st;
	static ArrayList<Info>[] info;
	static ArrayList<Integer> candi;
	static int[] dist;
	static StringBuilder sb;
	static int root;
	static class Info {
		int dest;
		int cost;
		
		public Info(int dest,int cost) {
			this.dest = dest;
			this.cost = cost;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb=new StringBuilder();
		T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++) {
			st = new StringTokenizer(br.readLine());
			n=Integer.parseInt(st.nextToken());
			m=Integer.parseInt(st.nextToken());
			t=Integer.parseInt(st.nextToken());
			info = new ArrayList[n+1];
			dist = new int[n+1];
			candi = new ArrayList<>();
			for(int i=1;i<=n;i++) {
				info[i] = new ArrayList<>();
			}
			st=new StringTokenizer(br.readLine());
			s=Integer.parseInt(st.nextToken());
			g=Integer.parseInt(st.nextToken());
			h=Integer.parseInt(st.nextToken());
			for(int i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				a=Integer.parseInt(st.nextToken());
				b=Integer.parseInt(st.nextToken());
				d=Integer.parseInt(st.nextToken());
				if((a==g&&b==h)||(a==h&&b==g)) root = d;
				info[a].add(new Info(b,d));
				info[b].add(new Info(a,d));
			}
			
			for(int i=0;i<t;i++) {
				x=Integer.parseInt(br.readLine());
				candi.add(x);
			}
			
			solve();
		}
		System.out.println(sb);
	}

	private static void solve() {
		//출발점 -> 목적지 후보 별로 다익스트라를 돌고 그 안에 g -> h의 경로가 포함되어 있는지 체크
		Collections.sort(candi);
		
		for(int i=0;i<t;i++) {
			x=candi.get(i);
//			int root1 = find(s,g)+root+find(h,x); //s->g->h->x
//			int root2 = find(s,h)+root+find(g,x); //s->h->g->x
			int totalroot = find(s,x); //s->x
			if(totalroot==find(s,g)+root+find(h,x)||totalroot==find(s,h)+root+find(g,x)) sb.append(x+" ");
		}

		sb.append("\n");
	}

	private static int find(int start, int end) {
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[start]=0;
		PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
			@Override
			public int compare(Info o1, Info o2) {
				return o1.cost-o2.cost;
			}
		});
		pq.offer(new Info(start,0));
		while(!pq.isEmpty()) {
			int cur = pq.peek().dest;
			int cdist = pq.peek().cost;
			if(cur==end)	return dist[end];
			pq.poll();
			for(int i=0;i<info[cur].size();i++) {
				int next = info[cur].get(i).dest;
				int ndist = info[cur].get(i).cost;
				if(dist[next]>cdist+ndist) {
					dist[next] = cdist+ndist;
					pq.add(new Info(next,cdist+ndist));
				}
			}
		}
		return dist[end];
	}
	
	

}
