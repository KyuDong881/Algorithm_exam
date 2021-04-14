import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_5656 {

	static int T, N, W, H, answer;
	static StringTokenizer st;
	static int[][] board, copy;
	static int[] marvels;
	static int[] dy = { 0, 0, 1, -1 };
	static int[] dx = { 1, -1, 0, 0 };

	static class Pair {
		int y;
		int x;
		int power;

		public Pair(int y, int x, int power) {
			this.y = y;
			this.x = x;
			this.power = power;
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int tc = 1; tc <= T; tc++) {
			answer = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			board = new int[H][W];
			marvels = new int[N];
			for (int i = 0; i < H; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < W; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			perm(0);
			sb.append("#" + tc + " " + answer + "\n");
		}
		System.out.println(sb);
	}

	private static void perm(int cnt) {
		if (cnt == N) {
			// board 복제
			copy = new int[H][W];
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					copy[j] = Arrays.copyOf(board[j], W);
				}
			}
			play();
			return;
		}

		for (int i = 0; i < W; i++) {
			marvels[cnt] = i;
			perm(cnt + 1);
		}

	}

	private static void play() {

		for (int i = 0; i < N; i++) {
			int marvel = marvels[i];
			int height = 0;
			boolean flag=true;
			// 첫 블록 찾기
			while (true) {
				if(height==H) {
					flag=false;
					break;
				}
				if(copy[height][marvel]>0) break;
				height++;
			}
			if(!flag) continue;
			int power = copy[height][marvel];
			crash(height, marvel, power);
			moveBlock();
		}
		count();

	}

	private static void moveBlock() {
		for (int i = 0; i < W; i++) {
			for (int j = H - 1; j > -1; j--) {
				if (copy[j][i] != 0)
					continue;
				int idx = j;
				while (true) {
					idx--;
					if (idx < 0)
						break;
					if (copy[idx][i] != 0) {
						copy[j][i] = copy[idx][i];
						copy[idx][i] = 0;
						break;
					}
				}
			}
		}
	}

	private static void crash(int height, int marvel, int power) {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(height, marvel, power));
		while (!q.isEmpty()) {
			int cy = q.peek().y;
			int cx = q.peek().x;
			int cpower = q.peek().power;
			
			q.poll();
			copy[cy][cx] = 0;
			for (int i = 1; i < cpower; i++) {
				for (int dir = 0; dir < 4; dir++) {
					int ny = cy + dy[dir] * i;
					int nx = cx + dx[dir] * i;
					if (ny < 0 || nx < 0 || ny >= H || nx >= W)
						continue;
					if (copy[ny][nx] > 1) {
						q.add(new Pair(ny, nx, copy[ny][nx]));
					}
					copy[ny][nx] = 0;
				}
			}
		}

	}

	// 벽돌개수 세는 거
	private static void count() {
		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (copy[i][j] != 0)
					cnt++;
			}
		}
		if (answer > cnt)
			answer = cnt;
	}

}
