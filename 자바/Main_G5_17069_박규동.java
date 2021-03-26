import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_G5_17069_박규동 {

	static int[][] board;
	static int N;
	static long answer;
	static StringTokenizer st;
	static long[][][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		board = new int[N + 1][N + 1];
		dp = new long[N + 1][N + 1][3];

		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < N + 1; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		answer = dp();

		System.out.println(answer);
	}

	private static long dp() {
		
		for(int i=2;i<=N;i++) {
			if(board[1][i]==1) break;
			dp[1][i][0]=1;
		}	//1행 2열부터 시작 1행에는 가로만 올 수 있음

		for (int i = 2; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == 1)
					continue;	//벽이면 값갱신 x

				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];

				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

				if (board[i - 1][j] != 1 && board[i][j - 1] != 1) {
					dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}
				//가로,세로,대각으로부터 올 수 있는 값을 메모
			}
		}

		return dp[N][N][0] + dp[N][N][1] + dp[N][N][2]; //(N,N)에 올 수 있는 경우를 더해서 리턴
	}

}
