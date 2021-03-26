import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_2636 {

	static int h,w;
	static int[][] board;
	static StringTokenizer st;
	static int time,count;
	static int[] dy = {0,0,1,-1};
	static int[] dx = {1,-1,0,0};
	static boolean last;
	static boolean[][] visit;
	
	static class Pair {
		int y;
		int x;
		public Pair(int y,int x) {
			this.x=x;
			this.y=y;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		h=Integer.parseInt(st.nextToken());
		w=Integer.parseInt(st.nextToken());
		board = new int[h][w];
		
		for(int i=0;i<h;i++) {
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<w;j++) {
				board[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		solve();
		System.out.println(time);
		System.out.println(count);
	}


	private static void solve() {
		
		while(true) {
			find_edge();
			melt();
			time++;
			if(last) break;
		}
		
	}


	private static void melt() {
		count=0;
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				if(visit[i][j]) {
					if(board[i][j]==1) count++;
					board[i][j]=0;
				}
			}
		}
		
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				if(board[i][j]==1) {
					return;
				}
			}
		}
		last=true;
		
	}


	private static void find_edge() {
		visit = new boolean[h][w];
		visit[0][0]=true; //가장자리는 무조건 치즈가 아니므로
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(0,0));
		while(!q.isEmpty()) {
			int cy = q.peek().y;
			int cx = q.peek().x;
			q.poll();
			if(board[cy][cx]==1) continue;
			
			for(int i=0;i<4;i++) {
				int ny = cy+dy[i];
				int nx = cx+dx[i];
				if(ny<0||nx<0||ny>=h||nx>=w) continue;
				if(visit[ny][nx]) continue;
				visit[ny][nx]=true;
				q.add(new Pair(ny,nx));
			}
		}
		
	}

}
