package ssafyalgo_s0412;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Solution_1249_박규동 {

	static int T,N,answer;
	static int[][] board,visit;
	static int[] dy = {0,0,1,-1};
	static int[] dx = {1,-1,0,0};
	static StringBuilder sb;
	static class Pair{
		int y;
		int x;
		int time;
		public Pair(int y,int x,int time) {
			this.x=x;
			this.y=y;
			this.time=time;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		sb=new StringBuilder();
		T=Integer.parseInt(br.readLine());
		for(int tc=1;tc<=T;tc++) {
			N=Integer.parseInt(br.readLine());
			board = new int[N][N];
			for(int i=0;i<N;i++) {
				String str = br.readLine();
				for(int j=0;j<N;j++) {
					board[i][j] = str.charAt(j)-'0';
				}
			}
			
			answer = bfs(0,0);
			sb.append("#"+tc+" "+answer+"\n");
		}
		System.out.println(sb);
	}

	private static int bfs(int sy, int sx) {
		visit = new int[N][N];
		for(int i=0;i<N;i++) {
			Arrays.fill(visit[i], Integer.MAX_VALUE);
		}
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(sy,sx,0));
		
		while(!q.isEmpty()) {
			int cy = q.peek().y;
			int cx = q.peek().x;
			int ctime = q.peek().time;
			q.poll();
			for(int i=0;i<4;i++) {
				int ny = cy+dy[i];
				int nx = cx+dx[i];
				if(ny<0||nx<0||ny>=N||nx>=N) continue;
				
				int ntime = ctime+board[ny][nx];
				
				if(visit[ny][nx]<=ntime) continue;
				visit[ny][nx]=ntime;
				q.add(new Pair(ny,nx,ntime));
			}
		}
		
		return visit[N-1][N-1];
	}
}
