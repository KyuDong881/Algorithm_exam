import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main_17472 {

	static int N,M;
	static StringTokenizer st;
	static int[][] board,island;
	static int[] parent;
	static int[] dy = {0,0,1,-1};
	static int[] dx = {1,-1,0,0};
	static int color,answer;
	static ArrayList<Info> info;

	
	static class Info {
		Integer i1;
		Integer i2;
		Integer cost;
		
		public Info(Integer i1, Integer i2, Integer cost) {
			this.i1 = i1;
			this.i2 = i2;
			this.cost = cost;
		}
	}
	
	static class Pair {
		Integer y;
		Integer x;
		
		public Pair(Integer y,Integer x) {
			this.y=y;
			this.x=x;
		}
	}
	
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		board = new int[N][M];
		island = new int[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				board[i][j]=Integer.parseInt(st.nextToken());
			}
		}
				
		makeIsland();
		makeEdge();
		MST();
		System.out.println(answer);
	}
	
	private static void MST() {
		int count=0;
		parent = new int[color+1];
		for(int i=1;i<=color;i++) {
			parent[i]=i;
		}
		
		Collections.sort(info,new Comparator<Info>() {
			@Override
			public int compare(Info o1, Info o2) {
				return o1.cost-o2.cost;
			}
		});
		
		for(int i=0;i<info.size();i++) {
			int cost = info.get(i).cost;
			int i1 = info.get(i).i1;
			int i2 = info.get(i).i2;
			if(check_cycle(i1, i2)==false) {
				union_xy(i1,i2);
				count++;
				answer+=cost;
			}
		}
		if(count!=color-1) answer=-1;
		
	}

	private static void makeEdge() {
		
		info = new ArrayList<>();
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(island[i][j]!=0) makeDari(i,j);
			}
		}
	}

	private static void makeDari(int y, int x) {
		
		int number = island[y][x];
		for(int dir=0;dir<4;dir++) {
			int dist=0;
			int nx=x;
			int ny=y;
			while(true) {
				ny+=dy[dir];
				nx+=dx[dir];
				dist++;
				if(ny<0||nx<0||ny>=N||nx>=M) break;
				if(island[ny][nx]!=0) {
					if(island[ny][nx]==number) break;
					else {
						if(dist>2) {
							info.add(new Info(number,island[ny][nx],dist-1));
						}
						break;
					}
				}
			}
		}
	}

	private static void makeIsland() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(board[i][j]==1&&island[i][j]==0) {
					bfs(i,j);
				}
			}
		}
	}

	private static void bfs(int y,int x) {
		color++;
		Queue<Pair> q = new LinkedList<>();
		island[y][x]=color;
		q.add(new Pair(y,x));
		while(!q.isEmpty()) {
			int cy = q.peek().y;
			int cx = q.peek().x;
			q.poll();
			for(int i=0;i<4;i++) {
				int ny = cy+dy[i];
				int nx = cx+dx[i];
				if(ny<0||nx<0||ny>=N||nx>=M) continue;
				if(board[ny][nx]==0) continue;
				if(island[ny][nx]>0) continue;
				island[ny][nx]=color;
				q.add(new Pair(ny,nx));
			}
		}
	} //island 배열에 섬이 구분되어 입력 됨

	private static void union_xy(int x,int y) {
		int rootx = find_parent(x);
		int rooty = find_parent(y);
		if(rootx==rooty) return;
		else {
			parent[rooty]=rootx;
			return;
		}
	}
	
	private static boolean check_cycle(int x,int y) {
		if(find_parent(x)==find_parent(y)) return true;
		else return false;
	}
	
	private static int find_parent(int x) {
		if(parent[x]==x) return x;
		else return parent[x]=find_parent(parent[x]);
	}
	
}
