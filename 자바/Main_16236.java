import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_16236 {

	static int[][] board;
	static int[][] visit;
	static int N;
	static int[] dy = {-1,0,1,0};
	static int[] dx = {0,-1,0,1};
	static Pair shark;
	static boolean flag;
	
	static int sharkcount;
	static int sharksize = 2;
	static int answer;
	
	static class Pair {
		int y;
		int x;
		
		public Pair(int y, int x) {
			this.y=y;
			this.x=x;
		}
	}
	
	static StringTokenizer st;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N=Integer.parseInt(br.readLine());
		board = new int[N][N];
		visit = new int[N][N];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j]==9) {
					board[i][j]=0;
					shark = new Pair(i,j);
				}
			}
		}
		
		while(true) {
			
			if(sharkcount==sharksize) {
				sharkcount=0;
				sharksize++;
			}
			
			bfs();
			if(flag==false) break;
		}
		
		System.out.println(answer);
		
	}
	private static void bfs() {
		flag=false;
		for(int i=0;i<N;i++) {
			Arrays.fill(visit[i], 0);			
		}

		visit[shark.y][shark.x] = 1;
		Queue<Pair> q = new LinkedList<>();
		q.offer(shark);
		while(!q.isEmpty()) {
			int cy = q.peek().y;
			int cx = q.peek().x;
			q.poll();
			
			if(board[cy][cx]<sharksize&&board[cy][cx]!=0) {
				sharkcount++;
				board[cy][cx]=0;
				flag=true;
				answer+=visit[cy][cx]-1;
				return;
			}
			
			for(int i=0;i<4;i++) {
				int ny = cy+dy[i];
				int nx = cx+dx[i];
				if(ny<0||nx<0||ny>=N||nx>=N) continue;
				if(visit[ny][nx]>0) continue;
				
				//상어크기가 모자란 경우
				if(board[ny][nx]>sharksize) continue;
				
				visit[ny][nx]=visit[cy][cx]+1;
				q.offer(new Pair(ny,nx));
			}
			
		}
	}
}


















