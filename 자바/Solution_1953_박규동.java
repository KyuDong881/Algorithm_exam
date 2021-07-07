package ssafyalgo_s0412;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_1953_박규동 {

	static int T,answer;
	static int N,M,R,C,L;
	static StringTokenizer st;
	static int[][] board;
	static boolean[][] visit;
	static int[] dy = {-1,0,1,0};
	static int[] dx = {0,1,0,-1};
	static int[][] shape = {
			{0, 0, 0, 0},
			{1, 1, 1, 1},	
			{1, 0, 1, 0},	
			{0, 1, 0, 1},	
			{1, 1, 0, 0},	
			{0, 1, 1, 0},	
			{0, 0, 1, 1},	
			{1, 0, 0, 1},
	};
	
	static class Pair {
		int y;
		int x;
		int time;
		
		public Pair(int y, int x,int time) {
			this.y = y;
			this.x = x;
			this.time=time;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T=Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for(int tc=1;tc<=T;tc++) {
			answer=0;
			st = new StringTokenizer(br.readLine());
			N=Integer.parseInt(st.nextToken());
			M=Integer.parseInt(st.nextToken());
			R=Integer.parseInt(st.nextToken());
			C=Integer.parseInt(st.nextToken());
			L=Integer.parseInt(st.nextToken());
			
			board = new int[N][M];
			visit = new boolean[N][M];
		
			for(int i=0;i<N;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<M;j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			bfs();
			answer++;
			sb.append("#"+tc+" "+answer+"\n");
		}
		System.out.println(sb);
	}

	private static void bfs() {
		visit[R][C]=true;
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(R,C,1));
		while(!q.isEmpty()) {
			int cy = q.peek().y;
			int cx = q.peek().x;
			int ctime = q.peek().time;
			q.poll();
			if(ctime==L) return;
			int type = board[cy][cx];
			for(int i=0;i<4;i++) {
				if(shape[type][i]==0) continue;
				int ny = cy+dy[i];
				int nx = cx+dx[i];
				if(ny<0||nx<0||ny>=N||nx>=M) continue;
				if(visit[ny][nx]) continue;
				if(board[ny][nx]==0) continue;
				if(i==0) {
					if(board[ny][nx]==1||board[ny][nx]==2||board[ny][nx]==5||board[ny][nx]==6) {
						visit[ny][nx]=true;
						answer++;
						q.add(new Pair(ny,nx,ctime+1));
					}
				}else if(i==1) {
					if(board[ny][nx]==1||board[ny][nx]==3||board[ny][nx]==6||board[ny][nx]==7) {
						visit[ny][nx]=true;
						answer++;
						q.add(new Pair(ny,nx,ctime+1));
					}
				}else if(i==2) {
					if(board[ny][nx]==1||board[ny][nx]==2||board[ny][nx]==4||board[ny][nx]==7) {
						visit[ny][nx]=true;
						answer++;
						q.add(new Pair(ny,nx,ctime+1));
					}
				}else {
					if(board[ny][nx]==1||board[ny][nx]==3||board[ny][nx]==4||board[ny][nx]==5) {
						visit[ny][nx]=true;
						answer++;
						q.add(new Pair(ny,nx,ctime+1));
					}
				}
			}
		}
		
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
