import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_G5_17070_박규동 {

	static int[][] board;
	static int N, answer;
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		board = new int[33][33];
		for (int i = 1; i < N+1; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < N+1; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		dfs(1, 2, 0);
		System.out.println(answer);
	}

	private static void dfs(int cy, int cx, int state) {
		if (cx == N && cy == N) {
			answer++;
			return;
		}

		if (state == 0) {
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					int ny = cy + 0;
					int nx = cx + 1;
					if (nx > N)
						continue;
					if (board[ny][nx] == 1)
						continue;
					int nstate = 0;
					dfs(ny, nx, nstate);
				} else {
					int ny = cy + 1;
					int nx = cx + 1;
					if (ny > N || nx > N)
						continue;
					if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1 || board[ny][nx] == 1)
						continue;
					int nstate = 2;
					dfs(ny, nx, nstate);
				}
			}
		}

		if (state == 1) {
			for (int i = 0; i < 2; i++) {
				if (i == 0) {
					int ny = cy + 1;
					int nx = cx + 0;
					if (ny > N)
						continue;
					if (board[ny][nx] == 1)
						continue;
					int nstate = 1;
					dfs(ny, nx, nstate);
				} else {
					int ny = cy + 1;
					int nx = cx + 1;
					if (ny > N || nx > N)
						continue;
					if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1 || board[ny][nx] == 1)
						continue;
					int nstate = 2;
					dfs(ny, nx, nstate);
				}
			}
		}
		if (state == 2) {
			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					int ny = cy + 0;
					int nx = cx + 1;
					if (nx > N)
						continue;
					if (board[ny][nx] == 1)
						continue;
					int nstate = 0;
					dfs(ny, nx, nstate);
				} else if (i == 1) {
					int ny = cy + 1;
					int nx = cx + 0;
					if (ny > N)
						continue;
					if (board[ny][nx] == 1 || ny > N)
						continue;
					int nstate = 1;
					dfs(ny, nx, nstate);
				} else {
					int ny = cy + 1;
					int nx = cx + 1;
					if (ny > N || nx > N)
						continue;
					if (board[ny - 1][nx] == 1 || board[ny][nx - 1] == 1 || board[ny][nx] == 1)
						continue;
					int nstate = 2;
					dfs(ny, nx, nstate);
				}
			}
		}

	}

}
